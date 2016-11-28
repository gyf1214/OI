//Created At: Sat Nov 26 20:17:33 CST 2016
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
#define mm 200010
using namespace std;

int a[mm], b[mm];
int n, m;

void build() {
    for (int i = n - 1; i > 0; --i) {
        a[i] = min(a[2 * i], a[2 * i + 1]);
        b[i] = max(a[2 * i], a[2 * i + 1]);
    }
    b[0] = a[1];
}

void print() {
    rep(i, 0, n - 1) {
        printf("%d%c", b[i], i == n - 1 ? '\n' : ' ');
    }
}

void pre() {
    scanf("%d%d", &n, &m);
    rep(i, n, 2 * n - 1) {
        scanf("%d", a + i);
    }
    build();
    print();
}

void modify(int k, int x) {
    for (k /= 2; k > 0; k /= 2) {
        if (b[k] < x) {
            swap(b[k], x);
        }
    }
    b[0] = x;
}

void work() {
    rep(i, 1, m) {
        int k, x;
        scanf("%d%d", &k, &x);
        modify(k + n, x);
        print();
    }
}

int main() {
    pre();
    work();

    fclose(stdin);
    fclose(stdout);
    return 0;
}
