//Created At: Mon Dec 26 20:04:52 CST 2016
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
#define mm 150
using namespace std;

typedef long long ll;

struct Mat {
    ll a[mm][mm];
    int n;

    Mat() {
        clr(a, 0);
    }

    Mat(int _n) : n(_n) {
        clr(a, 0);
    }

    ll *operator [](int index) {
        return a[index];
    }

    const ll *operator [](int index) const {
        return a[index];
    }

    Mat operator *(const Mat &b) const {
        Mat ret(n);
        rep(k, 0, n - 1) {
            rep(i, 0, n - 1) rep(j, 0, n - 1) {
                ret[i][j] += a[i][k] * b[k][j];
            }
        }
        return ret;
    }

    Mat operator ^(long long x) const {
        Mat ret(n);
        Mat s(*this);

        rep(i, 0, n - 1) ret[i][i] = 1;
        for (; x; x /= 2) {
            if (x & 1) {
                ret = ret * s;
            }
            s = s * s;
        }
        return ret;
    }
}p;

long long m;
char buf[10];

bool work() {
    int n, k, x, y;
    scanf("%d%lld%d", &n, &m, &k);
    if (!n) return false;
    p.n = n + 1;
    clr(p.a, 0);
    rep(i, 0, n) p[i][i] = 1;
    rep(i, 1, k) {
        scanf("%s%d", buf, &x);
        switch (buf[0]) {
            case 'g':
            ++p[x][0];
            break;
            case 'e':
            rep(i, 0, n) p[x][i] = 0;
            break;
            case 's':
            scanf("%d", &y);
            rep(i, 0, n) swap(p[x][i], p[y][i]);
            break;
        }
    }
    p = p ^ m;
    rep(i, 1, n) printf("%lld%c", p[i][0], i == n ? '\n' : ' ');
    return true;
}

int main() {
    while(work());

    fclose(stdin);
    fclose(stdout);
    return 0;
}
