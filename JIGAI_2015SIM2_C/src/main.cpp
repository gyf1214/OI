//Created At: Fri Dec 18 15:29:54 CST 2015
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
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define clr(i, a) memset(i, (a), sizeof(i))
#define infi 0x7FFFFFFF
#define mm 10
using namespace std;

int qx, qy, kx, ky, tx, ty;
int dx[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy[] = {1, -1, 0, 1, -1, 0, 1, -1};
bool vis[mm][mm];

void get(int qx, int qy) {
    clr(vis, 0);
    rep(i, 0, 7) {
        int x = qx, y = qy;
        for (;;) {
            vis[x][y] = true;
            x += dx[i];
            y += dy[i];
            if (x < 0 || x >= 8 || y < 0 || y >= 8 ||
                (x == kx && y == ky)) break;
        }
    }
    vis[qx][qy] = false;
}

bool canGet(int x, int y, int qx, int qy) {
    get(qx, qy);
    return vis[x][y];
}

bool valid(int x, int y) {
	return canGet(x, y, qx, qy) &&
		!(x == kx && y == ky);
}

bool checkpos(int x, int y, int tx, int ty) {
    return (tx < 0) || (tx >= 8) || (ty < 0) || (ty >= 8) ||
        (max(abs(tx - kx), abs(ty - ky)) < 2) ||
        canGet(tx, ty, x, y);
}

bool check(int x, int y) {
    rep(i, tx - 1, tx + 1) {
        rep(j, ty - 1, ty + 1) {
            if (!checkpos(x, y, i, j)) return false;
        }
    }
    return true;
}

bool work() {
    char str[3][5];
    scanf("%s%s%s", str[0], str[1], str[2]);
    kx = str[0][0] - 'a';
    ky = str[0][1] - '1';
    qx = str[1][0] - 'a';
    qy = str[1][1] - '1';
    tx = str[2][0] - 'a';
    ty = str[2][1] - '1';
    rep(i, 0, 7) {
        rep(j, 0, 7) {
            if (valid(i, j) && check(i, j)) {
                printf("%c%c\n", i + 'a', j + '1');
                return true;
            }
        }
    }
    return false;
}

int main() {
    if (!work()) printf("no\n");

	fclose(stdin);
	fclose(stdout);
	return 0;
}
