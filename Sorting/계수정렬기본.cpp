#include <iostream>
#define MAX_VALUE 9
using namespace std;

int n = 10;

//��� ������ ���� 0���� ũ�ų� ���ٰ� ������ (�ε����� ������ �ϴϱ�)
int arr[10] = { 5, 2, 5, 3, 6, 1, 5, 3, 9, 6 };

//��� ������ �����ϴ� �迭 ����(��� ���� 0���� �ʱ�ȭ)
int cnt[MAX_VALUE + 1]; //�ε��� �� �� MAX�� 9���� �迭 ũ��� 10��

int main(void) {
	for (int i = 0; i < n; i++) {
		cnt[arr[i]] += 1; // �� �����͸� ������ �ش� �ε��� ���� ������Ŵ
	}
	for (int i = 0; i <= MAX_VALUE; i++) {
		for (int j = 0; j < cnt[i]; j++) {
			cout << i << ' '; //������ Ƚ����ŭ �ε����� ���
		}
	}

}