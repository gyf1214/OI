/*
 * main.cpp
 *
 *  Created on: Mar 9, 2014
 *      Author: gyf
 */

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define clr(i, a) memset(i, (a), sizeof(i))
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))
#define infi 0x7FFFFFFF
#define mm 1010
using namespace std;

int a[mm], b[mm];
int dp[mm][mm];
int x, y, z, na, nb;

int main()
{
	freopen("landscape.in", "r", stdin);
	freopen("landscape.out", "w", stdout);

	int n;
	scanf("%d%d%d%d", &n, &x, &y, &z);
	na = nb = 0;
	rep(i, 1, n)
	{
		int k1, k2;
		scanf("%d%d", &k1, &k2);
		rep(j, 1, k1)
			a[++na] = i;
		rep(j, 1, k2)
			b[++nb] = i;
	}
	clr(dp, 0);
	rep(i, 1, na)
		dp[i][0] = y * i;
	rep(i, 1, nb)
		dp[0][i] = x * i;
	rep(i, 1, na)
		rep(j, 1, nb)
		{
			dp[i][j] = min(dp[i - 1][j] + y, dp[i][j - 1] + x);
			dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + z * abs(a[i] - b[j]));
		}
	printf("%d\n", dp[na][nb]);

	fclose(stdin);
	fclose(stdout);
}
