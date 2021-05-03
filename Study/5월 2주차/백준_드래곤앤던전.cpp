#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n;
long long cur_a, ans, initial_a;
struct Room {
	long long t, a, h;
};
vector<Room> room;

void init() {
	cin >> n >> initial_a;
	for (int i = 0; i < n; i++) {
		long long t, a, h;
		cin >> t >> a >> h;
		room.push_back({ t, a, h });
	}
}
bool canRescue(long long max_h) {

	cur_a = initial_a;
	long long cur_h = max_h;

	for (int i = 0; i < room.size(); i++) {
		if (room[i].t == 1) { //몬스터가 있음
			//몬스터 생명력이 0이 되기 위한 공격 반복횟수
			long long kill_monster_time = room[i].h / cur_a;
			if (room[i].h % cur_a > 0) kill_monster_time++;

			//용사 생명력이 0이 되기 위한 공격 반복횟수
			long long kill_man_time = cur_h / room[i].a;
			if (cur_h % room[i].a > 0)  kill_man_time++;

			//몬스터보다 용사가 먼저 죽으면
			if (kill_monster_time > kill_man_time) return false;

			//몬스터를 죽이는동안 용사가 생명력이 소모된 상태로 업데이트
			//몬스터가 먼저 죽는다면 그때에는 용사의 생명력을 소모하지 않으니까 -1
			cur_h -= ((kill_monster_time - 1) * room[i].a);
		}
		else { //포션
			cur_a += room[i].a;
			cur_h += room[i].h;
			if (cur_h > max_h) cur_h = max_h;
		}
	}
	return true;
}
int main() {
	init();
	long long l = 1, r = LLONG_MAX;
	while (l <= r) {
		long long mid = (l+r) / 2;
		if (canRescue(mid)) { //구할 수 있다면 생명력 줄여서 탐색
			ans = mid;
			r = mid - 1;
		}
		else { //구할 수 없다면 생명력 늘리기
			l = mid + 1;
		}
	}
	cout << ans << "\n";
	return 0;
}