#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    int deleteNum = k;
    int deleteNow = 0;
    answer += number[0];
    for (int i = 1; i < number.size(); i++) {
        int num = number[i] - '0';
        while (num > answer.back() - '0' && deleteNow < deleteNum && answer.length() > 0) {
            answer = answer.substr(0, answer.size() - 1);
            deleteNow++;
        }
        answer += number[i];
    }
    while (deleteNow < deleteNum) {
        answer = answer.substr(0, answer.size() - 1);
        deleteNow++;
    }
    return answer;
}