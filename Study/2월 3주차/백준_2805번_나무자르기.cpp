#include <iostream>
#include <vector>
using namespace std;

long long n, m, maxTree, h; vector<long long>v;
long long getM(int mid) {
	long long ans = 0;
	for (long long tree : v) {
		if (tree > mid) { //���ܱ⺸�� ������
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
		if (m <= getM(mid)) { //�߸� ���� �ٿ��� ��. �� ���ܱ⸦ ������ ��.
			h = mid;
			l = mid + 1;
		}
		else { //���ܱ⸦ ����� ��
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