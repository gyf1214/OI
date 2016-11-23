//Created At: Wed Nov 23 14:29:18 CST 2016
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

int n, k;
int a[mm];

int main() {
    scanf("%d%d", &n, &k);
    rep(i, 1, n) {
        scanf("%d", a + i);
    }
    sort(a + 1, a + n + 1);
    printf("%d\n", a[k]);

    fclose(stdin);
    fclose(stdout);
    return 0;
}
