/*
 * main.cpp
 *
 *  Created on: 2013-7-29
 *      Author: gyf
 */

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define clr(i, a) memset(i, a, sizeof(i))
#define max(a, b) (a)>(b)?(a):(b)
#define min(a, b) (a)<(b)?(a):(b)
#define infi 0x7FFFFFFF
#define mm 5010
#define mod 100000000

int dp[mm], dp0[mm], r[mm];
int n, f;

int work()
{
	clr(dp0, 0);
	dp0[0] = 1;
	rep(i, 1, n)
	{
		rep(j, 0, f - 1)
			dp[j] = (dp0[j] + dp0[(f * 20000 + j - r[i]) % f]) % mod;
		rep(j, 0, f - 1)
			dp0[j] = dp[j];
	}
	return dp[0];
}

int main()
{
	freopen("fristeam.in", "r", stdin);
	freopen("fristeam.out", "w", stdout);

	scanf("%d%d", &n, &f);
	rep(i, 1, n)
		scanf("%d", r + i);
	printf("%d\n", (mod + work() - 1) % mod);

	fclose(stdin);
	fclose(stdout);
	return 0;
}



