#include <iostream>
#include <algorithm>
using namespace std;
int N, M;
int map[500][500];

bool inRange(int x, int y) {
	return x >= 0 && x < N&& y >= 0 && y < M;
}
int getMaxA() {//일자 폴리오미노
	int ret = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (inRange(i, j) && inRange(i + 3, j)) {
				int sum = 0;
				for (int k = 0; k <= 3; k++)
					sum += map[i + k][j];
				ret = max(ret, sum);
			}
			if (inRange(i, j) && inRange(i, j + 3)) {
				int sum = 0;
				for (int k = 0; k <= 3; k++)
					sum += map[i][j + k];
				ret = max(ret, sum);
			}
		}
	}
	return ret;
}
int getMaxB() { //정사각형 폴리오미노
	int ret = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (inRange(i, j) && inRange(i + 1, j+1)) {
				int sum =  map[i][j] + map[i + 1][j] + map[i][j + 1] + map[i + 1][j + 1];
				ret = max(ret, sum);
			}
		}
	}
	return ret;
}
int getMaxC() { //ㄴ자 폴리오미노
	int ret = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (inRange(i -2, j) && inRange(i, j+1)) {
				int sum =map[i][j] + map[i -2][j]+ map[i][j + 1]+map[i -1][j];
				ret = max(ret, sum);
			}
			if ( inRange(i, j+2) && inRange(i+1, j)) {
				int sum = map[i][j] + map[i +1][j]+ map[i][j + 2] +map[i][j+1];
				ret = max(ret, sum);
			}
			 if ( inRange(i, j -1) && inRange(i + 2, j)) {
				int sum = map[i][j]+ map[i + 2][j]+ map[i][j -1]+ map[i+1][j];
				ret = max(ret, sum);
			}
			if ( inRange(i, j - 2) && inRange(i - 1, j)) {
				int sum =map[i][j]+ map[i - 1][j]+ map[i][j - 2]+ map[i][j -1];
				ret = max(ret, sum);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (inRange(i - 1, j) && inRange(i, j + 2)) {
				int sum = map[i][j] + map[i - 1][j] + map[i][j + 2] + map[i][j+1];
				ret = max(ret, sum);
			}
			if (inRange(i, j + 1) && inRange(i + 2, j)) {
				int sum = map[i][j] + map[i + 1][j] + map[i][j + 1] + map[i+2][j];
				ret = max(ret, sum);
			}
			if (inRange(i, j - 2) && inRange(i + 1, j)) {
				int sum = map[i][j] + map[i][j-2] + map[i+1][j] + map[i][j-1];
				ret = max(ret, sum);
			}
			if (inRange(i, j - 1) && inRange(i - 2, j)) {
				int sum = map[i][j] + map[i][j-1] + map[i-2][j] + map[i-1][j];
				ret = max(ret, sum);
			}
		}
	}

	return ret;
}
int getMaxD() { //ㅗ자 모양 폴리오미노
	int ret = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (inRange(i, j) && inRange(i, j-1) && inRange(i, j + 1) && inRange(i+1,j)) {
				int sum = map[i][j] + map[i][j-1] + map[i][j + 1] + map[i + 1][j];
				ret = max(ret, sum);
			}
			if (inRange(i, j) && inRange(i, j - 1) && inRange(i, j + 1) && inRange(i - 1, j)) {
				int sum = map[i][j] + map[i][j-1] + map[i][j + 1] + map[i-1][j];
				ret = max(ret, sum);
			}
			if (inRange(i, j) && inRange(i, j - 1) && inRange(i-1, j) && inRange(i + 1, j)) {
				int sum = map[i][j] + map[i][j-1] + map[i-1][j] + map[i +1][j];
				ret = max(ret, sum);
			}
			if (inRange(i, j) && inRange(i-1, j) && inRange(i, j + 1) && inRange(i + 1, j)) {
				int sum = map[i][j] + map[i - 1][j] + map[i][j + 1] + map[i+1][j];
				ret = max(ret, sum);
			}
		}
	}
	return ret;
}
int getMaxE() { //나머지
	int ret = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (inRange(i-1, j) && inRange(i + 1, j + 1)) {
				int sum = map[i][j] + map[i - 1][j] + map[i+1][j + 1] + map[i][j + 1];
				ret = max(ret, sum);
			}
			if (inRange(i, j-1) && inRange(i - 1, j + 1)) {
				int sum = map[i][j] + map[i][j-1] + map[i -1][j] + map[i-1][j + 1];
				ret = max(ret, sum);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (inRange(i - 1, j+1) && inRange(i + 1, j)) {
				int sum = map[i][j] + map[i - 1][j+1] + map[i + 1][j] + map[i][j + 1];
				ret = max(ret, sum);
			}
			if (inRange(i, j - 1) && inRange(i + 1, j + 1)) {
				int sum = map[i][j] + map[i][j - 1] + map[i + 1][j] + map[i + 1][j + 1];
				ret = max(ret, sum);
			}
		}
	}
	return ret;
}
int main() {
	int ret = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
	ret = max(ret, getMaxA());
	ret = max(ret, getMaxB());
	ret = max(ret, getMaxC());
	ret = max(ret, getMaxD());
	ret = max(ret, getMaxE());
	cout << ret;
	return 0;
}