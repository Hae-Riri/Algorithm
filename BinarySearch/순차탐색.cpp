#include <iostream>
#include <vector>
#include <string>
using namespace std;

int sequantialSearch(int n, string target, vector<string> arr) {
	//��� ���� �ϳ��� Ȯ��
	for (int i = 0; i < n; i++) {
		if (arr[i] == target) {
			return i + 1; //�� ��ġ ��ȯ(�ε������� �ϳ� ũ��)
		}
	}
	return -1; //ã�� ���ϸ� -1 ��ȯ
}

int n; //���Ұ���
string target;
vector<string> arr;

int main(void) {
	cout << "������ ���� ������ �Է��� ���� �� ĭ ��� ã�� ���ڿ��� �Է��ϼ���. " << '\n';
	cin >> n >> target;

	cout << "�ռ� ���� ���� ������ŭ ���ڿ��� �Է��ϼ���. ������ ���� �� ĭ���� �մϴ�." << "\n";
	for (int i = 0; i < n; i++) {
		string x;
		cin >> x;
		arr.push_back(x);
	}

	//���� Ž�� ��� ���
	cout << sequantialSearch(n, target, arr) << "\n";

}