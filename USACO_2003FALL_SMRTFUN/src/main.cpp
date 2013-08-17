/*
 * main.cpp
 *
 *  Created on: 2013-8-6
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
#define mm 301000
#define nm 200
#define offset 100000

int dp[mm], dp0[mm], f[nm], s[nm];
int n;

int work()
{
	rep(i, 0, 2 * offset)
		dp[i] = -infi / 3;
	dp[offset] = 0;
	rep(i, 1, n)
	{
		rep(j, 0, 2 * offset)
			dp0[j] = dp[j];
		for (int j = 2 * offset; j >= 0; --j)
			if (j - f[i] >= 0 && j - f[i] <= 2 * offset)
				dp[j] = max(dp0[j], dp0[j - f[i]] + s[i]);
	}
	int ans = 0;
	rep(i, offset, 2 * offset)
		if (dp[i] > 0)
			ans = max(ans, dp[i] + i - offset);
	return ans;
}

int main()
{
	freopen("smrtfun.in", "r", stdin);
	freopen("smrtfun.out", "w", stdout);

	scanf("%d", &n);
	rep(i, 1, n)
		scanf("%d%d", s + i, f + i);
	printf("%d\n", work());
}


