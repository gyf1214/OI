//Created At: Sat Nov 26 20:01:39 CST 2016
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
#include <queue>
#define rep(i, a, b) for (int _a = (a), _b = (b), i = _a; i <= _b; ++i)
#define clr(i, a) memset(i, (a), sizeof(i))
#define infi 0x7FFFFFFF
#define mm 100010
using namespace std;

int a[mm];
priority_queue<int, vector<int>, greater<int> > pq;
int n, m;

int main() {
    scanf("%d%d", &n, &m);
    rep(i, 0, n - 1) {
        scanf("%d", a + i);
    }
    int x;
    rep(i, 0, m - 1) {
        scanf("%d", &x);
        pq.push(x);
    }
    rep(i, 0, n - 1) {
        if (pq.empty()) break;
        x = pq.top();
        pq.pop();
        printf("%s%d", i == 0 ? "" : " ", x);
        if (a[i] >= x) pq.push(a[i]);
    }
    putchar('\n');

    fclose(stdin);
    fclose(stdout);
    return 0;
}
