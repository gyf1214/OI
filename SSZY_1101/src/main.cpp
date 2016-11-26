//Created At: Sat Nov 26 11:41:19 CST 2016
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
#define mm 50010
using namespace std;

struct Node {
    int index, a, b;
}a[mm];

bool cmp1(const Node &a, const Node &b) {
    return a.a > b.a;
}

bool cmp2(const Node &a, const Node &b) {
    return a.b > b.b;
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    rep(i, 1, n) {
        scanf("%d%d", &a[i].a, &a[i].b);
        a[i].index = i;
    }
    sort(a + 1, a + 1 + n, cmp1);
    sort(a + 1, a + 1 + k, cmp2);
    printf("%d\n", a[1].index);

    fclose(stdin);
    fclose(stdout);
    return 0;
}
