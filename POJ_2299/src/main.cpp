//Created At: Sat Oct 15 19:51:54 CST 2016
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
#define mm 500010
#define lb(x) ((x) & (-(x)))
using namespace std;

struct Node {
    int i, x;
    inline bool operator <(const Node &other) const {
        return x < other.x;
    }
}a[mm];

int b[mm], n;
long long s[mm];

void add(int x, long long y) {
    for (; x < mm; x += lb(x)) s[x] += y;
}

long long sum(int x) {
    long long ans = 0;
    for (; x > 0; x -= lb(x)) ans += s[x];
    return ans;
}

bool pre() {
    scanf("%d", &n);
    if (!n) return false;
    rep(i, 0, n - 1) {
        scanf("%d", &a[i].x);
        a[i].i = i;
    }
    sort(a, a + n);
    rep(i, 0, n - 1) {
        b[a[i].i] = i + 1;
    }
    return true;
}

long long work() {
    clr(s, 0);
    long long ans = 0;
    rep(i, 0, n - 1) {
        ans += i - sum(b[i]);
        add(b[i], 1);
    }
    return ans;
}

int main() {
    while (pre()) printf("%lld\n", work());

    fclose(stdin);
    fclose(stdout);
    return 0;
}
