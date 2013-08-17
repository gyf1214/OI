/*
 * main.cpp
 *
 *  Created on: 2013-7-28
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
#define mm 50100

int dp[mm], v[mm];
int n, c;

void work()
{
	clr(dp, 0);
	rep(i, 1, n)
		for (int j = c; j > 0; --j)
			if (j >= v[i])
				dp[j] = max(dp[j], dp[j - v[i]] + v[i]);
}

int main()
{
	freopen("hay4sale.in", "r", stdin);
	freopen("hay4sale.out", "w", stdout);

	scanf("%d%d", &c, &n);
	rep(i, 1, n)
		scanf("%d", v + i);
	work();
	int ans = 0;
	rep(i, 0, c)
		ans = max(ans, dp[i]);
	printf("%d\n", ans);

	fclose(stdin);
	fclose(stdout);
	return 0;
}


