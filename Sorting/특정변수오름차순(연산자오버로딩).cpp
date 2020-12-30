#include <iostream>
#include <algorithm>

using namespace std;

class Student {
public:
    string name;
    int score;
    Student(string name, int score) {
        this->name = name;
        this->score = score;
    }
    //점수가 작은 것 부터
    bool operator <(Student& student) {
        return this->score < student.score;
    }

};

int main(void) {
    Student students[] = {
        Student("구십이", 92),
        Student("구십삽", 93),
        Student("구십구", 99),
        Student("팔십일", 81),
        Student("구십오", 95)
    };

    sort(students, students + 5);
    for (int i = 0; i < 5; i++) {
        cout << students[i].name << ' ';
    }
}