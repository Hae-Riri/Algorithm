#include <iostream>
using namespace std;

int n = 5; //������ ����
int arr[10] = { 20, 12, 10, 15, 2 };

int main(void) {
	for (int i = 0; i < n; i++) {
		int min_index = i; //���� ���� ���Ұ� �;� �� ��ġ �ε���
		for (int j = i + 1; j < n; j++) {//�ϳ��� ���ϸ鼭 ���� ���� ���� ��ġ ã��
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