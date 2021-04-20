#include <iostream>
#include <vector>
using namespace std;

int R, C, M, king_col, ret; //���ÿ��� ����ȣ 0���� �ʱ�ȭ
vector<int> map[101][101]; //��ǥ�� 1~100�̴ϱ�
struct SHARK {
	int r, c, s, d, z; //��ǥ, �ӷ�, ����, ũ��
};
vector<SHARK> shark; //�����������
const int dx[] = {0, -1, 1, 0, 0}; //���Ͽ���
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

	//2. ������ (�̶��� �� ĭ�� ��� 1���ۿ� ����)
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

	//3. ��� �̵�
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
		// ������ �ڸ��� �� �����Ѵٸ� ���ؼ� �Ѹ� �ְ� �Ѹ��� ������ �ɷ� ó��
		if (map[shark[i].r][shark[i].c].size() > 0) { 
			//���� �� ū�Ÿ� ������ �ִ� �ָ� ����
			if (shark[i].z > shark[map[shark[i].r][shark[i].c][0]].z) {
				int eaten = map[shark[i].r][shark[i].c][0];
				shark[eaten].d = 0;
				map[shark[i].r][shark[i].c].pop_back();
				map[shark[i].r][shark[i].c].push_back(i);
			}
			else { //���� �� �۴ٸ� �� ����, �� ���� ������ map�� �״�� �ΰ�.
				shark[i].d = 0;
			}
		}
		else { //������ �ڸ��� �ƹ��� ���ٸ� �׳� ��
			map[shark[i].r][shark[i].c].push_back(i);
		}
	}
}
int main() {
	init();
	king_col = 1; //1. ���ÿ� �̵�
	while (king_col <= C) {
		simulation();
		king_col++; //1. ���ÿ� �̵�
	}
	cout << ret<< "\n";
	return 0;
}