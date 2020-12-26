#include <string>
#include <vector>

using namespace std;
int answer = 0;

void dfs(int i, vector<int>& numbers, int sum, int& target) {
    if (i >= numbers.size()) {
        if (sum == target)
            answer++;
        return;
    }
    dfs(i + 1, numbers, sum + numbers[i], target);
    dfs(i + 1, numbers, sum - numbers[i], target);
    return;
}

int solution(vector<int> numbers, int target) {

    dfs(0, numbers, 0, target);
    return answer;
}