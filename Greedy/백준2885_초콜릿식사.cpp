#include <iostream>
using namespace std;

int main() {
	int k;
	cin >> k;
	int size = 1;
	while (1) {
		if (k <= size)
			break;
		size *= 2;
	}
	cout << size<<" ";
	int cnt = 0;
	if (size == k) {
		cout << 0;
		return 0;
	}
	while (k > 0) {
		size /= 2;
		if (k - size >= 0) {
			k -= size;
		}
		cnt++;
	}
	cout << cnt;
	return 0;
}