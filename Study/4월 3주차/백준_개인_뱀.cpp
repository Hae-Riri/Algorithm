#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int N, K, L , snake_d;
int map[101][101]; //행열 1부터 시작
vector<pair <int, char > > turns;
deque< pair<int, int> > snake;
const int dx[] = {0, 1, 0, -1}; //우하좌상
const int dy[] = { 1, 0, -1, 0 };

bool inRange(int x, int y) {
	return x >= 1 && x <= N && y >= 1 && y <= N;
}

void init() {
	cin >> N;
	cin >> K;
	for (int i = 0; i < K; i++) {
		int r, c;
		cin >> r >> c;
		map[r][c] = 1;
	}
	cin >> L;
	for (int i = 0; i < L; i++) {
		int x; char c;
		cin >> x >> c;
		turns.push_back(make_pair(x, c));
	}
	snake_d = 0;
	snake.push_back(make_pair(1, 1));
}
bool collision(int x, int y) { //자기자신의 몸과 부딪히는지 확인
	//다음 이동할 칸이 뱀의 몸 중에 하나면 true
	for (int i = 0; i < snake.size(); i++) {
		if (snake[i].first == x && snake[i].second == y) return true;
	}
	return false;
}
int main() {
	init();
	int time = 0;
	int turn_idx = 0;
	while (true) {
		time++; //이번 초에 할 일을 하자.
		int x = snake.front().first; 
		int y = snake.front().second;
		
		//머리를 다음 칸에 위치시키기
		int nx = x + dx[snake_d];
		int ny = y + dy[snake_d];
		if (!inRange(nx, ny)) { cout << time; break; }
		if(collision(nx, ny)) { cout << time; break; }
		snake.push_front(make_pair(nx, ny));

		//꼬리위치 처리
		if (map[nx][ny] == 1) { //사과가 있다면
			map[nx][ny] = 0; //먹음
		}
		else {
			snake.pop_back(); //꼬리를 하나 제거
		}

		//이번 초가 끝난 뒤 방향 전환해야 하는지 체크
		if (turn_idx == turns.size()) continue;
		if (turns[turn_idx].first == time) {
			if (turns[turn_idx].second == 'D') {
				snake_d = (snake_d + 1) % 4;
			}
			else {
				snake_d = snake_d - 1;
				if (snake_d < 0) snake_d = 3;
			}
			turn_idx++;
		}
	}
	return 0;
}