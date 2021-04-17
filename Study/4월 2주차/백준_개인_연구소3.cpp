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
info viruses[10] = { 0, }; //���̷������� ��ǥ�� �ð� ����, ���߿� queue�� 
//���̷����� ���� ��ǥ�� �ð��� ���Ŷ�! 
int bfs(int pick[]) {
	//��ĭ �� ����
	int empty_count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 0) ++empty_count;
		}
	}

	int visit[50][50] = { 0, };
	queue<info> q;

	//pick�迭�� �ִ� M���� Ȱ�� ���̷������� �̸� �־�α�
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
			if (visit[next.x][next.y] == 0 && map[next.x][next.y] != 1) { //��Ȱ���� ���� �۶߸� �� �ִ� ���̴ϱ� 0�� ã�� �� �ƴ϶� 1�� �ƴ� �� ã�ƾ���!
				visit[next.x][next.y] = 1;
				q.push(next);
			}
		}
	}
	//empty_count�� 0�� �� ���� ���ٸ�
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
	dfs(-1, 0, pick); //������ pick�� �ε���, ���ݱ��� ���� ����, pick�迭
	cout << (ret == INF ? -1 : ret);
}