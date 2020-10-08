#include <iostream>
using namespace std;

//0,1,2,3 : 북 동 남 서 / 이동의 인덱스

//북동남서 순 -> 상 좌 하 우
int dx[4] = {-1, 0, 1, 0};
int dy[4] = { 0, -1, 0, +1 };
int map[50][50];
bool visit[50][50];

int main() {
	int answer = 1; //현위치도 방문 위치라서
	int n, m;
	cin >> n >> m; //N(행), M(열)입력
	int x, y, d;
	cin >> x >> y >> d; //서 있는 위치, 바라보는 방향
	visit[x][y] = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	while (true) {
		int turn = 0;
		while (turn < 4) {//네 방향을 모두 봤으면 나감
			d++; //현재기준으로 왼쪽방향으로 틀기
			if (d > 3) d = d % 4;
			int nx = x + dx[d];
			int ny = y + dy[d];
			if (nx > 0 && nx < n && ny >0 && ny < m && map[nx][ny] == 0 && !visit[nx][ny]) {
				x = nx;
				y = ny;
				answer++;
				visit[nx][ny] = true;
				turn = 0; //새로 이동했으니 현위치에서의 turn 횟수 초기화
			}
			else {
				turn++;
			}
		}
		//네바퀴 다 돈 뒤 뒤로 갈 수 있는가
		//뒤로가기 : 북(0) -> 남(2) , 동(1) -> 서(3)
		d = (d + 2) % 4;
		int nx = x + dx[d];
		int ny = y + dy[d];
		if (map[nx][ny] == 0 && !visit[nx][ny]) {
			x = nx; y = ny; //뒤로 이동
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