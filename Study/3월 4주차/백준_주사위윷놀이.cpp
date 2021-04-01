#include <iostream>
#include <stdio.h>
using namespace std;

//�ڳʸ��� �ѹ��� �������� 0�� road��
int map[4][22] = {
	{-1, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26,28,30,32,34,36,38,40,0},
	{10, 13,16,19,25, 30, 35, 40, 0},
	{20, 22, 24,25,30,35,40,0},
	{30, 28, 27,26,25,30,35,40,0}
};

int compare[6] = { 16,22,24,26,28,30};

pair<int, int> mal[4]; //�� ���� ��ġ ���� (road, location)
bool arrived[4]; //�� ���� ��������
int turn[10]; //10�� �Ϻ� �̵� ĭ �� ����
int maxScore = -1; //�ִ����� ������ ����

pair<int,int> canMove(int turnIdx, int malIdx) { //�� ��ȣ, mal ��ȣ
	int cur_road = mal[malIdx].first;
	int cur_location = mal[malIdx].second;
	//�������� �Ķ� ��ġ��? (�ڳʸ��� ���� �������鼭 �ٸ� �Ķ��������� ����?)
	if (cur_road == 0) {
		for (int j = 1; j < 4; j++) {
			if (map[cur_road][cur_location] == map[j][0]) {//��� ���� �ؾ���.
				cur_road = j;
				cur_location = 0;
				break;
			}
		}
	}
	//������ �̵��� �ϱ� �������� mal[i]�� �������� �� ��.
	//�� cur_road, cur_location���� ���� next�� ����ϰ�, Ȯ������ �׶� ����.

	//�̵��غ���.
	int next_location = cur_location;
	int move = turn[turnIdx]; //�̵��ؾ� �� ĭ ��
	for(int k= 0; k < move; k++){
		//�� ĭ�� �ű�ٰ� �����ϸ� ����.
		next_location += 1; 
		if (map[cur_road][next_location] == 0) {
			break;
		}
	}
	//�̵��� �� ������ �� �Ŷ�� �ٸ� �� �ִ��� Ȯ�� ���ص� ��
	if (map[cur_road][next_location] == 0) {
		return { cur_road, next_location };
	}
	//�̵��� ���� �ٸ� ���� �ִ��� Ȯ��
	for (int k = 0; k < 4; k++) {
		if (k == malIdx) continue;
		if (map[cur_road][next_location] == map[mal[k].first][mal[k].second]) {
			int num = map[cur_road][next_location];
			for (int i = 0; i < 6; i++) {
				if (num == compare[i]) { //���� ���ϴ� ���ڴ� ��ġ���� ���ؾ� ��
					if (cur_road != mal[k].first || next_location != mal[k].second) {
						return { cur_road, next_location };
					}
					else
						break;
				}
			}
			return { -1, -1 };
		}
		
	}
	return {cur_road, next_location};
}

void dfs(int turnIdx, int& score) {

	if (turnIdx == 10) {
		maxScore = max(score, maxScore);
		return;
	}

	//���� ��������
	for (int i = 0; i < 4; i++) {

		int deTurn = turnIdx;
		int deMal = i;
		
		//�̹� ���� ĭ�� �ִ� ���̴�?
		if (arrived[i]) continue;

		pair<int, int> next = canMove(turnIdx, i);
		//�̵��� �ڸ��� �ٸ� ���� �ִ�?
		if (next.first == -1) continue;

		//�̵� ���� ���� ���� ��ġ�� ���� ���θ� ����
		int pre_road = mal[i].first; 
		int pre_location = mal[i].second;
		bool pre_arrived = arrived[i];

		//�̵��ص� �ȴٸ� -> ���� ���� �̵���Ű��. 
		mal[i] = {next.first, next.second};
		//�̵��� ��ġ�� �����̸� �������� ������Ʈ
		if (map[mal[i].first][mal[i].second] == 0) {
			arrived[i] = true;
		}
		//���� ������Ʈ
		score = score + map[mal[i].first][mal[i].second];

		//�̵��� ���ļ� ������� ������ ���
		dfs(turnIdx + 1, score);
		//����ؼ� ������ �̵��� ���� ����ġ, ������ ����ġ
		score = score - map[mal[i].first][mal[i].second];
		mal[i].first = pre_road;
		mal[i].second = pre_location;
		arrived[i] = pre_arrived;
	}
}

int main() {
	for (int i = 0; i < 10; i++) {
		cin >> turn[i];
	}
	int score = 0;
	dfs(0, score);
	cout << maxScore;
	return 0;
}