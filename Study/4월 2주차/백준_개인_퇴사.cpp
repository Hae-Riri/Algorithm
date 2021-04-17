#include <iostream>
using namespace std;

int N, ret;
int cnt; //뽑은 조합의 개수(1-N까지 가능)
pair<int, int> info[15]; // 기간, 금액

int getPayment(int pick[], int cnt) {//pick은 뽑힌 상담정보의 인덱스들임
	int paySum = 0;
	bool possible = false;
	int day = pick[0]; //상담시작날짜
	int period = info[pick[0]].first;
	int pay = info[pick[0]].second;
	for (int i = 1; i < cnt; i++) {
		if (day + period - 1 >= N) break;
		//시작하는 날인데 아직 안끝났다면
		if (day + period - 1 >= pick[i]) continue;
		//끝났다면 기존 pay를 더한 뒤 다른 상담 시작
		paySum += pay;
		day = pick[i];
		period = info[pick[i]].first;
		pay = info[pick[i]].second;
	}
	//마지막 상담
	if (day + period - 1 < N) paySum += pay;
	return paySum;
}

void dfs(int last_pick, int pick_count, int pick[], int cnt) {
	if (pick_count == cnt) {
		int payment = getPayment(pick, cnt);
		if (payment > ret)
			ret = payment;
		return;
	}
	for (int i = last_pick + 1; i < N; i++) {
		pick[pick_count] = i;
		dfs(i, pick_count + 1, pick, cnt);
	}
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> info[i].first >> info[i].second;
	}
	for (int cnt = 1; cnt <= N; cnt++) {
		int pick[15] = { 0, };//1개~N개까지 조합을 뽑을 수 있음
		dfs(-1,0, pick, cnt); //cnt개의 상담건을 뽑음
	}
	cout << ret << endl;
}

// 끝나는 날 = (오늘날짜 + 걸리는기간 - 1)
// 시작하는 날 = 이전 상담이 끝나는 날 + 1 부터 가능
//N일 중에서 1개, 2개, ....N개 까지 각각 조합을 뽑고
//각 조합별로 가능한 상담까지만 이익을 계산