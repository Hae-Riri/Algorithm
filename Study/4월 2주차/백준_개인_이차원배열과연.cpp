#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_TIME 101
using namespace std;
int A[101][101]; //1부터 사용
int r, c, k, r_count, c_count;
int ret = MAX_TIME;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second; //등장 횟수 적은것부터
}
void calculateR() {
	int max_r_size = 0;//가장 큰 행의 크기
	for (int i = 1; i <= r_count; ++i) {//모든 행에 대하여 연산 시작
		int new_r_size = 0; //정렬 후 새로 들어갈 개수
		vector<pair<int, int>> count(101, { 0,0 });
		for (int j = 1; j <= c_count; ++j) {
			if (A[i][j] == 0) continue;
			count[A[i][j]].first = A[i][j];
			count[A[i][j]].second++;
			A[i][j] = 0;
		}
		
		sort(count.begin(), count.end(), cmp); //정렬
		int j = 1; //현재 행의 1번째 숫자부터 하나씩 A에 변화를 줄거야
		for (int k = 1; k < count.size(); k++) {
			if (count[k].second > 0) {
				if (j > 100) break;
				A[i][j] = count[k].first;
				new_r_size++;
				j++;
				if (j > 100) break;
				A[i][j] = count[k].second;
				new_r_size++;
				j++;
			}
		}
		if (max_r_size < new_r_size)
			max_r_size = new_r_size;
	}
	c_count = max_r_size;
}
void calculateC() {
	int max_c_size = 0;//가장 큰 열의 크기
	for (int j = 1; j <= c_count; j++) {//모든 열에 대한 연산 시작
		int new_c_size = 0;
		vector<pair<int, int>>count(101, { 0,0 });
		for (int i = 1; i <= r_count; ++i) {
			if (A[i][j] == 0) continue;
			count[A[i][j]].first = A[i][j];
			count[A[i][j]].second++;
			A[i][j] = 0;
		}
		sort(count.begin(), count.end(), cmp);
		int i = 1; //현재 열의 1번째 숫자부터 하나씩 A에 변화를 줄거야
		for (int k = 1; k < count.size(); k++) {
			if (count[k].second > 0) {
				if (i > 100) break;
				A[i][j] = count[k].first;
				new_c_size++;
				i++;
				if (i > 100) break;
				A[i][j] = count[k].second;
				new_c_size++;
				i++;
			}
		}
		if (max_c_size < new_c_size)
			max_c_size = new_c_size;
	}
	r_count = max_c_size;
}
int solve() {
	int time = 0;
	while (1) {
		if (A[r][c] == k) return time;
		if (time == 100) return time = MAX_TIME;
		if (r_count >= c_count)
			calculateR();
		else
			calculateC();
		time++;
	}
	return MAX_TIME;
}
int main() {
	r_count = 3; c_count = 3;
	cin >> r >> c >> k;
	for (int i = 1; i <= 3; ++i)
		for (int j = 1; j <= 3; ++j)
			cin >> A[i][j];
	ret = solve();
	cout << (ret == MAX_TIME ? -1 : ret) << "\n";
	return 0;
}
/*
디버깅
void printCount(vector<pair<int, int>> count) {
	cout << "정렬한 count배열" << endl;
	for (int i = 1; i < count.size(); i++) {
		if (count[i].second == 0) break;
		cout << "i: " << i << ", first: " <<
			count[i].first << ", second:" << count[i].second << endl;
	}
}
void printA() {
	cout << endl;
	for (int i = 1; i <= r_count; i++) {
		for (int j = 1; j <= c_count; j++) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	cout << "--출력함--" << endl;
}
void printInfo() {
	cout << "r_count :" << r_count << ", c_count:" << c_count << endl;
}
*/