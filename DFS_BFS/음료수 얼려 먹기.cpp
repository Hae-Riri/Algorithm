#include <iostream>

using namespace std;

int n, m;
int map[1000][1000];

//DFS로 특정 노드 방문 후 연결된 모든 노드 방문
bool dfs(int x, int y) {
	if (x <= -1 || x >= n || y <= -1 || y >= m) {
		return false;
	}
	if (map[x][y] == 0) {//방문을 안했다면
		map[x][y] = 1;
		//상하좌우 위치들 모두 재귀 호출
		dfs(x - 1, y);
		dfs(x + 1, y);
		dfs(x, y - 1);
		dfs(x, y + 1);
		return true; //상하좌우 연관 위치들 모두 호출 했다면 true 리턴
	}
	return false;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf_s("%1d", &map[i][j]); //한글자씩 입력받기
		}
	}
	//모든 노드에 음료수 채우기
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dfs(i, j)) { //true가 리턴되었다면 한 뭉치를 돈 것이므로 +1
				ans++;
			}
		}
	}
	cout << ans;
}