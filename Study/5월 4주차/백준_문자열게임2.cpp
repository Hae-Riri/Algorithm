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
			//'� ����'�� �� ���ɼ��� �ִ� �͵鿡 ���� k�� ��ŭ ���� �� ���� ����
			//start���� start + k -1��° �ε��������� k����. k���� ������ �ε����� ������ �ֱ�
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