#include <string>
#include <iostream>
#include <queue>
#include <set>
#include <utility>
using namespace std;

string start;
string goal = "123456780";
set<string> visit; //������ Ž���� �������� Ȯ�ο�

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int bfs() {
	queue<pair<string, int>>q; //����������,�̵�Ƚ��
	q.push({ start,0 });
	visit.insert(start);
	while (!q.empty()) {
		string str = q.front().first;
		int move = q.front().second;
		q.pop();
		if (str == goal)
			return move;
		int zeroIndex = str.find('0');
		int x = zeroIndex / 3;
		int y = zeroIndex % 3;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx > -1 && nx<3 && ny>-1 && ny < 3) {
				string nstr = str;//��ġ �ٲ㺼 nstr
				swap(nstr[x * 3 + y], nstr[nx * 3 + ny]); //��ġ�ٲٱ�
				if (visit.find(nstr) == visit.end()) {//�湮�� �� ���ٸ�
					visit.insert(nstr);
					q.push({ nstr,move + 1 });
				}
			}
		}
	}
	return -1;
}
int main() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int a;
			cin >> a;
			start += to_string(a);
		}
	}
	cout << bfs();
	return 0;
}