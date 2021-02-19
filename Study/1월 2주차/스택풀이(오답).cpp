#include <iostream>
#include <stack>
using namespace std;

int h, w, ans;
int map[500][500];
stack <int> s;

int main() {
	cin >> h >> w;
	for (int i = 0; i < w; i++) {
		int x;
		cin >> x;
		for (int j = 0; j < x; j++) {
			map[j][i] = 1;
		}
	}

	for (int i = 0; i < h; i++) {
		
		for (int j = 0; j < w; j++) {
			if (map[i][j] == 0) {
				if (s.empty()) continue;
				s.push(0);
			}
			else { // 1ÀÏ ¶§
				if (!s.empty() && s.top() == 1) continue;
				else if (s.empty()) s.push(1);
				else if (s.top() == 0) {
					while (!s.empty()) {
						int top = s.top();
						s.pop();
						if (top == 0)
							ans++;
					}
				}
			}

		}
		while (!s.empty()) {
			s.pop();
		}

	}
	cout << ans;
	
}