#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;

bool compare(int a, int b) {
	return a > b;
}

int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		v.push_back(input);
	}
	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < n; i++) {
		cout << v[i] << ' ';
	}
}