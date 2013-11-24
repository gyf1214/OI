/*
 * main.cpp
 *
 *  Created on: 2013-11-24
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
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))
#define infi 0x7FFFFFFF
#define nm 600
#define mm 100010
using namespace std;

int p[nm], v[nm], g[nm];
int dp[nm][mm], n, m;

void work()
{
	rep(i, 0, g[n])
		rep(j, 0, mm - 1)
			dp[i][j] = -infi / 3;
	dp[0][0] = 0;
	rep(i, 0, n - 1)
	{
		rep(k, 0, mm - 1)
		{
			dp[g[i + 1]][k] = max(dp[g[i + 1]][k], dp[g[i]][k]);
			if (k >= p[g[i] + 1])
				dp[g[i] + 1][k] = max(dp[g[i] + 1][k], dp[g[i]][k - p[g[i] + 1]]);
		}
		rep(j, g[i] + 2, g[i + 1])
		{
			rep(k, 0, mm - 1)
			{
				dp[j][k] = max(dp[j][k], dp[j - 1][k]);
				if (k >= p[j])
					dp[j][k] = max(dp[j][k], dp[j - 1][k - p[j]] + v[j]);
			}
		}
	}
}

void pre()
{
	scanf("%d%d", &n, &m);
	int now = 1;
	clr(g, 0);
	clr(p, 0);
	clr(v, 0);
	rep(i, 1, n)
	{
		scanf("%d", p + now);
		int t;
		scanf("%d", &t);
		rep(j, 1, t)
		{
			scanf("%d", p + now + j);
			scanf("%d", v + now + j);
		}
		now += t + 1;
		g[i] = now - 1;
	}
}

int main()
{
	freopen("vidgame.in", "r", stdin);
	freopen("vidgame.out", "w", stdout);

	pre();
	work();
	int ans = 0;
	rep(i, 0, mm - 1)
		if (i <= m)
			ans = max(ans, dp[g[n]][i]);
	printf("%d\n", ans);

	fclose(stdin);
	fclose(stdout);
}
