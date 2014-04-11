/*
 * main.cpp
 *
 *  Created on: 2014-4-11
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
#define mm 1310
using namespace std;

int s[mm], b[mm], a[mm], n, m;
int dp[mm][mm];

void dfs(int u)
{
	if (s[u])
		dfs(s[u]);
	if (b[u])
		dfs(b[u]);
	rep(i, 0, n + 1)
	{
		dp[u][i] = dp[b[u]][i];
		rep(j, 0, i - 1)
			dp[u][i] = max(dp[u][i], dp[s[u]][j] + dp[b[u]][i - j - 1] + a[u]);
	}
}

int main()
{
	clr(s, 0);
	clr(b, 0);
	clr(a, 0);
	clr(dp, 0);
	scanf("%d%d", &n, &m);
	rep(i, 1, n)
	{
		int x;
		scanf("%d%d", &x, &a[i]);
		b[i] = s[x];
		s[x] = i;
	}
	dfs(0);

	printf("%d\n", dp[s[0]][m]);

	fclose(stdin);
	fclose(stdout);
	return 0;
}



