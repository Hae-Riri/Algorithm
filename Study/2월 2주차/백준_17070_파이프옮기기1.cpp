#include <iostream>
#include <queue>
using namespace std;

int map[17][17];// 1~16 �ε��� ���
int n, ans;
int dx[3] = {0, +1, +1}; //���� �밢�� ����
int dy[3] = { +1, +1, 0 };

struct info {
	int x, y, d;
	//������ 0, 1, 2 ������� ����, �밢��, ����
};

queue<info>q;

void move(int x, int y, int d, int i) {
	int nx = x + dx[i];
	int ny = y + dy[i];
	int nd = i;
	if (map[nx][ny] == 0 && nx > 0 && nx <= n && ny > 0 && ny <= n) {
		if (i == 1) {//�밢���� �߰� üũ
			if (map[nx - 1][ny] == 1 || map[nx][ny - 1] == 1)
				return;
		}
		q.push({ nx, ny, nd });
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
	q.push({ 1,2,0 });
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int d = q.front().d;
		q.pop();
		if (x == n && y == n)
			ans++;
		if (d == 0) { //����
			for (int i = 0; i < 2; i++) { //0,1�� �̵�
				move(x, y, d, i);
			}
		}
		else if (d == 1) {//�밢��
			for (int i = 0; i < 3; i++) { //0,1,2�� �̵�
				move(x, y, d, i);
			}
		}
		else {//�Ʒ�
			for (int i = 1; i < 3; i++) { //1,2�� �̵�
				move(x, y, d, i);
			}
		}
	}
	cout << ans;
	return 0;
}