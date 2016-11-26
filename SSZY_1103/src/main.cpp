//Created At: Sat Nov 26 12:05:45 CST 2016
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
#define mm 200
using namespace std;

struct Node {
    char str[mm];
    int val;

    bool operator <(const Node &other) const {
        return val < other.val;
    }
}a[mm];

int n, m;

int main() {
    scanf("%d%d", &n, &m);
    rep(i, 0, m - 1) {
        scanf("%s", a[i].str);
    }

    rep(i, 0, m - 1) {
        a[i].val = 0;
        rep(j, 0, n - 2) rep(k, j + 1, n - 1) {
            if (a[i].str[j] > a[i].str[k]) {
                ++a[i].val;
            }
        }
    }
    sort(a, a + m);
    rep(i, 0, m - 1) {
        printf("%s\n", a[i].str);
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
