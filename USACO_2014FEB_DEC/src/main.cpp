/*
 * main.cpp
 *
 *  Created on: Feb 10, 2014
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
#define mm 1100000
#define nm 30
using namespace std;

struct _bonus
{
	int p, a;
	inline friend bool operator <(_bonus a, _bonus b)
	{
		return a.p < b.p;
	}
}bonus[nm][nm];
int cnt[nm];

int dp[mm];
int q[mm];
bool vis[mm];
int s[nm][nm];
int l, r;
int n, m;

int size(int m)
{
	int ans = 0;
	for (; m; m /= 2)
		if (m % 2 == 1)
			++ans;
	return ans;
}

int work()
{
	clr(dp, 0);
	l = 0;
	r = 1;
	q[0] = 0;
	while (l < r)
	{
		int now = q[l];
		int t = size(now) + 1;
		rep(i, 1, n)
			if (((1 << (i - 1)) & now) == 0)
			{
				int next = (1 << (i - 1)) | now;
				int ans = dp[now] + s[i][t];
				rep(j, 1, cnt[t])
				{
					if (ans >= bonus[t][j].p)
						ans += bonus[t][j].a;
				}
				dp[next] = max(dp[next], ans);
				if (!vis[next])
				{
					q[r] = next;
					++r;
					vis[next] = true;
				}
			}
		++l;
	}
	return dp[(1 << n) - 1];
}

void pre()
{
	int b;
	scanf("%d%d", &n, &b);
	clr(cnt, 0);
	rep(i, 1, b)
	{
		int k;
		scanf("%d", &k);
		++cnt[k];
		scanf("%d%d", &bonus[k][cnt[k]].p, &bonus[k][cnt[k]].a);
	}
	rep(i, 1, n)
		rep(j, 1, n)
			scanf("%d", &s[i][j]);
	rep(i, 1, n)
		sort(bonus[i] + 1, bonus[i] + 1 + cnt[i]);
}

int main()
{
	freopen("dec.in", "r", stdin);
	freopen("dec.out", "w", stdout);

	pre();
	printf("%d\n", work());

	fclose(stdin);
	fclose(stdout);
	return 0;
}

