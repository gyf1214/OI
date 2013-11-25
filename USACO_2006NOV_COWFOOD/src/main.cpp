/*
 * main.cpp
 *
 *  Created on: 2013-11-25
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
#define nm 20
#define mm 4096
#define mod 100000000
using namespace std;

int dp[nm][nm][mm];
bool map[nm][nm];
int n, m;

void work()
{
	clr(dp, 0);
	dp[0][m][0] = 1;
	rep(i, 1, n)
		rep(j, 1, m)
		{
			int x = i;
			int y = j - 1;
			if (y == 0)
			{
				y = m;
				x = i - 1;
			}
			rep(k, 0, (1 << m) - 1)
			{
				int t = (k << 1) % (1 << m);
				if (map[i][j] && ((k & (1 << (m - 1))) == 0) && (k % 2 == 0 || j == 1))
					dp[i][j][t + 1] = (dp[i][j][t + 1] + dp[x][y][k]) % mod;
				dp[i][j][t] = (dp[i][j][t] + dp[x][y][k]) % mod;
			}
		}
}


int main()
{
	freopen("cowfood.in", "r", stdin);
	freopen("cowfood.out", "w", stdout);

	scanf("%d%d", &n, &m);
	rep(i, 1, n)
		rep(j, 1, m)
		{
			int x;
			scanf("%d", &x);
			map[i][j] = x == 1;
		}
	work();
	int ans = 0;
	rep(i, 0, (1 << m) - 1)
		ans = (ans + dp[n][m][i]) % mod;
	printf("%d\n", ans);

	fclose(stdin);
	fclose(stdout);
	return 0;
}
