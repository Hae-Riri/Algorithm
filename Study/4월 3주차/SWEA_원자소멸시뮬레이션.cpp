#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int dx[] = { 0, 0, -1, 1 };
const int dy[] = { 1, -1, 0,0 };
int map[4001][4001];
int t, n, energy;
struct ATOM {
	int x, y, d, k;
	bool live;
};
vector<ATOM> atom;
void init() {
	n = 0;
	energy = 0;
	memset(map, 0, sizeof(map));
	atom.clear(); 
	//atom.resize(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y, d, k;
		cin >> x >> y >> d >> k;
		x = (x + 1000) * 2; y = (y + 1000) * 2;
		map[x][y] = 1;
		atom.push_back({ x, y, d, k, true });
	}
}
bool inRange(int x, int y) {
	return x >= 0 && x <= 4000 && y >= 0 && y <= 4000;
}
void move() { //��ĭ�� �̵��ϴ� �Լ�
	//�̹� ���� ���ڴ� �̵�������!
	//���ڰ� �̵��ϸ�
	//���ڸ��� ���ڼ��� �ٰ�map[][]-- !!
	//�̵��� �ڸ��� ���ڼ��� �þ�� map[][]++ !!
	//�̵��� ������ ��ǥ�� �ٲ�� !!
	//���ڹ����� ����� �������ڷ� ó�� !!
	for (int i = 0; i < atom.size(); i++) {
		if (!atom[i].live) continue;
		int x = atom[i].x;
		int y = atom[i].y;
		int d = atom[i].d;
		int nx = x + dx[d];
		int ny = y + dy[d];
		map[x][y] = 0;
		if (!inRange(nx, ny)) { //���� ������ ���� ���� ����
			atom[i].live = false;
		}
		else {
			//�̵�
			map[nx][ny]++;
			atom[i].x = nx;
			atom[i].y = ny;
		}
	}
}
void getEnergy() {
	//���ڸ� ���鼭 �̹� ���� ���ڴ� �н� !!
	//���ڸ� ���鼭 ���ڸ��� 2 �̻��̸� �� ���ڸ� live = false�� �ϰ� k�� ���ϰ� !!
	// ���� for������ ���ڸ� ���鼭 �� ��ġ�� ������ ��ġ�� ���ڰ� �ִٸ�
	//�� k�� ���Ѵ��� �� ���ڸ� ���� ���ڷ� ó��.
	for (int i = 0; i < atom.size(); i++) {
		if (!atom[i].live) continue;
		int x = atom[i].x;
		int y = atom[i].y;
		if (map[x][y] >= 2) { //�浹�� ����
			for (int j = 0; j < atom.size(); j++) {
				if (atom[j].x == x && atom[j].y == y) {
					atom[j].live = false;
					energy += atom[j].k;
				}
			}
		}
		//�ش���ġ�� ��� ó�������� 
		map[x][y] = 0;
	}
}
bool allDead() {
	for (int i = 0; i < atom.size(); i++) {
		if (atom[i].live) return false;
	}
	return true;
}
int main() {
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		init();
		while (true) {
			if (atom.size() == 0 || atom.size() == -1) break;
			move();
			getEnergy();
			if (allDead()) {
				break;
			}
		}
		cout << "#" << tc << " " << energy << "\n";
	}
	return 0;
}