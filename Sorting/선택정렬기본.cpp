#include <iostream>
using namespace std;

int n = 5; //정렬할 개수
int arr[10] = { 20, 12, 10, 15, 2 };

int main(void) {
	for (int i = 0; i < n; i++) {
		int min_index = i; //가장 작은 원소가 와야 할 위치 인덱스
		for (int j = i + 1; j < n; j++) {//하나씩 비교하면서 가장 작은 값의 위치 찾음
			if (arr[min_index] > arr[j]) {
				min_index = j;
			}
		}
		swap(arr[i], arr[min_index]);
	}
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}