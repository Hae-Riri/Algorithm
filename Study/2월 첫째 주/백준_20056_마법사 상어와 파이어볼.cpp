#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

struct info {
    int r, c, m, s, d; //행열, 질량, 속도, 방향 
};

vector<info> map[51][51];
vector<info>tmp[51][51];
int n, M, k;
//01234567
int dx[8] = { -1, -1, 0, +1, +1, +1, 0, -1 };
int dy[8] = { 0, +1, +1, +1, 0, -1, -1, -1 };

void init() {
    scanf_s("%d %d %d", &n, &M, &k);
    while (M > 0) {
        int r, c, m, s, d;
        cin >> r >> c >> m >> s >> d;
        if (m == 0)
            continue;
        map[r][c].push_back({ r,c,m,s,d });
        M--;
    }
    return;
}

int setXY(int target) {
    int res = target;
    if (target < 1) {
        target = target * (-1);//양수로 변경
        res = n - (target % n);
    }
    else if (target > n) {
        res = target % n;
    }
    if (res == 0) {
        res = n;
    }
    return res;
}

void moveOne(info i) {
    //s번만큼 방향으로 이동
    int x = i.r + dx[i.d] * i.s;
    int y = i.c + dy[i.d] * i.s;
    x = setXY(x); y = setXY(y);
    tmp[x][y].push_back({ x, y, i.m, i.s, i.d });
    return;
}
void moveAll() {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            tmp[i][j].clear(); tmp[i][j].resize(0);
        }
    }
    //하나씩 이동
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 0; k < map[i][j].size(); k++) {
                moveOne(map[i][j][k]);
            }
        }
    }
    //map 초기화 후, 이동한 모습인 tmp를 map에 복사
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            map[i][j].clear(); map[i][j].resize(0);
            map[i][j] = tmp[i][j];
        }
    }
}

vector<info> divide(int i, int j, int size) { //map에서의 위치
    vector<info> v;
    int ms = 0;//질량합
    int ss = 0; //속력합
    //짝수는 0, 홀수는 1
    int pred, nowd; bool same = true;
    if (map[i][j][0].d % 2 == 0) {
        pred = 0; nowd = 0;
    }
    else {
        pred = 1; nowd = 1;
    }
    while (!map[i][j].empty()) {
        info ni = map[i][j].back();
        ms += ni.m; ss += ni.s;
        if (ni.d % 2 == 0) {
            nowd = 0;
        }
        else {
            nowd = 1;
        }
        if (nowd != pred) {
            same = false;
        }
        pred = nowd;
        map[i][j].pop_back();
    }
    //4개 파이어볼 생성
    int m = ms / 5;
    if (m == 0) {
        return v;
    }
    int s = ss / size;
    int startd = same ? 0 : 1;
    for (int k = 0; k < 4; k++) {
        v.push_back({ i, j, m, s, startd + k * 2 });
    }
    return v;
}

void afterMove() {

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int size = map[i][j].size();
            if (size > 1) {
                vector<info>v = divide(i, j, size);
                map[i][j] = v;
            }
        }
    }
}
int main() {
    init();
    while (k > 0) {
        moveAll();
        afterMove();
        k--;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 0; k < map[i][j].size(); k++) {
                ans += map[i][j][k].m;
            }
        }
    }
    cout << ans;
    return 0;
}