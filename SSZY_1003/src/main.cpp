//Created At: Wed Nov 23 14:39:03 CST 2016
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
#define mm 1000010
using namespace std;

int pool[mm * 2];
int *a = pool + mm;

int main() {
    int n, t, x;
    scanf("%d%d", &n, &t);
    rep(i, 1, n) {
        scanf("%d", &x);
        ++a[x];
    }
    t = t < 0 ? -t : t;
    int ans = 0;
    rep(i, - mm + 1, mm - 1 - t) {
        if (a[i] > 0 && a[i + t] > 0 && (t != 0 || a[i] > 1)) ++ans;
    }
    printf("%d\n", ans);

    fclose(stdin);
    fclose(stdout);
    return 0;
}
