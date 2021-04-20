#include <iostream>
#include <cstring>
#include <vector>
#include <deque>
using namespace std;

int R, C, T;
int map[51][51];
int tmp[51][51];
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };
vector<pair<int, int> > cleaner;
void print() {
	cout << "\n---map정보---\n";
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
}
void init() {
	cin >> R >> C >> T;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1) {
				cleaner.push_back(make_pair(i, j));
			}
		}
	}
}
bool canGo(int x, int y) { //경계안이고 공기청정기가 아닌지 확인
	return x >= 1 && x <= R && y >= 1 && y <= C && map[x][y] != -1;
}
void blow() {
	memset(tmp, 0, sizeof(tmp)); //퍼져서 들어온 값은 tmp에 저장
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (map[i][j] != 0) {
				int blow_cnt = 0;
				int blow_quantity = map[i][j] / 5;

				for (int d = 0; d < 4; d++) {
					int nx = i + dx[d];
					int ny = j + dy[d];
					if (canGo(nx, ny)) {
						blow_cnt++;
						tmp[nx][ny] += blow_quantity;
					}
				}

				map[i][j] -= blow_cnt * blow_quantity;
			}
		}
	}
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (map[i][j] > 0) {
				tmp[i][j] += map[i][j];
			}
		}
	}
	//map을 tmp로 업데이트
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			map[i][j] = tmp[i][j];
		}
	}
	for (int i = 0; i < 2; i++) {
		map[cleaner[i].first][cleaner[i].second] = -1;
	}
}
void rotate() {
	int cx = cleaner[0].first, cy = cleaner[0].second;
	int tmp = map[cx][2], pre = map[cx][2];
	map[cx][2] = 0;
	//왼 -> 오
	for (int col = 3; col <= C; col++) {
		tmp = map[cx][col]; //업데이트 되기 전의 값을 저장
		map[cx][col] = pre; //앞의 값으로 현위치를 업데이트
		pre = tmp; //앞의 값을 업데이트
	}
	//아래 -> 위
	for (int row = cx - 1; row >= 1; row--) {
		tmp = map[row][C];
		map[row][C] = pre;
		pre = tmp;
	}
	//오 -> 왼
	for (int col = C - 1; col >= 1; col--) {
		tmp = map[1][col];
		map[1][col] = pre;
		pre = tmp;
	}
	//위 -> 아래
	for (int row = 2; row < cx; row++) {
		tmp = map[row][1];
		map[row][1] = pre;
		pre = tmp;
	}

	//아래쪽 회전
	cx = cleaner[1].first; cy = cleaner[1].second;
	tmp = map[cx][2], pre = map[cx][2]; 
	map[cx][2] = 0;
	//왼 -> 오
	for (int col = 3; col <= C; col++) {
		tmp = map[cx][col]; //업데이트 되기 전의 값을 저장
		map[cx][col] = pre; //앞의 값으로 현위치를 업데이트
		pre = tmp; //앞의 값을 업데이트
	}
	//위 -> 아래
	for (int row = cx+1; row <= R; row++) {
		tmp = map[row][C];
		map[row][C] = pre;
		pre = tmp;
	}
	//오 -> 왼
	for (int col = C - 1; col >= 1; col--) {
		tmp = map[R][col];
		map[R][col] = pre;
		pre = tmp;
	}
	//아래 -> 위
	for (int row = R-1; row > cx; row--) {
		tmp = map[row][1];
		map[row][1] = pre;
		pre = tmp;
	}
}
int main() {
	init();
	int time = 0;
	while (time < T) {
		blow();
		//print();
		rotate();
		//print();
		time++;
	}
	int ret = 0;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if(map[i][j] > 0) ret+= map[i][j];
		}
	}
	cout << ret;
	return 0;
}