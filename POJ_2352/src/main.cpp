//Created At: Tue Oct 4 20:12:06 CST 2016
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
#define mm 40000
#define lb(x) ((x) & (-(x)))
using namespace std;

int s[mm];

void add(int x, int d) {
    for (; x < mm; x += lb(x)) {
        s[x] += d;
    }
}

int query(int x) {
    int ret = 0;
    for (; x; x -= lb(x)) {
        ret += s[x];
    }
    return ret;
}

struct Node {
    int x, y;
    int operator <(const Node &b) const {
        return y < b.y || (y == b.y && x < b.x);
    }
}node[mm];

int n;
int ans[mm];

void pre() {
    scanf("%d", &n);
    rep(i, 0, n - 1) {
        scanf("%d%d", &node[i].x, &node[i].y);
    }
    // sort(node, node + n);
}

void work() {
    clr(s, 0);
    clr(ans, 0);
    rep(i, 0, n - 1) {
        ++ans[query(node[i].x + 1)];
        add(node[i].x + 1, 1);
    }
    rep(i, 0, n - 1) {
        printf("%d\n", ans[i]);
    }
}

int main() {
    pre();
    work();

    fclose(stdin);
    fclose(stdout);
    return 0;
}
