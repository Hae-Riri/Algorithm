#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    int heavy = people.size() - 1;
    int light = 0;
    while (light <= heavy) {
        if (people[heavy] + people[light] <= limit) {
            heavy--;
            light++;
        }
        else {
            heavy--;
        }
        answer++;
    }
    return answer;
}