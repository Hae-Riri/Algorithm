#include <iostream>
#include <vector>
using namespace std;

struct fish {
	int x, y, d, n;
	fish(int x, int y, int d, int n) : x(x), y(y), d(d), n(n) {};
};

const int dy[] = { 1,-1,0,1,1,1,0,-1 };
const int dx[] = { 0,-1,-1,-1,0,1,1,1 };

bool isRange(int x, int y) {
	return y >= 0 && x >= 0 && x < 4 && y < 4;
}

int solve(int x, int y, vector<vector<int>>field, vector<fish>fishes) {
	//x, y는 상어위치
	int ret, d;
	fish& eaten = fishes[field[x][y]];
	d = eaten.d;//방향 저장
	ret = eaten.n;

	//먹힌 물고기자리 -> 빈칸 변경(-1)로
	eaten.d = -1;
	field[x][y] = -1;

	//모든 물고기 이동
	for (fish& f : fishes) {
		if (f.d == -1) continue; //이미 먹힌 물고기는 패스

		bool fail = false;
		int nx, ny, fd = f.d;
		while (true) {
			nx = x + dx[f.d];
			ny = y + dy[f.d];

			//이동 가능하다면(경계 안이면서 상어도 아닌상태)
			if (isRange(nx, ny) && (ny != y ||  nx != x)) break;

			if (++f.d > 7) f.d = 0;

			if (f.d == fd) {//이동할 곳이 없어 처음으로 돌아왔다면
				fail = true;
				break;
			}
		}

		if (fail) continue;

		if (field[nx][ny] != -1) {//이동 가능한데 그게 빈칸이 아닌 다른 물고기라면
			//위치변경
			fishes[field[nx][ny]].x = f.x;
			fishes[field[nx][ny]], y = f.y;
		}
		field[f.x][f, y] = field[nx][ny];
		field[nx][ny] = f.n - 1;
		f.x = nx;
		f.y = ny;
	}

	//물고기들 이동을 마쳤으면 상어이동 & 백트래킹
	int nx = x; int ny = y; //기존상어위치 저장
	while (true) {
		nx += dx[d];//먹힌 물고기의 방향
		ny += dy[d];

		if (!isRange(nx, ny)) break;
		if (field[nx][ny] == -1) continue; //빈칸이면 넘어가

		ret = max(ret, eaten.n + solve(nx, ny, field, fishes));
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<fish> fishes(16, fish(0, 0, 0, 0));
	vector<vector<int>> field(4, vector<int>(4));

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int n, d; cin >> n >> d;
			fishes[n - 1].x = i;
			fishes[n - 1].y = j;
			fishes[n - 1].d = d - 1;
			fishes[n - 1].n = n;
			field[i][j] = n - 1;
		}
	}

	cout << solve(0, 0, field, fishes);
}