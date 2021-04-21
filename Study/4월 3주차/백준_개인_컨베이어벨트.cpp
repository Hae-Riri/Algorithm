#include <deque>
#include <iostream>
using namespace std;

int n, k;
deque<pair<int, bool> > dq; //내구도, 로봇여부
void init() {
	cin >> n >> k;
	for (int i = 0; i <= 2*n -1; i++) {
		int x; cin >> x;
		dq.push_back({ x, 0 });
	}
}
void print() {
	for (int i = 0; i < dq.size(); i++)
		cout <<"{" << dq[i].first << ","<<dq[i].second<<"}, ";
	cout << endl;
}
//올라가는 위치는 0, 내려가는 위치는 n-1;
int main() {
	init();
	int all_step = 0;
	while (true) {
		all_step++;

		//step1 한칸 회전
		dq.push_front(dq.back());
		dq.pop_back();
		if(dq[n-1].second) dq[n - 1].second = false; //내려오는 위치 오자마자 내리기

		//step2
		for (int i = n - 2; i >= 0; i--) {
			if (dq[i].second && !dq[i + 1].second && dq[i + 1].first > 0) {//내자리는 로봇있고, 옆자린 없으면서, 옆자리 내구도가 0 초과
				dq[i + 1].first--;
				dq[i].second = false;
				dq[i + 1].second = true;
			}
		}
		dq[n - 1].second = false; //내려가는 위치에 로봇이 왔으면 걔도 내려야 해.

		//step3
		if (!dq[0].second && dq[0].first > 0) {
			dq[0].second = true;
			dq[0].first--;
		}

		//step4
		int cnt = 0;
		for (int i = 0; i < 2 * n; i++) {
			if (dq[i].first <= 0) cnt++;
		}
		if (cnt >= k) break;
	}
	cout << all_step;
	return 0;
}