#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int N, K, L , snake_d;
int map[101][101]; //�࿭ 1���� ����
vector<pair <int, char > > turns;
deque< pair<int, int> > snake;
const int dx[] = {0, 1, 0, -1}; //�����»�
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
bool collision(int x, int y) { //�ڱ��ڽ��� ���� �ε������� Ȯ��
	//���� �̵��� ĭ�� ���� �� �߿� �ϳ��� true
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
		time++; //�̹� �ʿ� �� ���� ����.
		int x = snake.front().first; 
		int y = snake.front().second;
		
		//�Ӹ��� ���� ĭ�� ��ġ��Ű��
		int nx = x + dx[snake_d];
		int ny = y + dy[snake_d];
		if (!inRange(nx, ny)) { cout << time; break; }
		if(collision(nx, ny)) { cout << time; break; }
		snake.push_front(make_pair(nx, ny));

		//������ġ ó��
		if (map[nx][ny] == 1) { //����� �ִٸ�
			map[nx][ny] = 0; //����
		}
		else {
			snake.pop_back(); //������ �ϳ� ����
		}

		//�̹� �ʰ� ���� �� ���� ��ȯ�ؾ� �ϴ��� üũ
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