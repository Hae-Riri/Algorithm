#include <string>
#include <vector>

using namespace std;
int ans;

void dfs(vector<int>& numbers, int target, int i, int sum) {
    if (i == numbers.size() - 1) {
        if (sum == target)
            ans++;
        return;
    }
    dfs(numbers, target, i + 1, sum + numbers[i + 1]);
    dfs(numbers, target, i + 1, sum - numbers[i + 1]);
}

int solution(vector<int> numbers, int target) {
    dfs(numbers, target, 0, numbers[0]);
    dfs(numbers, target, 0, -numbers[0]);
    return ans;
}