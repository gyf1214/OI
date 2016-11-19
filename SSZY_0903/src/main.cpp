//Created At: Sat Nov 19 19:32:50 CST 2016
//orz zyx
//ntr czr
//Author: gyf

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i, a, b) for (int _a = (a), _b = (b), i = _a; i <= _b; ++i)
#define clr(i, a) memset(i, (a), sizeof(i))
#define infi 0x7F7F7F7F
#define mm 210
using namespace std;

typedef pair<int, int> pii;

int map[mm][mm][4];
pii pool[mm * mm * 4];
pii *q = pool + mm * mm * 2;
int dis[mm][mm];
int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };

bool pre() {
    int n, m;
    int x, y, d, t;
    scanf("%d%d", &m, &n);
    if (m < 0) return false;
    clr(map, 0);
    rep(i, 1, m) {
        scanf("%d%d%d%d", &x, &y, &d, &t);
        for (; t > 0; --t, x += 1 - d, y += d) {
            map[x][y][d] = -1;
            map[x - d][y - 1 + d][d + 2] = -1;
        }
    }
    rep(i, 1, n) {
        scanf("%d%d%d", &x, &y, &d);
        map[x][y][d] = 1;
        map[x - d][y - 1 + d][d + 2] = 1;
    }
    rep(i, 0, mm - 1) {
        map[i][0][0] = -1;
        map[0][i][1] = -1;
        map[i][mm - 1][2] = -1;
        map[mm - 1][i][3] = -1;
    }
    return true;
}

void bfs() {
    int l = 0, r = 0;
    q[r++] = make_pair(0, 0);
    clr(dis, 0x7F);
    dis[0][0] = 0;
    while (l < r) {
        int x = q[l].first;
        int y = q[l++].second;
        rep(d, 0, 3) if (map[x][y][d] != -1) {
            int nx = x + dx[d], ny = y + dy[d];
            if (dis[nx][ny] > dis[x][y] + map[x][y][d]) {
                dis[nx][ny] = dis[x][y] + map[x][y][d];
                if (map[x][y][d]) {
                    q[r++] = make_pair(nx, ny);
                } else {
                    q[--l] = make_pair(nx, ny);
                }
            }
        }
    }
}

int main() {
    while (pre()) {
        bfs();
        double x, y;
        scanf("%lf%lf", &x, &y);
        int xx = floor(x), yy = floor(y);
        xx = xx > mm - 1 ? mm - 1 : xx;
        yy = yy > mm - 1 ? mm - 1 : yy;
        int ans = dis[xx][yy];
        printf("%d\n", ans == infi ? -1 : ans);
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
