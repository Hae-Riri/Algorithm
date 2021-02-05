#include <iostream>
using namespace std;

int map[2][100002];
int t, n;
int main() {

	cin >> t;
	while (t > 0) {
		cin >> n;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j + 2];
			}
		}

		for (int j = 2; j < n + 2; j++) {
			for (int i = 0; i < 2; i++) {
				if (i == 0) {
					map[i][j] += max(map[i + 1][j - 2], map[i + 1][j - 1]);
				}
				else {
					map[i][j] += max(map[i - 1][j - 2], map[i - 1][j - 1]);
				}
			}
		}
		cout << max(map[0][n + 1], map[1][n + 1]) << "\n";
		t--;
	}

	return 0;
}