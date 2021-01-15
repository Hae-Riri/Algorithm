#include <iostream>
#include <vector>
using namespace std;

int h, w, ans;
vector<int>v;
int main() {
	cin >> h >> w;
	for (int i = 0; i < w; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	for (int i = 1; i < w - 1; i++) {
		int left = 0; int right = 0;
		//¿ÞÂÊ
		for (int j = 0; j <= i - 1; j++) {
			left = max(left, v[j]);
		}
		//¿À¸¥ÂÊ
		for (int j = i + 1; j < w; j++) {
			right = max(right, v[j]);
		}
		int h = min(right, left);
		int rain = h - v[i];
		if(rain > 0)
			ans = ans + rain;
	}
	cout << ans;
}