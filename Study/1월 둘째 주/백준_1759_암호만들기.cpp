#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	vector<char> v;
	vector<int>pick;
	int l, c;
	cin >> l >> c;
	for (int i = 0; i < c; i++) {
		char x;
		cin >> x;
		v.push_back(x);
		pick.push_back(1);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < l; i++) {
		pick[i] = 0;
	}
	do {
		string s = "";
		for (int i = 0; i < c; i++) {
			if (pick[i] == 0) {
				s = s + v[i];
			}
		}
		int cnt1 = 0;
		int cnt2 = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
				cnt1++;
			else
				cnt2++;
		}
		if (cnt1 < 1 || cnt2 < 2)
			continue;
		cout << s <<'\n';
	} while (next_permutation(pick.begin(), pick.end()));

}