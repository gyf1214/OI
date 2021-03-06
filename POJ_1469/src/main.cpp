//Created At: Fri Dec 16 20:38:38 CST 2016
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
#define mm 400
using namespace std;

bool vis[mm], map[mm][mm];
int match[mm];
int n, p;

bool find(int x) {
    rep(y, 1, n) {
        if (map[x][y] && !vis[y]) {
            vis[y] = true;
            if (!match[y] || find(match[y])) {
                match[y] = x;
                return true;
            }
        }
    }
    return false;
}

bool work() {
    clr(map, 0);
    scanf("%d%d", &p, &n);
    clr(match, 0);
    rep(i, 1, p) {
        int x, y;
        scanf("%d", &x);
        rep(j, 1, x) {
            scanf("%d", &y);
            map[i][y] = true;
        }
    }
    rep(i, 1, p) {
        clr(vis, 0);
        if (!find(i)) return false;
    }
    return true;
}

int main() {
    int t;
    scanf("%d", &t);
    rep(i, 1, t) {
        printf("%s\n", work() ? "YES" : "NO");
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
