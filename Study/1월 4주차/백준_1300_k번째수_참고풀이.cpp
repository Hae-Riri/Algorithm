#include <iostream>
using namespace std;

long long n, k, ans;
int main() {
	scanf("%d\n%d", &n, &k);
	long long l = 1;
	long long r = k;
	while (l <= r) {
		long long cnt = 0;
		long long mid = (l + r) / 2;
		for (int i = 1; i <= n; i++) {
			cnt += min(mid / i, n);
		}
		if (cnt < k) {
			l = mid + 1;
		}
		else { // cnt >= k
			ans = mid;
			r = mid - 1;
		}
	}
	cout << ans;
	return 0;
}