#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
#define INF 987654321

int N, M, ret;
int city[51][51];
vector<pair<int, int> > chicken;
vector<int> pick;
//0빈칸, 1집, 2치킨

int getDistance() { //현재의 pick에 따라 getDistance함
	int city_distance = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (city[i][j] == 1) { //집이라면 pick된 치킨집까지의 거리 중 최소를 구해
				int min_distance = INF;
				for (int k = 0; k < pick.size(); k++) {
					int cx = chicken[pick[k]].first;
					int cy = chicken[pick[k]].second;
					int distance = abs(i - cx) + abs(j - cy);
					min_distance = min(min_distance, distance);
				}
				city_distance += min_distance;
			}
		}
	}
	return city_distance;
}

void dfs(int cur, int count, int M) {
	if (count == M) {
		ret = min(getDistance(), ret);
		return;
	}
	for (int i = cur; i < chicken.size(); ++i) {
		pick.push_back(i); //치킨정보의 인덱스를 pick함
		dfs(i + 1, count + 1, M);
		pick.pop_back();
	}
	return;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> city[i][j];
			if (city[i][j] == 2) {
				chicken.push_back(make_pair(i, j));
			}
		}
	}
	ret = INF;
	for (int i = 1; i <= M; i++) { //1개뽑는 경우부터 M개뽑는 경우까지 해보기
		dfs(0, 0, i);
	}
	cout << ret;
	return 0;
}