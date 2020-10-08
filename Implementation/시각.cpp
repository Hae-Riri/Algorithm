#include <iostream>
#include <string>
using namespace std;

bool check(int h, int m, int s) { //해설만 보고 내가 만든 함수
	string time = "";
	time += to_string(h);
	time += to_string(m);
	time += to_string(s);
	for (char c : time) {
		if (c == '3')
			return true;
	}
	return false;
}
bool check_by_ndb(int h, int m, int s) {//교재 저자의 c++코드
	if (h % 10 == 3 || m / 10 == 3 || m % 10 == 3 || s / 10 == 3 || s % 10 == 3)
		return true;
	return false;
}
int main() {
	int answer = 0;
	int n;
	cin >> n;

	for (int h = 0; h <= n; h++) {
		for (int m = 0; m < 60; m++) {
			for (int s = 0; s < 60; s++) {
				if (check(h, m, s)) answer++;
			}
		}
	}
	cout << answer;
	return 0;
}