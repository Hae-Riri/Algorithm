#include <iostream>
#include <vector>
using namespace std;

long long n, m, maxTree, h; vector<long long>v;
long long getM(int mid) {
	long long ans = 0;
	for (long long tree : v) {
		if (tree > mid) { //절단기보다 높으면
			ans += (tree - mid);
		}
	}
	return ans;
}
int main() {
	cin >> n >> m;
	for (long long i = 0; i < n; i++) {
		long long x; cin >> x;
		v.push_back(x);
		maxTree = max(maxTree, x);
	}
	long long preMid = 0;
	long long l = 0; long long r = maxTree;
	while (l <= r) {
		long long mid = (l + r) / 2;
		if (m <= getM(mid)) { //잘린 양을 줄여야 해. 즉 절단기를 높여야 해.
			h = mid;
			l = mid + 1;
		}
		else { //절단기를 낮춰야 해
			r = mid - 1;
		}
	}
	cout << h;
	return 0;
}


//6 1
//0 2 0 0 0 2
//
//answer: 1
//output : 2

//4 6
//
//6 6 6 6
//answer : 4
//output : 0