#include <iostream>
using namespace std;

//num보다 작은 수의 개수를 리턴
long long getLowerNum(long long n, long long num) {
	long long res = 0;
	for (int i = 1; i <= n; i++) {
		long long q = num / i; long long last = num % i;
		if (q > n)
			res = res + n;
		else if (last == 0)
			res = res + (q - 1);
		else
			res = res + q;
	}
	return res;
}
long long n, k, ans;
int main() {
	scanf_s("%d\n%d", &n, &k);
	long long l = 1;
	long long r = k;
	while (l <= r) {
		long long mid = (l + r) / 2;
		long long lowerNum = getLowerNum(n, mid);
		if (lowerNum <= k - 1) {
			ans = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	cout << ans;
}