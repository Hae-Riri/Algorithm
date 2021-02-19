#include <iostream>
#include <queue>
using namespace std;

//사과칸은 1, 뱀 몸통이 있는 칸은 -1
int map[101][101];
int n, k, l, t, x;
char c;
deque<pair<int,int>>snake;

//오른쪽 회전방향으로 구현 (상 우 하 좌)
int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, +1, 0, -1 };
int now_d = 1; //우

void change_d(char c){
	if (c == 'L') {//왼쪽방향
		now_d = (now_d + 3) % 4;
	}
	else {//'D' 오른쪽방향
		now_d = (now_d + 1) % 4;
	}
}

bool canMove() {
	pair<int, int> before_top = snake.front();
	int nx = before_top.first + dx[now_d];
	int ny = before_top.second + dy[now_d];
	if (nx < 1 || nx > n || ny < 1 || ny > n) //map 밖이면 못감
		return false;
	if (map[nx][ny] == -1) return false; //몸통이면 못 감

	//앞으로 갈 곳에 대해 몸통으로 체크
	snake.push_front({ nx, ny });
	
	if (map[nx][ny] != 1) { //갈 곳의 사과부터 체크를 한 뒤에
		map[snake.back().first][snake.back().second] = 0;
		snake.pop_back();
	}
	//사과관련해서 체크를 마쳤다면 몸통으로 정보 변경
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
		//x에 도달했으니 방향바꾸고 다음 x를 받자
		change_d(c);
	}
	//변할 방향의 수는 다 바뀐 상태인데 아직 게임이 진행 중이라면
	while (1) {
		if (!canMove()) {
			cout << t + 1;
			return 0;
		}
		t++;
	}
	return 0;
}