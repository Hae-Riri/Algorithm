#include <string>
#include <vector>
#include <iostream>

using namespace std;
vector<int> answer;
bool arr[21]; //1부터 20까지 false
int fact(int n) {
    int num = 1;
    while (n > 1) {
        num *= n;
        n--;
    }
    cout << "num : " << num << endl;
    return num;
}
void getAns(int n, long long k) {
    if (n == 0) {
        return;
    }
    int term = fact(n) / n;
    cout << "term : " << term << endl;
    if (k == 0) {
        for (int i = 1; i <= n; i++) {
            if (!arr[i]) {
                answer.push_back(i);
            }
        }

    }
    int target = k / term;
    int last = k % term;
    if (last > 0) {
        int num = 0;
        for (int i = 1; i <= n; i++) {
            if (arr[i])
                continue;
            num++;
            if (num == target + 1) {
                arr[i] = true;
                answer.push_back(i);
            }
        }
        for (bool i : arr) {
            cout << i << " ";
        }
        cout << endl;
        getAns(n - 1, last);
    }
    else {
        int num = 0;
        for (int i = 1; i <= n; i++) {
            if (arr[i])
                continue;
            num++;
            if (num == target) {
                arr[i] = true;
                answer.push_back(i);
            }
        }
        getAns(n - 1, last);
    }
}

vector<int> solution(int n, long long k) {
    getAns(n, k);
    return answer;
}