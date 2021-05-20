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
		int node_cnt = 0; //�θ�� �ڽ��̵� ����� ���
		for (int i = 0; i < tree[node].size(); i++) {
			int next = tree[node][i];
			if (!visit[next]) {
				node_cnt++;
				visit[next] = true;
				q.push(next);
			}
		}
		//�ڽ����� ������ ��� �ܿ��� ��� �� ���� ��������� ��
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
	//��Ʈ�������� �� Ȯ���ؼ� ������ ������ ���� ���ؼ���
	//����������� üũ�ؼ� ans ���ϱ�
	if (target != root) bfs(root);
	cout << ans;
	return 0;
}