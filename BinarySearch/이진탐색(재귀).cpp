#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& arr, int target, int start, int end) {
	if (start > end) return -1;
	int mid = (start + end) / 2;
	//찾았다면 중간점 인덱스 반환
	if (arr[mid] == target) return mid;
	else if (arr[mid] > target) return binarySearch(arr, target, start, mid - 1);
	else return binarySearch(arr, target, mid + 1, end);
}

int n, target;
vector<int> arr;

int main() {
	//n(원소개수)와 target(찾으려는 값) 입력받기
	cin >> n >> target;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr.push_back(x);
	}

	//이진탐색 수행 결과 출력
	int result = binarySearch(arr, target, 0, n - 1);
	if (result == -1) {
		cout << "원소가 존재하지 않습니다.";
	}
	else {
		cout << result + 1 << '\n'; 
	}

}