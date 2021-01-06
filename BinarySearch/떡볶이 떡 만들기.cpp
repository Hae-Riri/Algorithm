#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binarySearch(vector<int>& nums, int n, int m, int start, int end) {
	while (start <= end) {
		int mid = (start + end) / 2; //�� ���ܱ� ���� ����
		cout << "mid : " << mid << " ";
		int rice = 0; //�մ��� ������ ��
		for (int i = 0; i < n; i++) {
			if(nums[i] > mid)
				rice = rice + (nums[i] - mid);
		}
		cout << "rice : " << rice << endl;
		if (m == rice) {
			return mid; //�� ���� ��ȯ
		}
		else if (m < rice) { //�����Ƕ��� ���� �� ���� �� �߷����ϱ� ���̸� ������ �߸� ���� ������.
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	return -1;
}

int m, n;
vector<int> nums;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		nums.push_back(x);
	}
	sort(nums.begin(), nums.end());
	int top = nums[n - 1];

	//�߰����� ��ġ �ޱ�
	int mid = binarySearch(nums, n, m, 0, top);
	cout << mid << endl;

}