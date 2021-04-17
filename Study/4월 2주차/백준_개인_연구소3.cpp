#include <iostream>
#include <queue>
#define INF 987654321
using namespace std;
int N, M, ret;
int map[50][50];
int virus_size = 0;
struct info {
	int x, y, time;
};
info viruses[10] = { 0, }; //바이러스들의 좌표와 시간 저장, 나중에 queue에 
//바이러스가 퍼진 좌표랑 시간을 쓸거라서! 
int bfs(int pick[]) {
	//빈칸 수 세기
	int empty_count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 0) ++empty_count;
		}
	}

	int visit[50][50] = { 0, };
	queue<info> q;

	//pick배열에 있는 M개의 활성 바이러스들을 미리 넣어두기
	for (int i = 0; i < M; i++) {
		q.push(viruses[pick[i]]);
		visit[viruses[pick[i]].x][viruses[pick[i]].y] = 1;
	}
	const int dx[] = { -1,1,0,0 };
	const int dy[] = { 0, 0, -1, 1 };
	while (!q.empty()) {
		info cur = q.front();
		q.pop();
		if (map[cur.x][cur.y] == 0) --empty_count;
		if (empty_count == 0) return cur.time;
		info next;
		next.time = cur.time + 1;
		for (int dir = 0; dir < 4; dir++) {
			next.x = cur.x + dx[dir];
			next.y = cur.y + dy[dir];
			if (next.x < 0 || next.x >N - 1 || next.y < 0 || next.y > N - 1) continue;
			if (visit[next.x][next.y] == 0 && map[next.x][next.y] != 1) { //비활성인 곳도 퍼뜨릴 수 있는 곳이니까 0을 찾는 게 아니라 1이 아닌 걸 찾아야해!
				visit[next.x][next.y] = 1;
				q.push(next);
			}
		}
	}
	//empty_count가 0이 된 적이 없다면
	return INF;
}
void dfs(int last_pick, int pick_count, int pick[]) {
	if (pick_count == M) {
		int time = bfs(pick);
		if (time < ret) ret = time;
		return;
	}
	for (int i = last_pick + 1; i < virus_size; ++i) {
		pick[pick_count] = i;
		dfs(i, pick_count + 1, pick);
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				viruses[virus_size].x = i;
				viruses[virus_size].y = j;
				viruses[virus_size].time = 0;
				++virus_size;
			}
		}
	}
	ret = INF;
	//select and get time
	int pick[10] = { 0 };
	dfs(-1, 0, pick); //마지막 pick된 인덱스, 지금까지 뽑힌 개수, pick배열
	cout << (ret == INF ? -1 : ret);
}