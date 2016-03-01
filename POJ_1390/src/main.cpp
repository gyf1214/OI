//Created At: Tue Mar 1 16:05:22 CST 2016
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
#define sqr(x) ((x)*(x))
#define infi 0x7FFFFFFF
#define mm 210
using namespace std;

int dp[mm][mm][mm];
int a[mm], b[mm], len[mm];
int temp[mm], p[mm], cnt[mm][mm];
int n, m;

int work() {
	clr(dp, 0);
	rep(l, 1, m) {
		rep(i, 1, m - l + 1) {
			int j = i + l - 1;
			rep(k, 0, cnt[j][b[j]]) {
				dp[i][j][k] = dp[i][j - 1][0] + sqr(len[j] + k);
				for (int x = p[j]; x >= i; x = p[x]) {
					dp[i][j][k] = max(dp[i][j][k], dp[x + 1][j - 1][0] + dp[i][x][len[j] + k]);
				}
			}
		}
	}
	return dp[1][m][0];
}

void pre() {
	scanf("%d", &n);
	clr(a, 0);
	rep(i, 1, n) scanf("%d", &a[i]);
	clr(b, 0);
	clr(len, 0);
	m = 0;
	rep(i, 1, n) {
		if (a[i] != a[i - 1]) {
			b[++m] = a[i];
		}
		++len[m];
	}
	clr(temp, 0);
	rep(i, 1, m) {
		p[i] = temp[b[i]];
		temp[b[i]] = i;
	}
	clr(cnt, 0);
	rep(i, 1, m) {
		for (int j = i - 1; j > 0; --j) {
			cnt[j][b[i]] += len[i];
		}
	}
}

int main() {
	int t;
	scanf("%d", &t);
	rep(i, 1, t) {
		pre();
		printf("Case %d: %d\n", i, work());
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
