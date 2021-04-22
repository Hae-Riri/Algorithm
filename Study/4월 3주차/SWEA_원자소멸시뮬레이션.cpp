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
void move() { //한칸씩 이동하는 함수
	//이미 죽은 원자는 이동하지마!
	//원자가 이동하면
	//그자리의 원자수가 줄고map[][]-- !!
	//이동한 자리의 원자수가 늘어나고 map[][]++ !!
	//이동한 원자의 좌표가 바뀌고 !!
	//격자밖으로 벗어나면 죽은원자로 처리 !!
	for (int i = 0; i < atom.size(); i++) {
		if (!atom[i].live) continue;
		int x = atom[i].x;
		int y = atom[i].y;
		int d = atom[i].d;
		int nx = x + dx[d];
		int ny = y + dy[d];
		map[x][y] = 0;
		if (!inRange(nx, ny)) { //겪자 밖으로 가면 죽은 원자
			atom[i].live = false;
		}
		else {
			//이동
			map[nx][ny]++;
			atom[i].x = nx;
			atom[i].y = ny;
		}
	}
}
void getEnergy() {
	//원자를 돌면서 이미 죽은 원자는 패스 !!
	//원자를 돌면서 그자리가 2 이상이면 이 원자를 live = false로 하고 k를 더하고 !!
	// 내부 for문으로 원자를 돌면서 그 위치랑 동일한 위치인 원자가 있다면
	//그 k도 더한다음 그 원자를 죽은 원자로 처리.
	for (int i = 0; i < atom.size(); i++) {
		if (!atom[i].live) continue;
		int x = atom[i].x;
		int y = atom[i].y;
		if (map[x][y] >= 2) { //충돌인 상태
			for (int j = 0; j < atom.size(); j++) {
				if (atom[j].x == x && atom[j].y == y) {
					atom[j].live = false;
					energy += atom[j].k;
				}
			}
		}
		//해당위치를 모두 처리했으면 
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