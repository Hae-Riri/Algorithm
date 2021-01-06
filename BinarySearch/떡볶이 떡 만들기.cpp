#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binarySearch(vector<int>& nums, int n, int m, int start, int end) {
	while (start <= end) {
		int mid = (start + end) / 2; //현 절단기 설정 높이
		cout << "mid : " << mid << " ";
		int rice = 0; //손님이 가져갈 떡
		for (int i = 0; i < n; i++) {
			if(nums[i] > mid)
				rice = rice + (nums[i] - mid);
		}
		cout << "rice : " << rice << endl;
		if (m == rice) {
			return mid; //현 높이 반환
		}
		else if (m < rice) { //정답의떡에 비해 더 많은 게 잘렸으니까 높이를 높여서 잘릴 떡을 줄이자.
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

	//중간점의 위치 받기
	int mid = binarySearch(nums, n, m, 0, top);
	cout << mid << endl;

}