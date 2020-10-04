#include <iostream>
#include <string>
using namespace std;

int main() {
	//L, R, U, D순서
	//x는 행, y는 열
	int dx[4] = {0, 0, -1, +1};
	int dy[4] = {-1, +1, 0, 0};
	char directions[4] = { 'L', 'R', 'U', 'D' };

	int n;
	cin >> n;
	cin.ignore(); //줄바꿈 문자를 인식해서 바로 처리되므로 버퍼를 비워야 다음 줄을 인식할 수 있음
	string plans;	
	//띄어쓰기를 포함하되 줄바꿈 문자 제외하고 통째로 한 줄을 입력받기(string 헤더)
	getline(cin, plans);
	int x = 1; int y = 1;

	for (int i = 0; i < plans.size(); i++) {
		int nx = 0; int ny = 0;
		for (int j = 0; j < 4; j++) {
			if (plans[i] == directions[j]) {
				nx = x + dx[j];
				ny = y + dy[j];
			}
		}
		if (nx <1 || nx >n || ny <1 || ny >n) {
			continue;
		}
		else {
			x = nx; 
			y = ny;
		}
	}
	cout << x << " " << y;
	return 0;
}