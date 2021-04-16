#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define INF 987654321
int N;
int Mark[20][20];
int A[20][20];

void fill(int r, int c, int value) {
	if (r < 0 || r > N - 1 || c <0 || c > N - 1) return;
	if (Mark[r][c] != 0) return; //경계선을 만났으니 더이상 할 필요가 없어
	//현 위치를 value로 fill하자
	Mark[r][c] = value;
	//사방으로 이동
	fill(r - 1, c, value);
	fill(r + 1, c, value);
	fill(r, c - 1, value);
	fill(r, c + 1, value);
}

int solve() {
	int ret = INF;
	for (int x = 0; x <= N - 3; ++x) {
		for (int y = 1; y <= N - 2; ++y) {
			for (int d1 = 1; x+d1 <= N-2 && y-d1 >= 0 ; ++d1) {
				//틀린원인이 여기임! 조건에 x+d1 <= N-2가 아니라 x+d1+d2<=N-1을 해야 해. 가장 커졌을때에 영향을 주는 것으로 선택.
				//x + dx2와 x+d1+d2 , y-d1+d2와 y+d2가 있었는데 각각 후자와 전자를 택해야 맞는 문제..
				for (int d2 = 1; x+d1+d2 <= N-1 && y+d2 <= N-1 ; ++d2) { 
					//만들어진 상황들에 대해서 인구 수 구하면 돼(항상 초기화)
					memset(Mark, 0, sizeof(Mark));

					//경계선 4개 긋기, d1길이 2개, d2길이 2개 (합쳐도 돼)
					for (int i = 0; i <= d1; ++i)
						Mark[x + i][y - i] = 5;
					for (int i = 0; i <= d2; ++i)
						Mark[x + i][y + i] = 5;
					for (int i = 0; i <= d2; ++i)
						Mark[x + d1 + i][y - d1 + i] = 5;
					for (int i = 0; i <= d1; ++i)
						Mark[x + d2 + i][y + d2 - i] = 5;

					//1,2,3,4 경계선 긋기
					for (int r = 0; r < x; ++r)
						Mark[r][y] = 1;
					for (int c = y + d2+1; c < N; ++c)
						Mark[x + d2][c] = 2;
					for (int c = 0; c < y - d1; ++c)
						Mark[x + d1][c] = 3;
					for (int r = x + d1 + d2 + 1; r < N; ++r)
						Mark[r][y - d1 + d2] = 4;

					//선거구 번호 채우기, 5안에 있는 건 안채워도 돼
					fill(0, 0, 1); 
					fill(0, N - 1, 2); 
					fill(N - 1, 0, 3); 
					fill(N - 1, N - 1, 4);

					//인구 수 세기
					int people[6] = { 0 };
					for (int i = 0; i < N; i++)
						for (int j = 0; j < N; j++)
							people[Mark[i][j]] += A[i][j];
					people[5] += people[0];

					//최소 인구 차 찾기
					int minP = INF, maxP = 0;
					for (int i = 1; i <= 5; i++) {
						minP = min(minP, people[i]);
						maxP = max(maxP, people[i]);
					}
					ret = min(ret, maxP - minP);
				}
			}
		}
	}
	return ret;
}
int main() {
	cin >> N;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> A[i][j];
	cout << solve() << endl;
	return 0;
}