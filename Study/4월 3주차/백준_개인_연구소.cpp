#include <iostream>
#include <queue>
using namespace std;

int n, m;
int ret;
int map[8][8];
struct Pt {
	int x, y;
};
Pt blank[64];
int blank_size;
const int dx[] = { -1, 1, 0 ,0 };
const int dy[] = { 0, 0, -1, 1 };
void print(int map[8][8]) {
	cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}
void init() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) {
				blank[blank_size] = { i, j };
				blank_size++;
			}
		}
	}
}
bool inRange(int x, int y) {
	return x >= 0 && x < n&& y >= 0 && y < m;
}
int getSafety(int map[8][8]) {
	queue<Pt> q;
	bool visit[8][8] = { 0, };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 2) {
				q.push({ i, j });
				visit[i][j] = true;
			}
		}
	}
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (inRange(nx, ny) && !visit[nx][ny] && map[nx][ny] != 1) {
				q.push({ nx, ny });
				map[nx][ny] = 2;
				visit[nx][ny] = true;
			}
		}
	}
	//cout << "bfs 내에서" << endl;
	//print(map);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) cnt++;
		}
	}
	return cnt;
}
void copy(int backup[8][8], int src[8][8]) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			backup[i][j] = src[i][j];
}
void dfs(int idx, int cnt, int map[8][8]) {
	if (cnt == 3) { //벽을 다 세웠으면 바이러스 퍼뜨려서 안전지대 체크
		//print(map);
		int safety = getSafety(map);
		if (ret < safety) ret = safety;
		return;
	}
	int backup[8][8] = { 0 };
	for (int i = idx; i < blank_size; i++) {
		copy(backup, map);
		/*		cout << "backup" << endl;
				print(backup)*/;
				Pt pt = blank[i];
				map[pt.x][pt.y] = 1;
				dfs(i + 1, cnt + 1, map);
				copy(map, backup);
				//cout << "map" << endl;
				//print(map);
	}
}
int main() {
	init();
	dfs(0, 0, map);
		cout << ret;
	return 0;
}