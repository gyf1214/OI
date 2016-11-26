//Created At: Sat Nov 26 11:49:23 CST 2016
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
#define infi 0x7FFFFFFF
#define mm 3000
using namespace std;

struct Node {
    int x, y, val;

    bool operator <(const Node &other) const {
        return val > other.val;
    }
}a[mm];

int n, k;

void pre() {
    n = 1;
    int m, t, x;
    scanf("%d%d%d", &m, &t, &k);
    rep(i, 1, m) rep(j, 1, t) {
        scanf("%d", &x);
        if (x > 0) {
            a[n].x = i;
            a[n].y = j;
            a[n++].val = x;
        }
    }
    sort(a + 1, a + n);
    a[0].x = 0;
    a[0].y = a[1].y;
}

int dist(const Node &a, const Node &b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

void work() {
    int ans = 0;
    rep(i, 1, n - 1) {
        if (k < dist(a[i], a[i - 1]) + a[i].x + 1) break;
        ans += a[i].val;
        k -= dist(a[i], a[i - 1]) + 1;
    }
    printf("%d\n", ans);
}

int main() {
    int t;
    scanf("%d", &t);
    rep(i, 1, t) {
        pre();
        work();
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
