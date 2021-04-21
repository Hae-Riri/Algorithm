#include <iostream>
using namespace std;
int map[8][8];
int n, m; //�࿭
int cctv_size;
const int rot_size[] = { 0, 4, 2, 4, 4, 1 };
struct CCTV {
	int x, y, type;
};
CCTV cctv[8];
int ret = 100; //64�̻��� ��� �� ����
void cp(int backup[8][8], int src[8][8]) { //�迭�� ���� �� �̸��� ���۷������� ����Ű�� �����Ͷ� &���̵� ����� ������
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			backup[i][j] = src[i][j];
}
void update(int dir, CCTV cctv) {
	dir %= 4;
	if (dir == 0) { //���̵�-���� �̵�
		for (int i = cctv.x; i >= 0; i--) {
			if (map[i][cctv.y] == 6) break;
			map[i][cctv.y] = -1;
		}
	}
	else if (dir == 2) {//��-���� �Ʒ���
		for (int i = cctv.x; i < n; i++) {
			if (map[i][cctv.y] == 6) break;
			map[i][cctv.y] = -1;
		}
	}
	else if (dir == 3) { //��
		for (int j = cctv.y; j >= 0; j--) {
			if (map[cctv.x][j] == 6) break;
			map[cctv.x][j] = -1;
		}
	}
	else if (dir == 1) {//��
		for (int j = cctv.y; j < m; j++) {
			if (map[cctv.x][j] == 6) break;
			map[cctv.x][j] = -1;
		}
	}
}
void dfs(int cnt) {
	if (cnt == cctv_size) {
		int candi = 0;
		//�簢���븦 count
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 0) candi++;
			}
		}
		if (ret > candi) ret = candi;
		return;
	}
	int backup[8][8];
	int type = cctv[cnt].type;
	for (int dir = 0; dir < rot_size[type]; dir++) {
		cp(backup, map);
		if (type == 1) {
			update(dir, cctv[cnt]); //��� ��ġ�� �ִ� � cctv���� �˾ƾ� �ϴϱ�
			//print();
		}
		else if (type == 2) {
			update(dir, cctv[cnt]);
			update(dir + 2, cctv[cnt]);
			//print();
		}
		else if (type == 3) {
			update(dir, cctv[cnt]);
			update(dir + 1, cctv[cnt]);
			//print();
		}
		else if (type == 4) {
			update(dir, cctv[cnt]);
			update(dir + 1, cctv[cnt]);
			update(dir + 2, cctv[cnt]);
			//print();
		}
		else if (type == 5) {
			update(dir, cctv[cnt]);
			update(dir + 1, cctv[cnt]);
			update(dir + 2, cctv[cnt]);
			update(dir + 3, cctv[cnt]);
		}
		dfs(cnt + 1);
		cp(map, backup);
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] > 0 && map[i][j] < 6) {
				cctv[cctv_size] = { i, j, map[i][j] };
				cctv_size++;
			}
		}
	}

	dfs(0);
	cout << ret;
	return 0;
}