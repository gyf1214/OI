//Created At: Fri Dec 16 20:14:52 CST 2016
//orz zyx
//ntr czr
//Author: gyf

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i, a, b) for (int _a = (a), _b = (b), i = _a; i <= _b; ++i)
#define clr(i, a) memset(i, (a), sizeof(i))
#define infi 0x7FFFFFFF
#define mm 40
using namespace std;

bool map[mm][mm], vis[mm][mm];
int match[mm][mm];
int m, n;
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};

bool find(int x, int y) {
    rep(k, 0, 3) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (map[nx][ny] && !vis[nx][ny]) {
            vis[nx][ny] = true;
            bool flag = true;
            int t = match[nx][ny] - 1;
            if (t >= 0) {
                int sx = nx - dx[t];
                int sy = ny - dy[t];
                flag = find(sx, sy);
            }
            if (flag) {
                match[nx][ny] = k + 1;
                return true;
            }
        }
    }
    return false;
}

bool work() {
    int k, x, y;
    clr(map, 0);
    clr(match, 0);
    scanf("%d%d%d", &n, &m, &k);
    rep(i, 1, n) rep(j, 1, m) map[i][j] = true;
    rep(i, 1, k) {
        scanf("%d%d", &x, &y);
        map[y][x] = false;
    }
    int ans = 0;
    rep(i, 1, n) rep(j, 1, m) if (map[i][j] && (i + j) % 2 == 0) {
        clr(vis, 0);
        if (!find(i, j)) return false;
        ++ans;
    }
    return 2 * ans == (n * m - k);
}

int main() {
    printf("%s\n", work() ? "YES" : "NO");

    fclose(stdin);
    fclose(stdout);
    return 0;
}
