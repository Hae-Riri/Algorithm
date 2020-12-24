#include <iostream>
#include <queue>
using namespace std;

int map[400][400];
int n, m;

int dx[4] = { -1, +1, 0, 0 };
int dy[4] = { 0, 0, -1, +1 };

struct dot {
	int x;
	int y;
	int move;
};

int main() {

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf_s("%1d", &map[i][j]);
		}
	}

	queue<dot>q;
	q.push({0,0,1});
	int ans = n*m;
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int move = q.front().move;
		map[x][y] = 0; //한번 방문했으니 다시 못들리게 0으로 변경
		q.pop();
		if (x == n - 1 && y == m - 1) {
			ans = min(ans, move);
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx > -1 && nx < n && ny >-1 && ny < m && map[nx][ny] == 1) { //1이어야 갈 수 있음
				q.push({nx, ny, move+1});
			}
		}
	}
	cout << ans;
	return 0;
}