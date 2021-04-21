#include <deque>
#include <iostream>
using namespace std;

int n, k;
deque<pair<int, bool> > dq; //������, �κ�����
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
//�ö󰡴� ��ġ�� 0, �������� ��ġ�� n-1;
int main() {
	init();
	int all_step = 0;
	while (true) {
		all_step++;

		//step1 ��ĭ ȸ��
		dq.push_front(dq.back());
		dq.pop_back();
		if(dq[n-1].second) dq[n - 1].second = false; //�������� ��ġ ���ڸ��� ������

		//step2
		for (int i = n - 2; i >= 0; i--) {
			if (dq[i].second && !dq[i + 1].second && dq[i + 1].first > 0) {//���ڸ��� �κ��ְ�, ���ڸ� �����鼭, ���ڸ� �������� 0 �ʰ�
				dq[i + 1].first--;
				dq[i].second = false;
				dq[i + 1].second = true;
			}
		}
		dq[n - 1].second = false; //�������� ��ġ�� �κ��� ������ �µ� ������ ��.

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