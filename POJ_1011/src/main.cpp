//Created At: Wed Apr 27 10:56:32 CST 2016
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
#define infi 0x7FFFFFFF
#define mm 70
using namespace std;

int a[mm], n, m;
bool v[mm];

bool dfs(int d, int t, int u) {
    if (d == n) return true;
    if (t == 0 || t == m) {
        int k = 0;
        while (v[k]) ++k;
        v[k] = true;
        bool ret = dfs(d + 1, a[k], k + 1);
        v[k] = false;
        return ret;
    }
    rep(i, u, n - 1) {
        if (!v[i] && t + a[i] <= m) {
            if (!v[i - 1] && a[i] == a[i - 1]) continue;
            v[i] = true;
            bool ret = dfs(d + 1, t + a[i], i + 1);
            v[i] = false;
            if (ret) return true;
        }
    }
    return false;
}

int work() {
    scanf("%d", &n);
    if (!n) return 0;
    int sum = 0;
    rep(i, 0, n - 1) {
        scanf("%d", a + i);
        sum += a[i];
    }
    sort(a, a + n, greater<int>());
    rep(i, a[0], sum - 1) {
        if (sum % i == 0) {
            clr(v, 0);
            m = i;
            if (dfs(0, 0, 0)) return m;
        }
    }
    return sum;
}

int main() {
    int ret;
    while ((ret = work()) > 0) {
        printf("%d\n", ret);
    }

	fclose(stdin);
	fclose(stdout);
	return 0;
}
