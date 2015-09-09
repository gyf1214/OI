//Created At: Wed Aug 26 12:29:05 CST 2015
//orz zyx
//ntr czr
//Author: gyf

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define clr(i, a) memset(i, (a), sizeof(i))
#define infi 1000000000000000000LL
#define mm 100005
using namespace std;

typedef long long ll;

struct Node
{
    int k, st;
}s[mm];

int top, n, p;
ll a[mm], f[mm], l;

ll add(ll a, ll b) {
    double t = (double)a + (double)b;
    if (t > infi) {
        return infi;
    } else {
        if (a + b > infi) {
            return infi;
        } else {
            return a + b;
        }
    }
}

ll mul(ll a, ll b) {
    double t = (double)a * (double)b;
    if (t > infi) {
        return infi;
    } else {
        if (a * b > infi) {
            return infi;
        } else {
            return a * b;
        }
    }
}

ll power(ll a) {
    a = a > 0 ? a : -a;
    ll ans = 1;
    rep(i, 1, p) {
        ans = mul(ans, a);
    }
    return ans;
}

ll cost(int i, int j) {
    return add(f[i], power(a[j] - a[i] + (ll)(j - i - 1) - l));
}

void pre() {
    scanf("%d%lld%d", &n, &l, &p);
    a[0] = 0;
    char str[40];
    rep(i, 1, n) {
        scanf("%s", str);
        a[i] = a[i - 1] + strlen(str);
    }
}

void calc(int i) {
    int l = 0, r = top;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (s[m].st <= i) {
            l = m;
        } else {
            r = m;
        }
    }
    f[i] = cost(s[l].k, i);
    r = n;
    while (s[top - 1].st > i &&
        cost(s[top - 1].k, s[top - 1].st) > cost(i, s[top - 1].st)) {
        --top;
        r = s[top].st - 1;
    }
    l = s[top - 1].st;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (cost(s[top - 1].k, m) > cost(i, m)) {
            r = m;
        } else {
            l = m;
        }
    }
    if (r - l == 1) {
        s[top].k = i;
        s[top++].st = r;
    }
}

void work() {
    top = 0;
    f[0] = 0;
    s[top].k = 0;
    s[top++].st = 0;
    rep(i, 1, n) {
        calc(i);
    }
    if (f[n] <= infi) {
        printf("%lld\n", f[n]);
    } else {
        printf("Too hard to arrange\n");
    }
    printf("--------------------\n");
}

int main() {

    int t;
    scanf("%d", &t);
    rep(i, 1, t) {
        pre();
        work();
    }

	fclose(stdin);
	fclose(stdout);
	return 0;
}

