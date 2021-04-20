#include <iostream>
#include <vector>
using namespace std;

int R, C, M, king_col, ret; //낚시왕의 열번호 0으로 초기화
vector<int> map[101][101]; //좌표가 1~100이니까
struct SHARK {
	int r, c, s, d, z; //좌표, 속력, 방향, 크기
};
vector<SHARK> shark; //상어정보저장
const int dx[] = {0, -1, 1, 0, 0}; //상하우좌
const int dy[] = { 0, 0, 0, 1, -1 };
bool inRange(int x, int y) {
	return x >= 1 && x <= R && y >= 1 && y <= C;
}
void mapInit() {
	for (int i = 0; i <= R; i++) {
		for (int j = 0; j <= C; j++) {
			map[i][j].clear(); map[i][j].resize(0);
		}
	}
}
int changeDir(int d) {
	if (d == 1) return 2;
	else if (d == 2) return 1;
	else if (d == 3) return 4;
	else if (d == 4) return 3;
}
void init() {
	cin >> R >> C >> M;
	for (int i = 0; i < M; ++i) {
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		shark.push_back({r,c,s,d,z});
		map[r][c].push_back(i);
	}
}
void simulation() {

	//2. 상어잡기 (이때는 한 칸에 상어 1개밖에 없어)
	for (int i = 1; i <= R; i++) {
		if (map[i][king_col].size() == 1) {
			int eaten_idx = map[i][king_col][0];
			map[i][king_col].pop_back();
			shark[eaten_idx].d = 0;
			ret += shark[eaten_idx].z;
			break;
		}
	}
	mapInit();

	//3. 상어 이동
	for (int i = 0; i < shark.size(); i++) {
		if (shark[i].d == 0) continue;
		int s = shark[i].s;
		if (shark[i].d == 1 || shark[i].d == 2) {
			s %= (R - 1) * 2;
		}
		else {
			s %= (C - 1) * 2;
		}
		while (s > 0) {
			if (!inRange(shark[i].r + dx[shark[i].d], shark[i].c + dy[shark[i].d])) {
				shark[i].d = changeDir(shark[i].d);
			}
			shark[i].r += dx[shark[i].d];
			shark[i].c += dy[shark[i].d];
			s--;
		}
		// 들어가려는 자리에 상어가 존재한다면 비교해서 한명만 넣고 한명은 먹히는 걸로 처리
		if (map[shark[i].r][shark[i].c].size() > 0) { 
			//내가 더 큰거면 기존에 있던 애를 먹자
			if (shark[i].z > shark[map[shark[i].r][shark[i].c][0]].z) {
				int eaten = map[shark[i].r][shark[i].c][0];
				shark[eaten].d = 0;
				map[shark[i].r][shark[i].c].pop_back();
				map[shark[i].r][shark[i].c].push_back(i);
			}
			else { //내가 더 작다면 난 먹혀, 들어간 적은 없으니 map은 그대로 두고.
				shark[i].d = 0;
			}
		}
		else { //들어가려는 자리에 아무도 없다면 그냥 들어가
			map[shark[i].r][shark[i].c].push_back(i);
		}
	}
}
int main() {
	init();
	king_col = 1; //1. 낚시왕 이동
	while (king_col <= C) {
		simulation();
		king_col++; //1. 낚시왕 이동
	}
	cout << ret<< "\n";
	return 0;
}