#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int map[100][100], c_map[100][100];
int N, L, ret;

bool canMakeRoad(int x, int y, int map[][100]) {
	int bottom = map[x][y+1]; //�������̿��� �ϴ� ��
	for (int j = y + 1; j <= y + L ; j++) { //����ġ �������� L���� ������ �־�� ��
		if (map[x][j] != bottom) return false;
	}
	return true;
}
void removeRoadRow(int map[][100]) {
	for (int i = 0; i < N; ++i) {
		bool isBlue = true;
		int before_road = 1; //�����ϴ� ĭ�� �����ؾ� �ϴϱ� 1�� �ʱ�ȭ, ���� �ٴڰ� ���ϴ� ����

		for (int j = 0; j < N-1; ++j) {
			int sub = map[i][j] - map[i][j + 1];
			if (sub == 0) before_road++; //����
			else if (sub == 1) { //���� �� ���� ��
				//������ ���� ���̸�ŭ �������� Ȯ��
				if (!canMakeRoad(i, j, map)) {
					isBlue = false; break;
				}
				else { //����� �ִٸ� ����ġ���� ���η� üũ�� �� ������ �Ѿ��
					j = j + L -1; // j+L�� j+L+1�� ���ؾ��ϴϱ� 
					before_road = 0; //������ �� j+L�� �̹� ���ΰ� ���ϴ� �ڸ��� �����ָ� �ȵ�
				}
			}
			else if (sub == -1) {//�ڰ� �� ���� ��
				if (before_road < L) {
					isBlue = false; break;
				}
				else before_road = 1;
			}
			else if (abs(sub) > 1) {
				isBlue = false; break;
			}
		}
		if (!isBlue) ret--;
	}
}
int main() {
	cin >> N >> L;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> map[i][j];
	ret = 2* N;
	removeRoadRow(map); 
	for (int j = 0; j < N; ++j)
		for (int i = 0; i < N; ++i)
			c_map[j][i] = map[i][j];
	removeRoadRow(c_map);
	cout << ret;
	return 0;
}