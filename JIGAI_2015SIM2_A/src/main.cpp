//Created At: Fri Dec 18 16:01:04 CST 2015
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
#define mm 200
using namespace std;

int dp[mm][mm];
int a[mm], n;

int work() {
	clr(dp, 0);
	rep(l, 0, n - 3) {
		rep(i, 1, n - 2 - l) {
			int j = i + l;
			dp[i][j] = infi;
			rep(k, i, j) {
				dp[i][j] = min(dp[i][j], dp[i][k - 1] + dp[k + 1][j] + a[k] * a[i - 1] * a[j + 1]);
			}
		}
	}
	return dp[1][n - 2];
}

int main() {
	scanf("%d", &n);
	rep(i, 0, n - 1) scanf("%d", a + i);
	printf("%d\n", work());

	fclose(stdin);
	fclose(stdout);
	return 0;
}
