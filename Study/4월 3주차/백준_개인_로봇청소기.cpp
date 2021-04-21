#include <iostream>
using namespace std;
int n, m; //��.��
int x, y, d;
int map[50][50];
const int dx[] = {-1, 0, 1, 0}; //�������
const int dy[] = {0, 1, 0, -1 }; //�������� ������ �ڷ� ������
int ret;

void init() {
	cin >> n >> m;
	cin >> x >> y >> d;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
}
int main() {
	init();
	while (true) {
		if (map[x][y] == 0) {
			map[x][y] = 2;
			ret++;
		}
		bool moved = false;	
		for (int i = 0; i < 4; i++) {
			d--;
			if (d < 0) d = 3;
			int nx = x + dx[d];
			int ny = y + dy[d];
			if (map[nx][ny] == 0) {
				x = nx;
				y = ny;
				moved = true;
				break;
			}
		}
		if (moved) continue;//���ڸ����� �ٽ� �����ؾ��ϴϱ�

		//����(������� ������ �� 4���� ��� �����Ŵϱ�)
		//���ο� ���⺯�� nd ������ �߿�!!!! û�ұ� ���� ��ü�� ���Ѱ� �ƴ��ݾ�
		//��� ������ �� ������ û�ұ� ������ �����ؾ� �ϴϱ� �������� �ؾߵ�
		int nd = (d + 2) % 4;
		x += dx[nd];
		y += dy[nd];
		if (map[x][y] == 1) break;
	}
	cout << ret;
	return 0;
}