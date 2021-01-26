#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int map[101][101];
int n, k, l, t;
int now_d = 1;
deque<pair<int, int>> snake;
vector<pair<int, char>>v;
//상우하좌
int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, +1, 0, -1 };
bool getAns;

bool canMove() {
	int x = snake.front().first;
	int y = snake.front().second;
	int nx = x + dx[now_d];
	int ny = y + dy[now_d];
	if (map[nx][ny] == -1 || nx < 1 || nx > n || ny < 1 || ny > n) {
		return false;
	}
	
	if (map[nx][ny] == 0) {//사과가 없다면
		int bx = snake.back().first;
		int by = snake.back().second;
		snake.pop_back();
		map[bx][by] = 0; //몸통 제거
	}
	//사과가 없었다고 해서 0으로 바꿀게 아니라 몸통이 있게 된거니까
	//-1로 해두고 납둬야죠.
	//else { //사과가 있다면
	//	//꼬리는 그대로고 사과는 제거
	//	map[nx][ny] = 0;
	//}
	snake.push_front({ nx, ny });
	map[nx][ny] = -1; //몸통은 -1로
	return true;
}

int main() {
	snake.push_back({ 1, 1 });
	map[1][1] = -1;
	scanf_s("%d\n%d\n", &n, &k);
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		//사과위치는 1
		map[x][y] = 1;
	}
	cin >> l;
	
	for (int i = 0; i < l; i++) {
		int x; char c;
		cin >> x >> c;
		v.push_back({ x,c });
	}
	for (int i = 0; i < l; i++) {
		int x = v[i].first;
		char c = v[i].second;
		while (t < x) {
			if (!canMove()) {
				cout << t + 1;
				return 0;
			}
			t++; 
			//canMove로 미리 이동을 시켜놓은 다음에
			//t++를 하는 거니까 t == x라면 이미 x초까지의 수행이 다 된거야.
		}
		//x초까지 수행하고 그 다음
		if (c == 'D')
			now_d = (now_d + 1) % 4;
		else
			now_d = (now_d + 3) % 4;
 	}
	while (1) {
		if (!canMove()) {
			cout << t + 1;
			return 0;
		}
		t++;
	}
	return 0;
}