#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    vector<char>v;
    v.push_back('0');
    int deleteNum = k + 1;
    int deleteNow = 0;
    for (int i = 0; i < number.size(); i++) {
        int num = number[i] - '0';
        while (num > v.back() - '0' && deleteNow < deleteNum && !v.empty()) {
            v.pop_back();
            deleteNow++;
        }
        v.push_back(number[i]);
    }
    for (int i = 0; i < v.size(); i++) {
        // answer += to_string(v[i]);
        answer += v[i];
    }
    return answer;
}