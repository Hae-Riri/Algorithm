#include <iostream>
using namespace std;

int N, ret;
int cnt; //���� ������ ����(1-N���� ����)
pair<int, int> info[15]; // �Ⱓ, �ݾ�

int getPayment(int pick[], int cnt) {//pick�� ���� ��������� �ε�������
	int paySum = 0;
	bool possible = false;
	int day = pick[0]; //�����۳�¥
	int period = info[pick[0]].first;
	int pay = info[pick[0]].second;
	for (int i = 1; i < cnt; i++) {
		if (day + period - 1 >= N) break;
		//�����ϴ� ���ε� ���� �ȳ����ٸ�
		if (day + period - 1 >= pick[i]) continue;
		//�����ٸ� ���� pay�� ���� �� �ٸ� ��� ����
		paySum += pay;
		day = pick[i];
		period = info[pick[i]].first;
		pay = info[pick[i]].second;
	}
	//������ ���
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
		int pick[15] = { 0, };//1��~N������ ������ ���� �� ����
		dfs(-1,0, pick, cnt); //cnt���� ������ ����
	}
	cout << ret << endl;
}

// ������ �� = (���ó�¥ + �ɸ��±Ⱓ - 1)
// �����ϴ� �� = ���� ����� ������ �� + 1 ���� ����
//N�� �߿��� 1��, 2��, ....N�� ���� ���� ������ �̰�
//�� ���պ��� ������ �������� ������ ���