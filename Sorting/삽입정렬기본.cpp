#include <iostream>

using namespace std;

int n = 8;
int arr[10] = { 4, 3, 2, 10, 12, 1, 5, 6 };

int main(void) {
	for (int i = 1; i < n; i++) { //두 번째 원소부터
		for (int j = i; j > 0; j--) {
			if (arr[j] < arr[j - 1]) {
				swap(arr[j], arr[j - 1]);
			}
			else break;
		}
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

}