#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 500
using namespace std;

int n;
int map[20][20];
int dist[20][20];
struct SHARK {
	int x, y, size;
};
SHARK shark;
struct FISH {
	int x, y;
};
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };
void print() {
	cout << "맵" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}
void printD() {
	cout << "distance" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << dist[i][j] << " ";
		}
		cout << endl;
	}
}
void printEatable(vector<FISH>eatable) {
	cout << "eatable" << endl;
	for (int i = 0; i < eatable.size(); i++) {
		cout << eatable[i].x << eatable[i].y << " ";
	}
	cout << endl;
}
void init() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				shark.x = i;
				shark.y = j;
				shark.size = 2;
			}
		}
	}
}
bool cmp(FISH a, FISH b) { //거리작은순 -> 행이 작은 순 ->열이 작은 순
	if (dist[a.x][a.y] == dist[b.x][b.y]) {
		if (a.x == b.x) {
			if (a.y < b.y) return true;
			else return false;
		}
		else {
			if (a.x < b.x) return true;
			else return false;
		}
	}
	else {
		if (dist[a.x][a.y] < dist[b.x][b.y]) return true;
		else return false;
	}
}
bool inRange(int x, int y) {
	return x >= 0 && x < n&& y >= 0 && y < n;
}
vector<FISH> findEatable() {
	//거리 최댓값으로 초기화
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dist[i][j] = INF;
		}
	}

	queue<FISH>q;
	q.push({ shark.x, shark.y });
	dist[shark.x][shark.y] = 0;

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (inRange(nx, ny) && map[nx][ny] <= shark.size) {//상어랑 같거나 작으면 지나가기 가능
				if (dist[nx][ny] > dist[x][y] + 1) {
					dist[nx][ny] = dist[x][y] + 1;
					q.push({ nx, ny });
				}
			}
		}
	}

	vector<FISH> eatable(0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if ((i != shark.x || j != shark.y) && map[i][j] < shark.size && map[i][j] > 0 && dist[i][j] != 500) { //먹을 수 있는 물고기라면 (단 상어라서 9인 위치는 제외)
				eatable.push_back({ i, j });
			}
		}
	}

	return eatable;
}
int main() {
	init();
	int time = 0;
	int eaten_cnt = 0;
	while (true) {

		//먹을 수 있는 물고기 탐색
		vector<FISH> eatable = findEatable();

		//정렬
		sort(eatable.begin(), eatable.end(), cmp);
		if (eatable.size() == 0) break;

		//print();
		//printD();

		//상어 이동
		FISH eaten = eatable[0];
		int distance = dist[eaten.x][eaten.y];
		map[shark.x][shark.y] = 0;
		shark.x = eaten.x;
		shark.y = eaten.y;
		map[shark.x][shark.y] = 9;
		time += distance;
		eaten_cnt++;
		if (eaten_cnt == shark.size) { shark.size++; eaten_cnt = 0; }
		
		//cout << "이동 후 " << endl;
		//cout << "distance : " << distance << endl;
		//cout << "time : " << time << endl;
		//print();

	}
	cout << time;
	return 0;
}