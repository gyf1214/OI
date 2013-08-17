#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#define rep(i, a, b)	for (int i = a; i <= b; ++i)
#define clr(i, a)		memset(i, a, sizeof(i))
#define max(a, b)		(a)>(b)?(a):(b)
#define min(a, b)		(a)<(b)?(a):(b)
#define infi			0x7FFFFFFF
#define mm				2000
using namespace std;

int dp[2][mm];

int main()
{
	freopen("bcatch.in", "r", stdin);
	freopen("bcatch.out", "w", stdout);

	int n, w;
	scanf("%d%d", &n, &w);
	clr(dp, 0);
	dp[0][w + 1] = -infi;
	dp[1][w + 1] = -infi;
	rep(i, 1, n)
	{
		int s;
		scanf("%d", &s);
		rep(j, 0, w)
		{
			dp[s - 1][j] = max(dp[s - 1][j] + 1, dp[2 - s][j + 1]);
			dp[2 - s][j] = max(dp[2 - s][j], dp[s - 1][j + 1] + 1);
		}
	}
	int ans = 0;
	rep(i, 0, w)
	{
		ans = max(ans, dp[0][i]);
		ans = max(ans, dp[1][i]);
	}
	printf("%d", ans);
}
