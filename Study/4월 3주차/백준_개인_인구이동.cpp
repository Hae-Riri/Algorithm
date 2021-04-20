#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#include <cstring>
using namespace std;

int N, L, R;
int A[50][50];
bool visit[50][50];
bool isMoved = false;
bool inRange(int x, int y) {
	return x >= 0 && x < N&& y >= 0 && y < N;
}
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };
void bfs(int x, int y) {
	queue<pair<int, int>> q, uq; //bfs�� ���� �Ϲ�ť�� ������ �Ǿ�� �ϴ� ����ť
	q.push({ x, y });
	uq.push({ x, y });
	visit[x][y] = true;
	int sum = 0, cnt = 0;
	while (!q.empty()) { //bfs�� ���� ���鼭 pop�� �Ǵϱ� ���bfs�� sum, cnt �ƴ� �뵵�θ� ���
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		sum += A[x][y];
		cnt++;
		for (int d = 0; d < 4; d++) {
			int nx = x + dx[d];
			int ny = y + dy[d];
			int sub = abs(A[nx][ny] - A[x][y]);
			if (!visit[nx][ny] && inRange(nx, ny) && sub >= L && sub <= R) {
				visit[nx][ny] = true;
				q.push({ nx, ny });
				uq.push({ nx,ny });
			}
		}
	}
	//����Ǿ��ִ� ����ť�� ���⼭ ó��
	int avg = sum / cnt;
	if (uq.size() > 1) {
		isMoved = true;
		while (!uq.empty()) {
			int x = uq.front().first;
			int y = uq.front().second;
			uq.pop();
			A[x][y] = avg;
		}
	}
}
void printVisit() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << visit[i][j] <<" ";
		}
		cout << "\n";
	}
	cout << "\n";
}
void printA() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << A[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}
int main() {
	int ret = 0;
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> A[i][j];
	
	//bool check= false; //��� ��ȸ�� �������� üũ (���̻� �̵��� �� ���ٸ� �׸��ϱ�)
	do{
		isMoved = false;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visit[i][j]) {
					bfs(i, j);
					//cout << "Ret : " << ret << endl;
					//printVisit();
					//printA();
				}
			}
		}
		if (isMoved) ret++;
		memset(visit, false, sizeof(visit));
	} while (isMoved);//�̹��� �̰� true�� �ȹٲ�Ÿ� �̵��� �����Ŵϱ� ����
	cout << ret;
}