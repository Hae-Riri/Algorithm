#include <iostream>

using namespace std;

int n, m;
int map[1000][1000];

//DFS�� Ư�� ��� �湮 �� ����� ��� ��� �湮
bool dfs(int x, int y) {
	if (x <= -1 || x >= n || y <= -1 || y >= m) {
		return false;
	}
	if (map[x][y] == 0) {//�湮�� ���ߴٸ�
		map[x][y] = 1;
		//�����¿� ��ġ�� ��� ��� ȣ��
		dfs(x - 1, y);
		dfs(x + 1, y);
		dfs(x, y - 1);
		dfs(x, y + 1);
		return true; //�����¿� ���� ��ġ�� ��� ȣ�� �ߴٸ� true ����
	}
	return false;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf_s("%1d", &map[i][j]); //�ѱ��ھ� �Է¹ޱ�
		}
	}
	//��� ��忡 ����� ä���
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dfs(i, j)) { //true�� ���ϵǾ��ٸ� �� ��ġ�� �� ���̹Ƿ� +1
				ans++;
			}
		}
	}
	cout << ans;
}