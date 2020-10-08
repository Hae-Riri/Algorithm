#include <iostream>
using namespace std;

//0,1,2,3 : �� �� �� �� / �̵��� �ε���

//�ϵ����� �� -> �� �� �� ��
int dx[4] = {-1, 0, 1, 0};
int dy[4] = { 0, -1, 0, +1 };
int map[50][50];
bool visit[50][50];

int main() {
	int answer = 1; //����ġ�� �湮 ��ġ��
	int n, m;
	cin >> n >> m; //N(��), M(��)�Է�
	int x, y, d;
	cin >> x >> y >> d; //�� �ִ� ��ġ, �ٶ󺸴� ����
	visit[x][y] = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	while (true) {
		int turn = 0;
		while (turn < 4) {//�� ������ ��� ������ ����
			d++; //����������� ���ʹ������� Ʋ��
			if (d > 3) d = d % 4;
			int nx = x + dx[d];
			int ny = y + dy[d];
			if (nx > 0 && nx < n && ny >0 && ny < m && map[nx][ny] == 0 && !visit[nx][ny]) {
				x = nx;
				y = ny;
				answer++;
				visit[nx][ny] = true;
				turn = 0; //���� �̵������� ����ġ������ turn Ƚ�� �ʱ�ȭ
			}
			else {
				turn++;
			}
		}
		//�׹��� �� �� �� �ڷ� �� �� �ִ°�
		//�ڷΰ��� : ��(0) -> ��(2) , ��(1) -> ��(3)
		d = (d + 2) % 4;
		int nx = x + dx[d];
		int ny = y + dy[d];
		if (map[nx][ny] == 0 && !visit[nx][ny]) {
			x = nx; y = ny; //�ڷ� �̵�
			answer++;
			visit[nx][ny] = true;
		}
		else {
			break;
		}
	}
	cout << answer;
	return 0;
}