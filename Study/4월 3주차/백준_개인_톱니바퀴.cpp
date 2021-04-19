#include <iostream>
#include <deque>
#include <vector>
#include <math.h>
using namespace std;

//S���� 1, N���� 0
//1�� �ð�, -1�� �ݽð�, 0�� ȸ�� ���ص� ��
struct Pan {
	deque<int>dq;
};
int K;
Pan pan[4];
vector< pair<int, int> > rotations(0);
int rotate_info[4] = { 0, };
void init() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			char x;
			cin >> x;
			pan[i].dq.push_back(x-'0');
		}
	}
	cin >> K;
	for (int i = 0; i < K; ++i) {
		int num, dir;
		cin >> num >> dir; //ȸ����ų ��Ϲ�ȣ, ����
		rotations.push_back(make_pair(num-1, dir));
	}
}
void set_rotate_info(int num, int dir) {
	rotate_info[num] = dir;
	bool before_rotated = true;

	//������ϵ� Ȯ��
	int cur_num = num, left_num = num - 1, before_dir = dir;
	while (left_num >= 0 && before_rotated) {
		if (pan[cur_num].dq[6] == pan[left_num].dq[2]) {
			before_rotated = false;
			rotate_info[left_num] = 0;
		}
		else {
			rotate_info[left_num] = -before_dir;
			before_dir = rotate_info[left_num];
			cur_num = left_num;
			left_num = left_num - 1;
		}
	}
	//��������ϵ� Ȯ��
	cur_num = num; int right_num = num + 1; 
	before_rotated = true; before_dir = dir;
	while (right_num < 4 && before_rotated) {
		if (pan[cur_num].dq[2] == pan[right_num].dq[6]) {
			before_rotated = false;
			rotate_info[right_num] = 0;
		}
		else {
			rotate_info[right_num] = -before_dir;
			before_dir = rotate_info[right_num];
			cur_num = right_num;
			right_num = right_num + 1;
		}
	}
}
void rotate() {
	for (int i = 0; i < 4; i++) {
		if (rotate_info[i] == 0) continue;
		else if (rotate_info[i] == 1) { //�ð���� ȸ��
			int tmp = pan[i].dq.back();
			pan[i].dq.pop_back();
			pan[i].dq.push_front(tmp);
		}
		else if (rotate_info[i] == -1) {
				int tmp = pan[i].dq.front();
				pan[i].dq.pop_front();
				pan[i].dq.push_back(tmp);
		}
	}
}
void solve() {
	for (int i = 0; i < K; i++) {
		//�� ȸ������ ȸ�����Ѿ� �� ��Ϲ����� �� ������ ����
		for (int r = 0; r < 4; r++)
			rotate_info[r] = 0;

		int num = rotations[i].first;
		int dir = rotations[i].second;
		set_rotate_info(num, dir);
		//print_rotate_info();
		rotate();
	}
}
int getRes() {
	int res = 0;
	for (int i = 0; i < 4; i++) {
		if (pan[i].dq[0] == 1) {
			res += pow(2, i);
		}
	}
	return res;
}
int main() {
	init();
	solve();
	cout << getRes();
	return 0;
}