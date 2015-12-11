//Created At: Fri Dec 11 16:32:38 CST 2015
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
#define nm 21
#define mm 1000001
#define mod 1000000000
using namespace std;

int dp[mm][nm];
int p[nm];

void pre() {
	p[0] = 1;
	rep(i, 1, nm - 1) p[i] = p[i - 1] * 2;
	//clr(dp, 0);
	rep(j, 0, nm - 1) {
		dp[0][j] = 1;
	}
	rep(i, 1, mm - 1) {
		dp[i][0] = 1;
		rep(j, 1, nm - 1) {
			dp[i][j] = dp[i][j - 1];
			if (i >= p[j]) {
				dp[i][j] = (dp[i][j] + dp[i - p[j]][j]) % mod;
			}
		}
	}
}

int main() {
	pre();
	int n;
	while (scanf("%d", &n) != EOF) printf("%d\n", dp[n][nm - 1]);

	fclose(stdin);
	fclose(stdout);
	return 0;
}
