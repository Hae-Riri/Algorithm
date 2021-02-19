#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s;
int ans;
bool isLuck() {
    for (int i = 1; i < s.size(); i++) {
        if (s[i - 1] == s[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    cin >> s;
    sort(s.begin(), s.end());
    do {
        if (isLuck())
            ans++;
    } while (next_permutation(s.begin(), s.end()));

    cout << ans;
    return 0;
}
