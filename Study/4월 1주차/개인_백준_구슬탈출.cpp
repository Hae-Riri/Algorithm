#include <iostream>
using namespace std;

char map[10][10];
pair<int, int> r, b, o;
struct location {
	int rx, ry, bx, by;
};
const int INF = 987654321;
int dx[4] = { -1, +1, 0, 0 };
int dy[4] = { 0, 0, -1, +1 };

int solve(int cnt, location l, int dir) {
	
	int res = INF;
	if (cnt > 10) return res;

	int rx = l.rx; int ry = l.ry;
	int bx = l.bx; int by = l.by;

	if (dir != -1) {
		while (map[bx + dx[dir]][by + dy[dir]] == '.') {
			bx += dx[dir];
			by += dy[dir];
			if (bx == o.first && by == o.second) {
				return res;
			}
		}
		while (map[rx + dx[dir]][ry + dy[dir]] == '.') {
			rx += dx[dir];
			ry += dy[dir];
			if (rx == o.first && ry == o.second) {
				res = cnt;
				return cnt;
			}
		}
		//겹칠 경우 기존 위치에 따라 처리
		if (rx == bx && ry == by) {
			if (dir == 0) {//상
				if (l.rx < l.bx) bx++;
				else rx++;
			}
			else if (dir == 1) {
				if (l.rx < l.bx) rx--;
				else bx--;
			}
			else if (dir == 2) {
				if (l.ry < l.by) by++;
				else ry++;
			}
			else if (dir == 3) {
				if (l.ry < l.by) ry--;
				else by--;
			}
		}
	}
	
	for (int i = 0; i < 4; i++) {
		res = min(res, solve(cnt + 1, { rx, ry, bx, by }, i));
	}
	return res;
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'O') {
				o.first = i; o.second = j;
				map[i][j] = '.';
			}
			else if (map[i][j] == 'R') {
				r.first = i; r.second = j;
				map[i][j] = '.';
			}
			else if (map[i][j] == 'B') {
				b.first = i; b.second = j;
				map[i][j] = '.';
			}
		}
	}
	location start = { r.first, r.second, b.first, b.second };
	int res = solve(0, start, -1);
	cout << (res == INF ? -1 : res);
}