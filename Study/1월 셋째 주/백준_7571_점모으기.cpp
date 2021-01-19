#include <iostream>
#include <algorithm>
using namespace std;

int n, m, ans;
int mx, my;
int ax[100000]; int ay[100000];
void init() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> ax[i] >> ay[i];
	}
	sort(ax, ax + m);
	sort(ay, ay + m);
	mx = ax[m / 2];
	my = ay[m / 2];
}

int main() {

	init();
	for (int i = 0; i < m; i++) {
		ans += abs(mx - ax[i]) + abs(my - ay[i]);
	}
	cout << ans;
}