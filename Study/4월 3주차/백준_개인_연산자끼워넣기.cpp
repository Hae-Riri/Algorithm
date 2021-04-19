#include <iostream>
#define INF 1000000000
#define MINUS_INF -1000000000
using namespace std;

int maxRes = MINUS_INF, minRes = INF;
int N;
int A[11];
int cnt[4]; //���� ���� ���� �������� ���� ����
int pick[10]; //pick�� ���� N-1���� ����

void print() {
	cout <<"�̰� ���� cnt"<< endl;
	for (int i = 0; i < 4; i++) {
		cout << cnt[i] << " ";
	}
}
void update(int pick[]) {
	int ans = A[0]; int idx = 1;
	for (int i = 0; i < N - 1; i++) {
		if (pick[i] == 0) { //����
			ans = ans + A[idx];
		}
		else if (pick[i] == 1) {
			ans = ans - A[idx];
		}
		else if (pick[i] == 2) {
			ans = ans * A[idx];
		}
		else if (pick[i] == 3) {
			ans = ans / A[idx];
		}
		idx++;
	}
	maxRes = max(ans, maxRes);
	minRes = min(ans, minRes);
}
void dfs(int cur, int count, int pick[]) {
	if (count == N - 1) {
		update(pick);
		return;
	}
	for (int i =0; i < 4; i++) { //4�� ���� �߿� ����
		if (cnt[i] <= 0) continue;
		pick[count] = i;
		cnt[i]--;
		dfs(i, count + 1,pick);
		cnt[i]++;
	}
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> cnt[i];
	}
	dfs(0, 0, pick);
	cout << maxRes << "\n"<<minRes<<"\n";
	return 0;
}