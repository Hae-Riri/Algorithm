#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int t, k;
string w;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> t;
	while (t--) {
		cin >> w;
		cin >> k;
		vector<int> alpha[26];
		vector<int> cand;
		for (int i = 0; i < w.size(); i++) alpha[w[i] - 'a'].push_back(i);
		for (int i = 0; i < 26; i++) {
			if (alpha[i].size() < k) continue;
			//'어떤 문자'가 될 가능성이 있는 것들에 대해 k개 만큼 세서 그 간격 세기
			//start부터 start + k -1번째 인덱스까지가 k개임. k개의 문자의 인덱스를 따져서 넣기
			for (int j = 0; j + k - 1 < alpha[i].size(); j++) {
				cand.push_back(alpha[i][j + k - 1] - alpha[i][j] + 1);
			}
		}
		if (cand.size() == 0) cout << "-1\n";
		else cout << *min_element(cand.begin(), cand.end()) 
			<< " " << *max_element(cand.begin(), cand.end()) << "\n";
	}
	return 0;
}