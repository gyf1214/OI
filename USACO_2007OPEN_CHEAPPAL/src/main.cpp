/*
 * main.cpp
 *
 *  Created on: 2013-11-8
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
#define mm 3000
using namespace std;

int dp[mm][mm];
char str[mm];
int cost[26];
int m;

int work()
{
	clr(dp, 127);
	rep(i, 0, m - 1)
		dp[0][i] = dp[1][i] = 0;
	rep(i, 2, m)
		rep(j, 0, m - i)
		{
			if (str[j] == str[i + j - 1])
				dp[i][j] = min(dp[i][j], dp[i - 2][j + 1]);
			dp[i][j] = min(dp[i][j], dp[i - 1][j] + cost[str[i + j - 1] - 'a']);
			dp[i][j] = min(dp[i][j], dp[i - 1][j + 1] + cost[str[j] - 'a']);
		}
	return dp[m][0];
}

int main()
{
	freopen("cheappal.in", "r", stdin);
	freopen("cheappal.out", "w", stdout);

	int n;
	scanf("%d%d", &n, &m);
	fflush(stdin);
	scanf("%s", str);
	rep(i, 1, n)
	{
		char c;
		int x, y;
		do {
			c = getchar();
		} while (c > 'z' || c < 'a');
		scanf("%d%d", &x, &y);
		cost[c - 'a'] = min(x, y);
	}
	printf("%d\n", work());

	fclose(stdin);
	fclose(stdout);
	return 0;
}
