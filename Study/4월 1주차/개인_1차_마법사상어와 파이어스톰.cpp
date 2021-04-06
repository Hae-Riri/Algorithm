#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int n, q, m_size;
int map[64][64];
int visit[64][64];
int melting[64][64];
vector<int> l_sizes; //한 변의 길이 2^L을 저장

//상하좌우
int dx[4] = { -1, +1, 0, 0 };
int dy[4] = { 0, 0, -1, +1 };

int dfs(int i, int j) {
	visit[i][j] = true;
	int ret = 1;
	for (int dir = 0; dir < 4; dir++) {
		int nx = i + dx[dir];
		int ny = j + dy[dir];
		if (nx >= 0 && nx < m_size && ny >= 0 && ny < m_size
			&& !visit[nx][ny] && map[nx][ny] > 0) {
			ret += dfs(nx, ny);
		}
	}
	return ret;
}

void melt() {

	for (int i = 0; i < m_size; i++) {
		for (int j = 0; j < m_size; j++) {
			int cnt = 0;
			for (int dir = 0; dir < 4; dir++) {
				int nx = i + dx[dir];
				int ny = j + dy[dir];
				if (nx >= 0 && nx < m_size && ny >= 0 && ny < m_size) {
					if (map[nx][ny] > 0)
						cnt++;
				}
			}
			if (cnt < 3) {
				//여기서 녹여버리면 다음부터는 녹여진대로 적용이 되니까
				//따로 저장해서 원래의 상태에서의 cnt를 세야 함.
				melting[i][j] = true;
			}
		}
	}
	for (int i = 0; i < m_size; i++) {
		for (int j = 0; j < m_size; j++) {
			if (melting[i][j]) {
				map[i][j]--;
				melting[i][j] = false;
			}
		}
	}


}

void rotate(vector<vector<int>>& rotated, int x, int y, int l_size) {
	//x, y 부터 양쪽으로 l_size만큼 map을 읽어서 rotated를 업뎃
	//l_size만큼의 tmp 생성
	vector<int> v(l_size);
	vector<vector<int>> tmp;
	for (int i = 0; i < l_size; i++) {
		tmp.push_back(v);
	}

	//tmp를 작성 (회전했을때의 부분배열)
	int tmp_x = 0, tmp_y = 0;
	for (int i = y; i < y + l_size; i++) {
		for (int j = x + l_size - 1; j >= x; j--) {
			tmp[tmp_x][tmp_y] = map[j][i];
			tmp_y++;
		}
		tmp_y = 0;
		tmp_x++;
	}
	//만들어진 부분배열값으로 rotated의 해당 부분 업데이트
	for (int i = 0; i < l_size; i++) {
		for (int j = 0; j < l_size; j++) {
			rotated[x + i][y + j] = tmp[i][j];
		}
	}
}

vector<vector<int>> divide(int q, int m_size) {

	int q_idx = l_sizes.size() - q - 1;
	int l_size = l_sizes[q_idx];

	//반환할 map과 동일한 사이즈의 배열 형성
	vector<int> v(m_size);
	vector<vector<int>> rotated;
	for (int i = 0; i < m_size; i++) {
		rotated.push_back(v);
	}

	//start와 end만 가져다가 map의 일부를 회전시킨 값을 rotated에 저장하기
	for (int i = 0; i < m_size; i += l_size) {
		for (int j = 0; j < m_size; j += l_size) {
			rotate(rotated, i, j, l_size);
		}
	}


	return rotated;
}

int main() {
	cin >> n >> q;
	m_size = pow(2, n); //한변의 길이 저장
	for (int i = 0; i < m_size; i++) {
		for (int j = 0; j < m_size; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < q; i++) {
		int l; cin >> l;
		l_sizes.push_back(pow(2, l));
	}

	while (q > 0) {
		q--;

		//분할로 나눠서 회전시키기
		vector<vector<int>> rotated = divide(q, m_size);
		for (int i = 0; i < m_size; i++) {
			for (int j = 0; j < m_size; j++) {
				map[i][j] = rotated[i][j];
			}
		}

		//얼음 녹이기
		melt();
	}

	//전체 얼음 수 체크
	int ice_cnt = 0;
	for (int i = 0; i < m_size; i++) {
		for (int j = 0; j < m_size; j++) {
			if (map[i][j] > 0) ice_cnt += map[i][j];
		}
	}
	cout << ice_cnt << endl;

	//큰 덩어리의 칸 수 세기
	int ret = 0;
	for (int i = 0; i < m_size; i++) {
		for (int j = 0; j < m_size; j++) {
			if (!visit[i][j] && map[i][j] > 0) {
				ret = max(ret, dfs(i, j));
			}
		}
	}
	cout << ret;
}