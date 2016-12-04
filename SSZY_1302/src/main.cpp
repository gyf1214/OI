//Created At: Sun Dec 4 15:03:55 CST 2016
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

int a[mm], b[mm];
int n, m;

void print(int d) {
    static bool x = false;
    printf("%s%d", x ? " " : "", d);
    x = true;
}

void work() {
    int j = 0;
    rep(i, 0, n - 1) {
        for (; j < m && b[j] < a[i]; ++j) {
            print(b[j]);
        }
        if (j < m && a[i] == b[j]) {
            ++j;
        } else {
            print(a[i]);
        }
    }
    for (; j < m; ++j) print(b[j]);
    putchar('\n');
}

void pre() {
    scanf("%d", &n);
    rep(i, 0, n - 1) {
        scanf("%d", a + i);
    }
    scanf("%d", &m);
    rep(i, 0, m - 1) {
        scanf("%d", b + i);
    }
}

int main() {
    pre();
    work();

    fclose(stdin);
    fclose(stdout);
    return 0;
}
