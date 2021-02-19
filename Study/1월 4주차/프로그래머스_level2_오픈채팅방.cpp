#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;
string split(string& s, int& idx) {
    string res = "";
    while (s[idx] != ' ' && idx < s.size()) {
        res += s[idx];
        idx++;
    }
    return res;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<pair<char, string>>v; //�ൿ����, uid
    unordered_map<string, string> um; //uid, name
    for (int i = 0; i < record.size(); i++) {
        string uid, name;
        int idx;
        if (record[i][0] == 'E') {
            idx = 6;
            uid = split(record[i], idx);
            idx++; //���� �پ�ѱ�
            name = split(record[i], idx);
            um[uid] = name;
            v.push_back({ 'E', uid });
        }
        else if (record[i][0] == 'L') {
            idx = 6;
            uid = split(record[i], idx);
            idx++; //����پ�ѱ�
            name = split(record[i], idx);
            v.push_back({ 'L', uid });
        }
        else {
            idx = 7;
            uid = split(record[i], idx);
            idx++;
            name = split(record[i], idx);
            um[uid] = name;
        }
    }
    for (int i = 0; i < v.size(); i++) {
        if (v[i].first == 'E') {
            answer.push_back(um[v[i].second] + "���� ���Խ��ϴ�.");
        }
        else {
            answer.push_back(um[v[i].second] + "���� �������ϴ�.");
        }
    }
    return answer;
}