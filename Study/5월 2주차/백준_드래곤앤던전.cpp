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
		if (room[i].t == 1) { //���Ͱ� ����
			//���� ������� 0�� �Ǳ� ���� ���� �ݺ�Ƚ��
			long long kill_monster_time = room[i].h / cur_a;
			if (room[i].h % cur_a > 0) kill_monster_time++;

			//��� ������� 0�� �Ǳ� ���� ���� �ݺ�Ƚ��
			long long kill_man_time = cur_h / room[i].a;
			if (cur_h % room[i].a > 0)  kill_man_time++;

			//���ͺ��� ��簡 ���� ������
			if (kill_monster_time > kill_man_time) return false;

			//���͸� ���̴µ��� ��簡 ������� �Ҹ�� ���·� ������Ʈ
			//���Ͱ� ���� �״´ٸ� �׶����� ����� ������� �Ҹ����� �����ϱ� -1
			cur_h -= ((kill_monster_time - 1) * room[i].a);
		}
		else { //����
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
		if (canRescue(mid)) { //���� �� �ִٸ� ����� �ٿ��� Ž��
			ans = mid;
			r = mid - 1;
		}
		else { //���� �� ���ٸ� ����� �ø���
			l = mid + 1;
		}
	}
	cout << ans << "\n";
	return 0;
}