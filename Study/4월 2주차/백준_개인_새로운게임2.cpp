//���� ��ȣ ����
//���� 4�� �̻� �׿����� üũ�ϴ� �Լ�
//vector board[n][n]
//int color[][] //�÷�����
//k���� ���� ��ġ�� �����ϴ� struct info vector(x,y,dir), horses
//��ȣ ������� ���� ĭ�� �����ͼ� board���� ����
//���󺰷� �̵��Ϸ��� horse�� �̵��� ĭ�� �ֱ�
//�̵��Ϸ��� ĭ�� ����
//��� : �� ĭ���� �̵�
//���� �߰��� ���� �ִ°Ÿ� 0������ �� �ε��� ã������, �ű⼭���� ������ 
//��ȸ�ϸ鼭 ������� �̵��Ϸ��� ĭ �ڿ� push_back�ϱ�
//������ : ������ �ݴ�� �ٲ㼭 �̵�
//���� �߰��� ���� �ִ°Ÿ� ã�Ƽ� ������ �ε������� ��ȸ�ؼ� ã������
//�ش� ���� ã�� �� �ε������� ������� �̵��Ƿ��� ĭ�� push_back()
//�Ķ��� : �̵� �� ���� ������ �ٲ�(horse������ ������) / �길 �ٲ��.
//�ٲ� �������� �̵��������� ĭ�� �Ķ����̰ų� �����̸� ������.
//�Ķ����̰ų� ������ �ƴ϶�� �̵��� ĭ�� ���� Ȯ���ѵ�
//�ش��Լ� ȣ��(���縻�� ���� , �̵��� ĭ)
#include <iostream>
#include <vector>
using namespace std;

int turn, n, k;
vector<int> board[13][13]; //��� 1~12
int color[13][13];//��� 1~1
struct info {
	int x, y, dir; //dir : 1~4
	info(int x, int y, int dir) : x(x), y(y), dir(dir) {};
};
vector<info>horses(11, info(0,0,0));
const int dx[] = { 0, 0, 0, -1, 1 };
const int dy[] = { 0, 1, -1, 0, 0 };

bool inRange(int x, int y) {
	return x > 0 && x <= n && y > 0 && y <= n;
}
int changeDir(int dir) {
	if (dir == 1) return 2;
	else if (dir == 2) return 1;
	else if (dir == 3) return 4;
	else if (dir == 4) return 3;
	return 0;
}
void init() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> color[i][j];
		}
	}
	for (int i = 1; i <= k; i++) {
		int x, y, d;
		cin >> x >> y >> d;
		horses[i].x = x;
		horses[i].y = y;
		horses[i].dir = d;
		board[x][y].push_back(i); //�ش� ���� ��ȣ�� board�� ����
	}
}
void moveWhite(int horse_idx, int x, int y, int nx, int ny) {
	//���� ĭ�� �ִ� ������ �� ���� ��� ���� �̵�(�� �Ʒ����� �ϳ��� �̵�)
	bool isFind = false; int cnt = 0;
	for (int i = 0; i < board[x][y].size(); i++) {
		if (board[x][y][i] == horse_idx) isFind = true;
		if (isFind) { //ã�Ҵٸ� �ű⼭���� �� ���� ���� �͵� ���� �ű��
			cnt++;
			horses[board[x][y][i]].x = nx;
			horses[board[x][y][i]].y = ny;
			board[nx][ny].push_back(board[x][y][i]);
		}
	}
	//�Ű��� ������ŭ �����ϱ�
	for (int i = 0; i < cnt; i++) {
		board[x][y].pop_back();
	}
}
void moveRed(int horse_idx, int x, int y, int nx, int ny) {
	bool isFind = false; int cnt = 0;
	//�ڿ������� ���鼭 ã�� �������� ������ ��� �ű��
	for (int i = board[x][y].size() -1; i >=0; i--) {
		if(!isFind) {
			cnt++;
			horses[board[x][y][i]].x = nx;
			horses[board[x][y][i]].y = ny;
			board[nx][ny].push_back(board[x][y][i]);
		}
		if (board[x][y][i] == horse_idx) isFind = true; //�ڱ��ڽű��� �̵��ؾ��ϴϱ� ��������
	}
	//�Ű��� ������ŭ �����ϱ�
	for (int i = 0; i < cnt; i++) {
		board[x][y].pop_back();
	}
}
void moveBlue(int horse_idx, int x, int y) {
	//�ݴ�������� ����
	int changed_dir = changeDir(horses[horse_idx].dir); 
	horses[horse_idx].dir = changed_dir;
	int nx = x + dx[changed_dir];
	int ny = y + dy[changed_dir];
	if (!inRange(nx,ny)) return;
	else if (color[nx][ny] == 2) return;
	else if (color[nx][ny] == 0) {//���
		moveWhite(horse_idx, x, y, nx, ny);
	}
	else if (color[nx][ny] == 1) {//������
		moveRed(horse_idx, x, y, nx, ny);
	}
}
bool isEnd() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (board[i][j].size() >= 4) {
				return true;
			}
		}
	}
	return false;
}
bool play() {
	for (int i = 1; i <= k; i++) { //i�� �� �̵�
		int x = horses[i].x;
		int y = horses[i].y;
		int dir = horses[i].dir;
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (!inRange(nx, ny)) {
			moveBlue(i, x, y);
		}
		else if (color[nx][ny] == 0) { //���
			moveWhite(i, x, y, nx, ny);
		}
		else if (color[nx][ny] == 1) {//������
			moveRed(i, x, y, nx, ny);
		}
		else if (color[nx][ny] == 2) {//�Ķ���
			moveBlue(i, x, y);
		}
		if (isEnd()) return false;
	}
	return true;
}
int main() {
	init();
	while (turn <= 1000) { //1000�� ���� �� �ͱ��� ����
		turn++;
		if (!play()) {//�� ���� ������ ���� �ߵ������̸� �� ��� turn ���
			cout << turn;
			return 0;
		}
	}
	cout << "-1";
	return 0;
}