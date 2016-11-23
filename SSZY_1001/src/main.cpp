//Created At: Wed Nov 23 14:14:34 CST 2016
//orz zyx
//ntr czr
//Author: gyf

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i, a, b) for (int _a = (a), _b = (b), i = _a; i <= _b; ++i)
#define clr(i, a) memset(i, (a), sizeof(i))
#define infi 0x7FFFFFFF
#define sqr(x) ((x)*(x))
#define mm 200
using namespace std;

struct Node {
    double d[3];
}a[mm];

typedef pair<int, int> pii;

pii b[mm];

double calc(const pii &x) {
    double ret = .0;
    rep(i, 0, 2) ret += sqr(a[x.first].d[i] - a[x.second].d[i]);
    return sqrt(ret);
}

bool cmp(const pii &x, const pii &y) {
    double xx = calc(x);
    double yy = calc(y);
    return xx > yy || (xx == yy && x < y);
}

void print(const Node &x) {
    printf("(%.0lf,%.0lf,%.0lf)", x.d[0], x.d[1], x.d[2]);
    return;
}

int main() {
    int n;
    scanf("%d", &n);
    rep(i, 0, n - 1) rep(j, 0, 2) scanf("%lf", &a[i].d[j]);
    int m = 0;
    rep(i, 0, n - 2) rep(j, i + 1, n - 1) {
        b[m++] = make_pair(i, j);
    }
    sort(b, b + m, cmp);
    rep(i, 0, m - 1) {
        print(a[b[i].first]);
        putchar('-');
        print(a[b[i].second]);
        printf("=%.2lf\n", calc(b[i]));
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
