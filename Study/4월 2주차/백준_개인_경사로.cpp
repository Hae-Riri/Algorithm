#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int map[100][100], c_map[100][100];
int N, L, ret;

bool canMakeRoad(int x, int y, int map[][100]) {
	int bottom = map[x][y+1]; //평지높이여야 하는 값
	for (int j = y + 1; j <= y + L ; j++) { //현위치 다음부터 L개의 평지가 있어야 해
		if (map[x][j] != bottom) return false;
	}
	return true;
}
void removeRoadRow(int map[][100]) {
	for (int i = 0; i < N; ++i) {
		bool isBlue = true;
		int before_road = 1; //시작하는 칸을 포함해야 하니까 1로 초기화, 경사로 바닥과 접하는 개수

		for (int j = 0; j < N-1; ++j) {
			int sub = map[i][j] - map[i][j + 1];
			if (sub == 0) before_road++; //평지
			else if (sub == 1) { //앞이 더 높을 때
				//앞으로 경사로 길이만큼 평평한지 확인
				if (!canMakeRoad(i, j, map)) {
					isBlue = false; break;
				}
				else { //만들수 있다면 현위치까지 경사로로 체크한 뒤 통으로 넘어가기
					j = j + L -1; // j+L도 j+L+1과 비교해야하니까 
					before_road = 0; //앞으로 될 j+L은 이미 경사로가 접하는 자리라 더해주면 안돼
				}
			}
			else if (sub == -1) {//뒤가 더 높을 때
				if (before_road < L) {
					isBlue = false; break;
				}
				else before_road = 1;
			}
			else if (abs(sub) > 1) {
				isBlue = false; break;
			}
		}
		if (!isBlue) ret--;
	}
}
int main() {
	cin >> N >> L;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> map[i][j];
	ret = 2* N;
	removeRoadRow(map); 
	for (int j = 0; j < N; ++j)
		for (int i = 0; i < N; ++i)
			c_map[j][i] = map[i][j];
	removeRoadRow(c_map);
	cout << ret;
	return 0;
}