#include <iostream>
#include <queue>
using namespace std;

//���ĭ�� 1, �� ������ �ִ� ĭ�� -1
int map[101][101];
int n, k, l, t, x;
char c;
deque<pair<int,int>>snake;

//������ ȸ���������� ���� (�� �� �� ��)
int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, +1, 0, -1 };
int now_d = 1; //��

void change_d(char c){
	if (c == 'L') {//���ʹ���
		now_d = (now_d + 3) % 4;
	}
	else {//'D' �����ʹ���
		now_d = (now_d + 1) % 4;
	}
}

bool canMove() {
	pair<int, int> before_top = snake.front();
	int nx = before_top.first + dx[now_d];
	int ny = before_top.second + dy[now_d];
	if (nx < 1 || nx > n || ny < 1 || ny > n) //map ���̸� ����
		return false;
	if (map[nx][ny] == -1) return false; //�����̸� �� ��

	//������ �� ���� ���� �������� üũ
	snake.push_front({ nx, ny });
	
	if (map[nx][ny] != 1) { //�� ���� ������� üũ�� �� �ڿ�
		map[snake.back().first][snake.back().second] = 0;
		snake.pop_back();
	}
	//��������ؼ� üũ�� ���ƴٸ� �������� ���� ����
	map[nx][ny] = -1;
	return true;
}
int main() {
	snake.push_back({ 1, 1 });
	map[1][1] = -1;
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		map[x][y] = 1;
	}
	cin >> l;
	for (int i = 0; i < l; i++) {
		cin >> x >> c;
		while (t != x) {
			if (!canMove()) { 
				cout << t+ 1;
				return 0;
			}
			t++;
		}
		//x�� ���������� ����ٲٰ� ���� x�� ����
		change_d(c);
	}
	//���� ������ ���� �� �ٲ� �����ε� ���� ������ ���� ���̶��
	while (1) {
		if (!canMove()) {
			cout << t + 1;
			return 0;
		}
		t++;
	}
	return 0;
}