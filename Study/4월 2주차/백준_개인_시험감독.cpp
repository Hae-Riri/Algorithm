#include <iostream>
#define MAX 1000000
using namespace std;

int N, B, C; //시험장 수 만큼 총감독관이 있음
int A[MAX];
long long ret;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	cin >> B >> C;
	ret = N;

	for (int i = 0; i < N; i++) {
		A[i] -= B; //부감독관이 감시할 응시인원
		if (A[i] <= 0) continue;
		int q = A[i] / C; ret += q;
		int l = A[i] % C;
		if (l != 0) ret++;
	}
	cout << ret;
}