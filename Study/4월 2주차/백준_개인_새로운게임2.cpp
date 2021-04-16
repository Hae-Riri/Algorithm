//턴의 번호 저장
//말이 4개 이상 쌓였는지 체크하는 함수
//vector board[n][n]
//int color[][] //컬러저장
//k개의 말의 위치를 저장하는 struct info vector(x,y,dir), horses
//번호 순서대로 말의 칸을 가져와서 board에서 보고
//색상별로 이동하려는 horse와 이동될 칸을 주기
//이동하려는 칸에 따라
//흰색 : 그 칸으로 이동
//쌓인 중간에 끼어 있는거면 0번부터 그 인덱스 찾은다음, 거기서부터 끝까지 
//순회하면서 순서대로 이동하려는 칸 뒤에 push_back하기
//빨간색 : 순서를 반대로 바꿔서 이동
//쌓인 중간에 끼어 있는거면 찾아서 마지막 인덱스부터 순회해서 찾은다음
//해당 값을 찾은 그 인덱스까지 순서대로 이동되려는 칸에 push_back()
//파란색 : 이동 전 말의 방향을 바꿈(horse방향을 변경함) / 얘만 바꿔라.
//바꾼 방향으로 이동했을때의 칸이 파란색이거나 경계밖이면 가만히.
//파란색이거나 경계밖이 아니라면 이동될 칸의 색을 확인한뒤
//해당함수 호출(현재말의 정보 , 이동될 칸)
#include <iostream>
#include <vector>
using namespace std;

int turn, n, k;
vector<int> board[13][13]; //행렬 1~12
int color[13][13];//행렬 1~1
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
		board[x][y].push_back(i); //해당 말의 번호를 board에 놓기
	}
}
void moveWhite(int horse_idx, int x, int y, int nx, int ny) {
	//기존 칸에 있는 현재의 말 위의 모든 말이 이동(맨 아래부터 하나씩 이동)
	bool isFind = false; int cnt = 0;
	for (int i = 0; i < board[x][y].size(); i++) {
		if (board[x][y][i] == horse_idx) isFind = true;
		if (isFind) { //찾았다면 거기서부터 그 위에 쌓인 것들 전부 옮기기
			cnt++;
			horses[board[x][y][i]].x = nx;
			horses[board[x][y][i]].y = ny;
			board[nx][ny].push_back(board[x][y][i]);
		}
	}
	//옮겨진 개수만큼 삭제하기
	for (int i = 0; i < cnt; i++) {
		board[x][y].pop_back();
	}
}
void moveRed(int horse_idx, int x, int y, int nx, int ny) {
	bool isFind = false; int cnt = 0;
	//뒤에서부터 보면서 찾기 전까지의 값들을 모두 옮기기
	for (int i = board[x][y].size() -1; i >=0; i--) {
		if(!isFind) {
			cnt++;
			horses[board[x][y][i]].x = nx;
			horses[board[x][y][i]].y = ny;
			board[nx][ny].push_back(board[x][y][i]);
		}
		if (board[x][y][i] == horse_idx) isFind = true; //자기자신까지 이동해야하니까 순서변경
	}
	//옮겨진 개수만큼 삭제하기
	for (int i = 0; i < cnt; i++) {
		board[x][y].pop_back();
	}
}
void moveBlue(int horse_idx, int x, int y) {
	//반대방향으로 변경
	int changed_dir = changeDir(horses[horse_idx].dir); 
	horses[horse_idx].dir = changed_dir;
	int nx = x + dx[changed_dir];
	int ny = y + dy[changed_dir];
	if (!inRange(nx,ny)) return;
	else if (color[nx][ny] == 2) return;
	else if (color[nx][ny] == 0) {//흰색
		moveWhite(horse_idx, x, y, nx, ny);
	}
	else if (color[nx][ny] == 1) {//빨간색
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
	for (int i = 1; i <= k; i++) { //i번 말 이동
		int x = horses[i].x;
		int y = horses[i].y;
		int dir = horses[i].dir;
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (!inRange(nx, ny)) {
			moveBlue(i, x, y);
		}
		else if (color[nx][ny] == 0) { //흰색
			moveWhite(i, x, y, nx, ny);
		}
		else if (color[nx][ny] == 1) {//빨간색
			moveRed(i, x, y, nx, ny);
		}
		else if (color[nx][ny] == 2) {//파란색
			moveBlue(i, x, y);
		}
		if (isEnd()) return false;
	}
	return true;
}
int main() {
	init();
	while (turn <= 1000) { //1000번 돌고 온 것까지 가능
		turn++;
		if (!play()) {//한 턴이 끝나기 전에 중도리턴이면 그 즉시 turn 출력
			cout << turn;
			return 0;
		}
	}
	cout << "-1";
	return 0;
}