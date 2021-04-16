//deque으로 구현 /회전시키는 함수
//원판에 인접한 수 처리하는 함수
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int n, m,t;
struct Pan {
	deque<int>dq;
};
struct info {
	int x, d, k;
};
vector<info>rotations(0);
Pan pan[51];
bool same[51][50];
const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0 , 0,-1,1 };
bool inRange(int x, int y) {
	return x >= 1 && x <= n && y >= 0 && y < m;
}
void init() {
	cin >> n >> m >> t;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			int x; cin >> x;
			pan[i].dq.push_back(x);
		}
	}
	for (int i = 0; i < t; i++) {
		int x, d, k;
		cin >> x >> d >> k;
		rotations.push_back({ x,d,k });
	}
}
//i번째 원판을 d 방향으로 k칸만큼 회전
void rotate(int i, int d, int k) { 
	if (d == 0) { 
		for (int j = 0; j < k; j++) {
			int tmp = pan[i].dq.back();
			pan[i].dq.pop_back();
			pan[i].dq.push_front(tmp);
		}
	}
	else if (d == 1) {
		for (int j = 0; j < k; j++) {
			int tmp = pan[i].dq.front();
			pan[i].dq.pop_front();
			pan[i].dq.push_back(tmp);
		}
	}
}
bool remove() {

	bool removed = false; //지워진 인접수가 있는지 확인하는 변수

	//각 좌표별로 사방을 둘러봄
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) { 
			if (pan[i].dq[j] == 0) continue; // 없어진 수는 패스
			for (int dir = 0; dir < 4; dir++) {
				int nx = i + dx[dir]; int ny = j + dy[dir];
				if (ny > m - 1) ny = 0;
				else if (ny < 0) ny = m - 1;
				if (inRange(nx, ny) && pan[i].dq[j] == pan[nx].dq[ny]) {
					removed = true;
					same[i][j] = true;
					same[nx][ny] = true;
				}
			}
		}
	}
	if (!removed) return false;

	//인접한 수가 같은 것을 지우고 same을 초기화
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			if (same[i][j]) {
				pan[i].dq[j] = 0;
			}
			same[i][j] = false;
		}
	}
	return removed;
}
pair<double, int> get_sum_and_cnt() {
	double sum = 0; int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			if (pan[i].dq[j] != 0) {
				sum += pan[i].dq[j];
				cnt++;
			}
		}
	}
	return { sum, cnt };
}
//평균과의 비교를 통해 삭제하는 함수
void deleteByAvg(double avg) {
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			if (pan[i].dq[j] == 0) continue;
			if (pan[i].dq[j] > avg) pan[i].dq[j]--;
			else if(pan[i].dq[j] < avg) pan[i].dq[j]++;
		}
	}
}
void rotate_and_remove() {
	for (int i = 0; i < rotations.size(); i++) {
		int x = rotations[i].x;
		int d = rotations[i].d;
		int k = rotations[i].k;
		for (int j = 2; j <= n; j++) {
			if (j % x == 0) { //x의 배수 원판만 삭제
				rotate(j, d, k);
			}
		}
		//원판 돌린 뒤 sum, count 구하기
		pair<double, int> sum_cnt = get_sum_and_cnt();
		if (sum_cnt.second == 0) continue;

		//인접수 지우기
		bool removed = remove();
		if (!removed) { //지워진 게 없다면 평균 처리
			sum_cnt = get_sum_and_cnt();
			double avg = sum_cnt.first / (double)sum_cnt.second;
			deleteByAvg(avg);
		}
	}
}
int main() {
	init();
	rotate_and_remove();
	cout << (int)get_sum_and_cnt().first;
}