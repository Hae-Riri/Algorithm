#include <iostream>
#include <string>
using namespace std;

int main() {
	//L, R, U, D����
	//x�� ��, y�� ��
	int dx[4] = {0, 0, -1, +1};
	int dy[4] = {-1, +1, 0, 0};
	char directions[4] = { 'L', 'R', 'U', 'D' };

	int n;
	cin >> n;
	cin.ignore(); //�ٹٲ� ���ڸ� �ν��ؼ� �ٷ� ó���ǹǷ� ���۸� ����� ���� ���� �ν��� �� ����
	string plans;	
	//���⸦ �����ϵ� �ٹٲ� ���� �����ϰ� ��°�� �� ���� �Է¹ޱ�(string ���)
	getline(cin, plans);
	int x = 1; int y = 1;

	for (int i = 0; i < plans.size(); i++) {
		int nx = 0; int ny = 0;
		for (int j = 0; j < 4; j++) {
			if (plans[i] == directions[j]) {
				nx = x + dx[j];
				ny = y + dy[j];
			}
		}
		if (nx <1 || nx >n || ny <1 || ny >n) {
			continue;
		}
		else {
			x = nx; 
			y = ny;
		}
	}
	cout << x << " " << y;
	return 0;
}