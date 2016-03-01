//Created At: Tue Mar 1 15:05:59 CST 2016
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
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define clr(i, a) memset(i, (a), sizeof(i))
#define sqr(x) ((x)*(x))
#define infi 0x7FFFFFFF
#define mm 16
using namespace std;

int dp[mm][mm][mm][mm][mm];
int a[mm][mm];
int n;

int sum(int up, int down, int left, int right) {
	return a[down][right] - a[up - 1][right] - a[down][left - 1] + a[up - 1][left - 1];
}

void update(int &x, int y) {
	x = min(x, y);
}

void calc(int x, int u, int d, int l, int r) {
	rep(m, u, d - 1) {
		update(dp[x][u][d][l][r], sqr(sum(u, m, l, r)) + dp[x - 1][m + 1][d][l][r]);
		update(dp[x][u][d][l][r], sqr(sum(m + 1, d, l, r)) + dp[x - 1][u][m][l][r]);
	}
	rep(m, l, r - 1) {
		update(dp[x][u][d][l][r], sqr(sum(u, d, l, m)) + dp[x - 1][u][d][m + 1][r]);
		update(dp[x][u][d][l][r], sqr(sum(u, d, m + 1, r)) + dp[x - 1][u][d][l][m]);
	}
}

double work() {
	scanf("%d", &n);
	clr(a, 0);
	rep(i, 1, 8) {
		rep(j, 1, 8) {
			scanf("%d", &a[i][j]);
			a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
		}
	}
	clr(dp, 0x6F);
	rep(u, 1, 8) {
		rep(d, u, 8) {
			rep(l, 1, 8) {
				rep(r, l, 8) dp[0][u][d][l][r] = sqr(sum(u, d, l, r));
			}
		}
	}
	rep(i, 1, n) {
		rep(u, 1, 8) {
			rep(d, u, 8) {
				rep(l, 1, 8) {
					rep(r, l, 8) calc(i, u, d, l, r);
				}
			}
		}
	}
	return sqrt((double)dp[n - 1][1][8][1][8] / (double)n - sqr((double)a[8][8] / (double)n));
}

int main() {
	printf("%.3f\n", work());

	fclose(stdin);
	fclose(stdout);
	return 0;
}
