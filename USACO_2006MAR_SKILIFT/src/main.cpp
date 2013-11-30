/*
 * main.cpp
 *
 *  Created on: 2013-11-30
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
#define mm 5010
using namespace std;

int h[mm], n, k;
int dp[mm];

void work()
{
	clr(dp, 0);
	dp[1] = 1;
	rep(i, 2, n)
	{
		dp[i] = infi;
		double best = 1e99;
		int t = max(1, i - k);
		for (int j = i - 1; j >= t; --j)
			if (best >= (h[j] - h[i] + .0) / (j - i + .0))
			{
				best = (h[j] - h[i] + .0) / (j - i + .0);
				dp[i] = min(dp[i], dp[j] + 1);
			}
	}
}

int main()
{
	freopen("skilift.in", "r", stdin);
	freopen("skilift.out", "w", stdout);

	scanf("%d%d", &n, &k);
	rep(i, 1, n)
		scanf("%d", h + i);
	work();
	printf("%d\n", dp[n]);

	fclose(stdin);
	fclose(stdout);
	return 0;
}


