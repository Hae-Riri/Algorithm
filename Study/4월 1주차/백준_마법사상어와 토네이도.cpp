#include <iostream>
#include <vector>
using namespace std;

int n;
int map[499][499];

//좌하우상
int dx[4] = { 0,+1,0,-1 };
int dy[4] = { -1, 0, +1, 0 };
int ratio[9] = { 1,1,2,7,7,2,10,10,5 };
//y를 기준으로 & 마지막은 알파
const int blow_x[4][10] = {
	{-1,1,-2,-1,1,2,-1,1,0,0},
	{-1,-1,0,0,0,0,1,1,2,1},
	{-1,1,-2,-1,1,2,-1,1,0,0},
	{1,1,0,0,0,0,-1,-1,-2,-1}
};
const int blow_y[4][10] = {
	{1,1,0,0,0,0,-1,-1,-2,-1},
	{-1,1,-2,-1,1,2,-1,1,0,0},
	{-1,-1,0,0,0,0,1,1,2,1},
	{-1,1,-2,-1,1,2,-1,1,0,0}
};


bool inRange(int x, int y) {
	return x >= 0 && x < n&& y >= 0 && y < n;
}

//격자 밖 모래 반환
int blowSand(int x, int y, int dir) {
	int ret = 0;
	int init = map[x][y];
	for (int i = 0; i < 10; i++) {
		int sand;
		if (i != 9) {//알파가 아니라면
			sand = init * ratio[i] / 100;
			map[x][y] -= sand;
		}
		else sand = map[x][y]; //남은 모래 저장

		int bx = x + blow_x[dir % 4][i];
		int by = y + blow_y[dir % 4][i];

		if (!inRange(bx, by)) {
			ret += sand;
			continue;
		}
		map[bx][by] += sand;
	}
	map[x][y] = 0;
	return ret;
}

int solve() {
	//맨 처음 날아갈 모래가 있는 자리를 기준으로
	int x = n / 2;
	int y = n / 2;
	int dir = 0;
	int ret = 0;
	
	//1칸부터 n-1까지 두번씩 이동
	//for (double i = 1.0; i <= n; i += 0.5) {
	//	for (int j = 0; j < (int)i; j++) {
	//		x += dx[dir % 4];
	//		y += dy[dir % 4];
	//		ret += blowSand(x, y, dir);
	//	}
	//	dir++;
	//}
	int moveCnt = 1;
	while (1) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < moveCnt; j++) {
				//이동을 한 곳에 있는 모래를 이동시킬거야
				x += dx[dir % 4];
				y += dy[dir % 4];
				ret += blowSand(x, y, dir);
			}
			dir++;
		}
		moveCnt++;
		if (moveCnt == n-1) {
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < moveCnt; j++) {
					x += dx[dir % 4];
					y += dy[dir % 4];
					ret += blowSand(x, y, dir);
				}
				dir++;
			}
			break;
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	cout << solve();
	return 0;
}