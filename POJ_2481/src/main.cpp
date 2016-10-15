//Created At: Sat Oct 15 20:03:40 CST 2016
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
#define mm 100010
#define lb(x) ((x) & (-(x)))
using namespace std;

struct Node {
    int s, e, i;

    inline bool operator <(const Node &other) const {
        return e > other.e || (e == other.e && s < other.s);
    }

    inline bool operator ==(const Node &other) const {
        return e == other.e && s == other.s;
    }
}a[mm];

int s[mm], n;
int ans[mm];

void add(int x, int y) {
    for (; x < mm; x += lb(x)) s[x] += y;
}

int sum(int x) {
    int ans = 0;
    for (; x > 0; x -= lb(x)) ans += s[x];
    return ans;
}

bool pre() {
    scanf("%d", &n);
    if (!n) return false;
    rep(i, 0, n - 1) {
        scanf("%d%d", &a[i].s, &a[i].e);
        a[i].i = i;
    }
    sort(a, a + n);
    return true;
}

void work() {
    clr(s, 0);
    rep(i, 0, n - 1) {
        if (i > 0 && a[i] == a[i - 1]) {
            ans[a[i].i] = ans[a[i - 1].i];
        } else {
            ans[a[i].i] = sum(a[i].s + 1);
        }
        add(a[i].s + 1, 1);
    }
    rep(i, 0, n - 1) printf("%d%c", ans[i], i == n - 1 ? '\n' : ' ');
}

int main() {
    while(pre()) work();

    fclose(stdin);
    fclose(stdout);
    return 0;
}
