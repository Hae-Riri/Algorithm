#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//한 간선의 길이가 10만이고 최대 경로는 이게 n개인
//n개 노드거치는 거니까 최소 1억개는 되어야 함
int inf = 987654321;

int d[1001]; //1부터 n까지
int n,m;
vector<pair<int, int>>v[1001]; //노드, 거리 n개 초기화

void dijkstra(int start) {
	d[start] = 0;
	priority_queue<pair<int, int>>pq;
	pq.push({ start, 0 });
	while (!pq.empty()) {
		int current = pq.top().first;
		int distance = -pq.top().second;
		pq.pop();
		if (distance > d[current]) continue;
		for (int i = 0; i < v[current].size(); i++) {
			int next = v[current][i].first;
			int nextDistance = distance + v[current][i].second;
			if (nextDistance < d[next]) {
				d[next] = nextDistance;
				pq.push({ next, -nextDistance });
			}
		}
	}
}

int main() {
	scanf("%d\n%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int start, end , distance;
		cin >> start >> end >> distance;

		v[start].push_back({end, distance});
	}
	int start, end;
	cin >> start;
	cin >> end;
	for (int i = 1; i <= n;i++) {
		d[i] = inf;
	}
	dijkstra(start);
	for (int i = 1; i <= n; i++) {
		cout << d[i] << " " << endl;
	}
	cout << d[end] << endl;
	return 0;
}