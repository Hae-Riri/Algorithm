#include <iostream>
#define MAX_VALUE 9
using namespace std;

int n = 10;

//모든 원소의 값이 0보다 크거나 같다고 가정함 (인덱스로 쓰여야 하니까)
int arr[10] = { 5, 2, 5, 3, 6, 1, 5, 3, 9, 6 };

//모든 범위를 포함하는 배열 선언(모든 값은 0으로 초기화)
int cnt[MAX_VALUE + 1]; //인덱스 값 중 MAX는 9지만 배열 크기는 10임

int main(void) {
	for (int i = 0; i < n; i++) {
		cnt[arr[i]] += 1; // 각 데이터를 만나면 해당 인덱스 값을 증가시킴
	}
	for (int i = 0; i <= MAX_VALUE; i++) {
		for (int j = 0; j < cnt[i]; j++) {
			cout << i << ' '; //등장한 횟수만큼 인덱스를 출력
		}
	}

}