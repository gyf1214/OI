//Created At: Fri Dec 25 12:44:59 CST 2015
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
#define mm 1010
using namespace std;

int dp[mm][mm];
int w[mm], p[mm];
int n, m, t;

void work() {
	clr(dp, 0);
	rep(i, 0, n - 1) {
		for (int j = m; j > 0; --j) {
			for (int k = t; k > 0; --k) {
				if (j > p[i] && k >= w[i]) {
					dp[j][k] = max(dp[j][k], dp[j - p[i]][k - w[i]] + 1);
				}
			}
		}
	}
	int ans = -1, best = 0;
	rep(j, 1, m) {
		rep(k, 1, t) {
			if (dp[j][k] > ans) {
				ans = dp[j][k];
				best = j;
			}
		}
	}
	printf("%d %d\n", ans, m + 1 - best);
}

void pre() {
	scanf("%d%d%d", &t, &m, &n);
	rep(i, 0, n - 1) {
		scanf("%d%d", w + i, p + i);
	}
}

int main() {
	pre();
	work();

	fclose(stdin);
	fclose(stdout);
	return 0;
}
