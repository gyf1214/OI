/*
 * main.cpp
 *
 *  Created on: 2013-8-20
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
#define mm 1010
#define mod 10000

int dp[mm], s[mm];

int work(int n, int k)
{
	clr(dp, 0);
	s[0] = dp[0] = 1;
	rep(i, 1, k)
		s[i] = s[i - 1] + dp[i];
	rep(i, 2, n)
	{
		rep(j, 0, k)
			if (j - i < 0)
				dp[j] = (s[j] + 10000) % 10000;
			else
				dp[j] = (s[j] - s[j - i] + 10000) % 10000;
		s[0] = dp[0];
		rep(j, 1, k)
			s[j] = (s[j - 1] + dp[j] + 10000) % 10000;
	}
	return (dp[k] + 10000) % 10000;
}

int main()
{
	int t;
	scanf("%d", &t);
	rep(i, 1, t)
	{
		int n, k;
		scanf("%d%d", &n, &k);
		printf("%d\n", work(n, k));
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}


