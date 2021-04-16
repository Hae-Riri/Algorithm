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
	if (Mark[r][c] != 0) return; //��輱�� �������� ���̻� �� �ʿ䰡 ����
	//�� ��ġ�� value�� fill����
	Mark[r][c] = value;
	//������� �̵�
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
				//Ʋ�������� ������! ���ǿ� x+d1 <= N-2�� �ƴ϶� x+d1+d2<=N-1�� �ؾ� ��. ���� Ŀ�������� ������ �ִ� ������ ����.
				//x + dx2�� x+d1+d2 , y-d1+d2�� y+d2�� �־��µ� ���� ���ڿ� ���ڸ� ���ؾ� �´� ����..
				for (int d2 = 1; x+d1+d2 <= N-1 && y+d2 <= N-1 ; ++d2) { 
					//������� ��Ȳ�鿡 ���ؼ� �α� �� ���ϸ� ��(�׻� �ʱ�ȭ)
					memset(Mark, 0, sizeof(Mark));

					//��輱 4�� �߱�, d1���� 2��, d2���� 2�� (���ĵ� ��)
					for (int i = 0; i <= d1; ++i)
						Mark[x + i][y - i] = 5;
					for (int i = 0; i <= d2; ++i)
						Mark[x + i][y + i] = 5;
					for (int i = 0; i <= d2; ++i)
						Mark[x + d1 + i][y - d1 + i] = 5;
					for (int i = 0; i <= d1; ++i)
						Mark[x + d2 + i][y + d2 - i] = 5;

					//1,2,3,4 ��輱 �߱�
					for (int r = 0; r < x; ++r)
						Mark[r][y] = 1;
					for (int c = y + d2+1; c < N; ++c)
						Mark[x + d2][c] = 2;
					for (int c = 0; c < y - d1; ++c)
						Mark[x + d1][c] = 3;
					for (int r = x + d1 + d2 + 1; r < N; ++r)
						Mark[r][y - d1 + d2] = 4;

					//���ű� ��ȣ ä���, 5�ȿ� �ִ� �� ��ä���� ��
					fill(0, 0, 1); 
					fill(0, N - 1, 2); 
					fill(N - 1, 0, 3); 
					fill(N - 1, N - 1, 4);

					//�α� �� ����
					int people[6] = { 0 };
					for (int i = 0; i < N; i++)
						for (int j = 0; j < N; j++)
							people[Mark[i][j]] += A[i][j];
					people[5] += people[0];

					//�ּ� �α� �� ã��
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