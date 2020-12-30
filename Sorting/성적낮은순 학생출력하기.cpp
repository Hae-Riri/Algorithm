#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Student {
public:
	string name;
	int score;
	bool operator<(Student& student) {
		return this -> score < student.score;
	}
};

int main(void) {
	int n;
	cin >> n;
	vector<Student>v;
	for (int i = 0; i < n; i++) {
		string name; int score;
		cin >> name >> score;
		v.push_back({name, score});
	}

	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		cout << v[i].name<<' ';
	}
}