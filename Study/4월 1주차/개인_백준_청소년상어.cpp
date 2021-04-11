#include <iostream>
#include <vector>
using namespace std;

struct fish {
	int x, y, d, n;
	fish(int x, int y, int d, int n) : x(x), y(y), d(d), n(n) {};
};

const int dy[] = { 1,-1,0,1,1,1,0,-1 };
const int dx[] = { 0,-1,-1,-1,0,1,1,1 };

bool isRange(int x, int y) {
	return y >= 0 && x >= 0 && x < 4 && y < 4;
}

int solve(int x, int y, vector<vector<int>>field, vector<fish>fishes) {
	//x, y�� �����ġ
	int ret, d;
	fish& eaten = fishes[field[x][y]];
	d = eaten.d;//���� ����
	ret = eaten.n;

	//���� ������ڸ� -> ��ĭ ����(-1)��
	eaten.d = -1;
	field[x][y] = -1;

	//��� ����� �̵�
	for (fish& f : fishes) {
		if (f.d == -1) continue; //�̹� ���� ������ �н�

		bool fail = false;
		int nx, ny, fd = f.d;
		while (true) {
			nx = x + dx[f.d];
			ny = y + dy[f.d];

			//�̵� �����ϴٸ�(��� ���̸鼭 �� �ƴѻ���)
			if (isRange(nx, ny) && (ny != y ||  nx != x)) break;

			if (++f.d > 7) f.d = 0;

			if (f.d == fd) {//�̵��� ���� ���� ó������ ���ƿԴٸ�
				fail = true;
				break;
			}
		}

		if (fail) continue;

		if (field[nx][ny] != -1) {//�̵� �����ѵ� �װ� ��ĭ�� �ƴ� �ٸ� �������
			//��ġ����
			fishes[field[nx][ny]].x = f.x;
			fishes[field[nx][ny]], y = f.y;
		}
		field[f.x][f, y] = field[nx][ny];
		field[nx][ny] = f.n - 1;
		f.x = nx;
		f.y = ny;
	}

	//������ �̵��� �������� ����̵� & ��Ʈ��ŷ
	int nx = x; int ny = y; //���������ġ ����
	while (true) {
		nx += dx[d];//���� ������� ����
		ny += dy[d];

		if (!isRange(nx, ny)) break;
		if (field[nx][ny] == -1) continue; //��ĭ�̸� �Ѿ

		ret = max(ret, eaten.n + solve(nx, ny, field, fishes));
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<fish> fishes(16, fish(0, 0, 0, 0));
	vector<vector<int>> field(4, vector<int>(4));

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int n, d; cin >> n >> d;
			fishes[n - 1].x = i;
			fishes[n - 1].y = j;
			fishes[n - 1].d = d - 1;
			fishes[n - 1].n = n;
			field[i][j] = n - 1;
		}
	}

	cout << solve(0, 0, field, fishes);
}