#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, target, ans, root;
vector<int> tree[50];
bool visit[50];
void bfs(int start) {
	visit[start] = true;
	queue<int> q;
	q.push(start);

	while (!q.empty()) {
		int node = q.front();
		q.pop();
		int node_cnt = 0; //부모든 자식이든 연결된 노드
		for (int i = 0; i < tree[node].size(); i++) {
			int next = tree[node][i];
			if (!visit[next]) {
				node_cnt++;
				visit[next] = true;
				q.push(next);
			}
		}
		//자신으로 접근한 노드 외에는 노드 가 없는 리프노드일 때
		if (node_cnt == 0) {
			ans++;
		}
	}
}
void init() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (x == -1) root = i;
		else {
			tree[i].push_back(x);
			tree[x].push_back(i);
		}
	}
	cin >> target;
	visit[target] = true;
}
int main() {
	init();
	//루트에서부터 쭉 확인해서 접근이 가능한 곳에 대해서만
	//리프노드인지 체크해서 ans 구하기
	if (target != root) bfs(root);
	cout << ans;
	return 0;
}