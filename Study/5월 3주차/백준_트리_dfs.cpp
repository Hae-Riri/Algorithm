#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, target, ans, root;
vector<int> tree[50];

void dfs(int node) {
    int child = 0;
    for (int i = 0; i < tree[node].size();i++) {
        int x = tree[node][i];
        if (x == target) continue;
        dfs(x);
        child++;
    }
    if (child == 0) ans++;
}
void init() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x == -1) root = i;
        else {
            //입력받은 값이 i의 부모 노드x
            tree[x].push_back(i);
        }
    }
    cin >> target;
}
int main() {
    init();
    if (target != root) dfs(root);
    cout << ans;
    return 0;
}