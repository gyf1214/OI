/*
 * main.cpp
 *
 *  Created on: 2013-11-23
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
#define nm 20
#define mm 70000
using namespace std;

typedef pair<int, int> pii;

long long dp[nm][mm];
pii q[nm * mm];
bool vis[nm][mm];
int s[nm], n, k;

long long work()
{
	clr(vis, 0);
	clr(dp, 0);
	int l = 0;
	int r = 0;
	rep(i, 0, n - 1)
	{
		vis[i][1 << i] = true;
		dp[i][1 << i] = 1;
		q[r] = make_pair(i, 1 << i);
		++r;
	}
	while (r > l)
	{
		pii now = q[l];
		++l;
		rep(i, 0, n - 1)
			if (abs(s[now.first] - s[i]) > k && (now.second & (1 << i)) == 0)
			{
				dp[i][now.second | (1 << i)] += dp[now.first][now.second];
				if (!vis[i][now.second | (1 << i)])
				{
					vis[i][now.second | (1 << i)] = true;
					q[r] = make_pair(i, now.second | (1 << i));
					++r;
				}
			}
	}
	long long ans = 0;
	rep(i, 0, n - 1)
		ans += dp[i][(1 << n) - 1];
	return ans;
}

int main()
{
	freopen("mixup2.in", "r", stdin);
	freopen("mixup2.out", "w", stdout);

	scanf("%d%d", &n, &k);
	rep(i, 0, n - 1)
		scanf("%d", s + i);
	printf("%lld\n", work());

	fclose(stdin);
	fclose(stdout);
	return 0;
}
