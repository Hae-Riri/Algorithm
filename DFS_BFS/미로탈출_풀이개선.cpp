#include <iostream>
#include <queue>
using namespace std;

int map[400][400];
int n, m;

int dx[4] = { -1, +1, 0, 0 };
int dy[4] = { 0, 0, -1, +1 };

int bfs(int x, int y) {
	queue<pair<int, int>>q;
	q.push({ x,y });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny =y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (map[nx][ny] == 0) continue;
			if (map[nx][ny] == 1) {
				map[nx][ny] = map[x][y]+1;
				q.push({ nx, ny });
			}
		}
	}
	return map[n- 1][m - 1];
}

int main() {

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf_s("%1d", &map[i][j]);
		}
	}

	cout << bfs(0, 0);
	return 0;
}