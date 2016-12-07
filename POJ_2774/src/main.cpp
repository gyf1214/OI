//Created At: Wed Dec 7 18:21:00 CST 2016
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
#define mm 400010
using namespace std;

int sa[mm], rk[mm], cnt[mm], t1[mm], t2[mm];
int height[mm], n;
char s[mm];

bool cmp(int *y, int a, int b, int k) {
    int a1 = y[a], b1 = y[b];
    int a2 = a + k >= n ? -1 : y[a + k];
    int b2 = b + k >= n ? -1 : y[b + k];
    return a1 == b1 && a2 == b2;
}

void makeSA() {
    int *x = t1, *y = t2;
    int m = 256;
    clr(cnt, 0);
    rep(i, 0, n - 1) ++cnt[x[i] = s[i]];
    rep(i, 1, m - 1) cnt[i] += cnt[i - 1];
    for (int i = n - 1; i >= 0; --i) sa[--cnt[x[i]]] = i;
    for (int k = 1; k < n; k *= 2) {
        int p = 0;
        for (int i = n - k; i < n; ++i) y[p++] = i;
        rep(i, 0, n - 1) if (sa[i] >= k) {
            y[p++] = sa[i] - k;
        }
        clr(cnt, 0);
        rep(i, 0, n - 1) ++cnt[x[y[i]]];
        rep(i, 1, m - 1) cnt[i] += cnt[i - 1];
        for (int i = n - 1; i >= 0; --i) sa[--cnt[x[y[i]]]] = y[i];

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
    height[0] = 0;
    int k = 0;
    rep(i, 0, n - 1) {
        if (!rk[i]) continue;
        int j = sa[rk[i] - 1];
        if (k) --k;
        while (s[j + k] == s[i + k]) ++k;
        height[rk[i]] = k;
    }
}

int main() {
    scanf("%s", s);
    int l = strlen(s);
    scanf("%s", s + l + 1);
    n = l + strlen(s + l + 1) + 1;
    makeSA();
    getHeight();
    int ans = 0;
    rep(i, 1, n - 1) {
        if ((sa[i] < l && sa[i - 1] > l) || (sa[i] > l && sa[i - 1] < l)) {
            ans = max(ans, height[i]);
        }
    }
    printf("%d\n", ans);

    fclose(stdin);
    fclose(stdout);
    return 0;
}
