#include <iostream>
#include <stdio.h>
using namespace std;

//코너링을 한번도 안했으면 0번 road임
int map[4][22] = {
	{-1, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26,28,30,32,34,36,38,40,0},
	{10, 13,16,19,25, 30, 35, 40, 0},
	{20, 22, 24,25,30,35,40,0},
	{30, 28, 27,26,25,30,35,40,0}
};

int compare[6] = { 16,22,24,26,28,30};

pair<int, int> mal[4]; //각 말의 위치 저장 (road, location)
bool arrived[4]; //각 말의 도착여부
int turn[10]; //10개 턴별 이동 칸 수 저장
int maxScore = -1; //최대점수 저장할 변수

pair<int,int> canMove(int turnIdx, int malIdx) { //턴 번호, mal 번호
	int cur_road = mal[malIdx].first;
	int cur_location = mal[malIdx].second;
	//시작점이 파란 위치니? (코너링은 아직 안했으면서 다른 파란시작점과 같니?)
	if (cur_road == 0) {
		for (int j = 1; j < 4; j++) {
			if (map[cur_road][cur_location] == map[j][0]) {//경로 변경 해야함.
				cur_road = j;
				cur_location = 0;
				break;
			}
		}
	}
	//실제로 이동을 하기 전까지는 mal[i]를 변경하지 말 것.
	//다 cur_road, cur_location으로 예상 next를 계산하고, 확정나면 그때 변경.

	//이동해보자.
	int next_location = cur_location;
	int move = turn[turnIdx]; //이동해야 할 칸 수
	for(int k= 0; k < move; k++){
		//한 칸씩 옮기다가 도착하면 정지.
		next_location += 1; 
		if (map[cur_road][next_location] == 0) {
			break;
		}
	}
	//이동한 게 도착을 한 거라면 다른 말 있는지 확인 안해도 돼
	if (map[cur_road][next_location] == 0) {
		return { cur_road, next_location };
	}
	//이동한 곳에 다른 말이 있는지 확인
	for (int k = 0; k < 4; k++) {
		if (k == malIdx) continue;
		if (map[cur_road][next_location] == map[mal[k].first][mal[k].second]) {
			int num = map[cur_road][next_location];
			for (int i = 0; i < 6; i++) {
				if (num == compare[i]) { //여기 속하는 숫자는 위치까지 비교해야 해
					if (cur_road != mal[k].first || next_location != mal[k].second) {
						return { cur_road, next_location };
					}
					else
						break;
				}
			}
			return { -1, -1 };
		}
		
	}
	return {cur_road, next_location};
}

void dfs(int turnIdx, int& score) {

	if (turnIdx == 10) {
		maxScore = max(score, maxScore);
		return;
	}

	//말을 선택하자
	for (int i = 0; i < 4; i++) {

		int deTurn = turnIdx;
		int deMal = i;
		
		//이미 도착 칸에 있는 말이니?
		if (arrived[i]) continue;

		pair<int, int> next = canMove(turnIdx, i);
		//이동한 자리에 다른 말이 있니?
		if (next.first == -1) continue;

		//이동 전에 이전 말의 위치와 도착 여부를 저장
		int pre_road = mal[i].first; 
		int pre_location = mal[i].second;
		bool pre_arrived = arrived[i];

		//이동해도 된다면 -> 현재 말을 이동시키자. 
		mal[i] = {next.first, next.second};
		//이동한 위치가 도착이면 도착여부 업데이트
		if (map[mal[i].first][mal[i].second] == 0) {
			arrived[i] = true;
		}
		//점수 업데이트
		score = score + map[mal[i].first][mal[i].second];

		//이동을 마쳐서 여기까지 왔으면 재귀
		dfs(turnIdx + 1, score);
		//재귀해서 왔으면 이동한 말을 원위치, 점수도 원위치
		score = score - map[mal[i].first][mal[i].second];
		mal[i].first = pre_road;
		mal[i].second = pre_location;
		arrived[i] = pre_arrived;
	}
}

int main() {
	for (int i = 0; i < 10; i++) {
		cin >> turn[i];
	}
	int score = 0;
	dfs(0, score);
	cout << maxScore;
	return 0;
}