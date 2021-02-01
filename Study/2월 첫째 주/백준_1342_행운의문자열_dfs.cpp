#include <iostream>
#include <string>
using namespace std;

string s,tmp;
int ans;
bool visit[11];
int alpha[26];

bool isLuck() {
    for (int i = 1; i < tmp.size(); i++) {
        if (tmp[i - 1] == tmp[i]) {
            return false;
        }
    }
    return true;
}
int fact(int n) {
    int res = 1;
    while (n > 0) {
        res *= n;
        n--;
    }
    return res;
}
void dfs() {
    if (tmp.size() == s.size()) {
        if (isLuck()) {
            ans++;
        }
        return;
    }
    for (int i = 0; i < s.size(); i++) {
        if (!visit[i]) {
            visit[i] = true;
            tmp.push_back(s[i]);
            dfs();
            tmp.pop_back();
            visit[i] = false;
        }
    }
}
int main() {
    cin >> s;
    for (char c : s) {
        alpha[c - 'a']++;
    }
    dfs();
    for (int i = 0; i < 26 ; i++) {
        if (alpha[i] > 1) {
            if (ans > 0) {
                ans /= fact(alpha[i]);
            }
        }
    }
    cout << ans;
    return 0;
}
