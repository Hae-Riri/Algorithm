#include <iostream>
using namespace std;
int n, m; //행.열
int x, y, d;
int map[50][50];
const int dx[] = {-1, 0, 1, 0}; //상우하좌
const int dy[] = {0, 1, 0, -1 }; //왼쪽으로 돌려면 뒤로 가야해
int ret;

void init() {
	cin >> n >> m;
	cin >> x >> y >> d;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
}
int main() {
	init();
	while (true) {
		if (map[x][y] == 0) {
			map[x][y] = 2;
			ret++;
		}
		bool moved = false;	
		for (int i = 0; i < 4; i++) {
			d--;
			if (d < 0) d = 3;
			int nx = x + dx[d];
			int ny = y + dy[d];
			if (map[nx][ny] == 0) {
				x = nx;
				y = ny;
				moved = true;
				break;
			}
		}
		if (moved) continue;//그자리에서 다시 시작해야하니까

		//후진(여기까지 내려온 건 4방향 모두 못간거니까)
		//새로운 방향변수 nd 선언이 중요!!!! 청소기 방향 자체가 변한게 아니잖아
		//잠깐 후진을 할 뿐이지 청소기 방향은 유지해야 하니까 새변수로 해야돼
		int nd = (d + 2) % 4;
		x += dx[nd];
		y += dy[nd];
		if (map[x][y] == 1) break;
	}
	cout << ret;
	return 0;
}