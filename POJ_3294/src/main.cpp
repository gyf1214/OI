//Created At: Wed Dec 7 19:09:14 CST 2016
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

int sa[mm], rk[mm], cnt[mm], t1[mm], t2[mm];
int height[mm], n, s[mm];

bool cmp(int *y, int a, int b, int k) {
    int a1 = y[a], b1 = y[b];
    int a2 = a + k >= n ? -1 : y[a + k];
    int b2 = b + k >= n ? -1 : y[b + k];
    return a1 == b1 && a2 == b2;
}

void makeSA() {
    int *x = t1, *y = t2;
    int m = 128;
    clr(cnt, 0);
    rep(i, 0, n - 1) ++cnt[x[i] = s[i]];
    rep(i, 1, m - 1) cnt[i] += cnt[i - 1];
    for (int i = n - 1; i >= 0; --i) sa[--cnt[x[i]]] = i;
    for (int k = 1; k < n; k *= 2) {
        int p = 0;
        rep(i, n - k, n - 1) y[p++] = i;
        rep(i, 0, n - 1) if (sa[i] >= k) {
            y[p++] = sa[i] - k;
        }

        clr(cnt, 0);
        rep(i, 0, n - 1) ++cnt[x[y[i]]];
        rep(i, 0, m - 1) cnt[i] += cnt[i - 1];
        rep(i, 0, n - 1) sa[--cnt[x[y[i]]]] = y[i];

        swap(x, y);
        m = 1;
        x[sa[0]] = 0;
        rep(i, 1, n - 1) {
            x[sa[i]] = cmp(y, sa[i], sa[i - 1], k) ? m - 1 : m++;
        }

        if (m >= n) return;
    }
}

void getHeight() {
    rep(i, 0, n - 1) rk[sa[i]] = i;
    int k = 0;
    rep(i, 0, n - 1) {
        if (!rk[i]) continue;
        if (k) --k;
        int j = sa[rk[i] - 1];
        while (s[i + k] == s[j + k]) ++k;
        height[rk[i]] = k;
    }
}

int num[mm], m;
bool vis[mm];
int anscnt;
int ans[mm];

inline bool check() {
    int t = 0;
    rep(i, 0, m - 1) if (vis[i]) ++t;
    return t > m / 2;
}

void solve(int k) {
    anscnt = 0;
    for (int i = 0, j = 1; j < n; i = j++) {
        while (height[j] >= k) ++j;
        if (j - i <= m / 2) continue;
        rep(t, 0, m - 1) vis[t] = false;
        ans[anscnt] = sa[i];
        for (; i < j; ++i) {
            vis[num[sa[i]]] = true;
        }
        if (check()) ++anscnt;
    }
}

char buf[mm];

bool pre() {
    scanf("%d", &m);
    if (m <= 0) return false;
    n = 0;
    rep(i, 0, m - 1) {
        scanf("%s", buf);
        int k = strlen(buf);
        rep(j, 0, k - 1) {
            s[n] = buf[j] - 'a' + 101;
            num[n++] = i;
        }
        s[n] = i;
        num[n++] = i;
    }
    return true;
}

void printAns(int k) {
    if (!k) {
        printf("?\n\n");
        return;
    }
    rep(i, 0, anscnt - 1) {
        rep(j, 0, k - 1) {
            putchar(s[ans[i] + j] - 101 + 'a');
        }
        putchar('\n');
    }
    putchar('\n');
}

void work() {
    makeSA();
    getHeight();
    int l = 0, r = 1001;
    while (r > l + 1) {
        int m = (l + r) / 2;
        solve(m);
        if (anscnt > 0) {
            l = m;
        } else {
            r = m;
        }
    }
    printAns(l);
}

int main() {
    while (pre()) {
        work();
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
