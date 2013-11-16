/*
 * main.cpp
 *
 *  Created on: 2013-11-16
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
#define nm 26
#define mm 500
#define mod 97654321
using namespace std;

struct _edge
{
	int tail, next;
}edge[mm];
int head[nm * 2], ne;

int dp[mm][nm * 2], dp0[mm][nm * 2], u, l;

inline int trans(char c)
{
	if (c >= 'a')
		return c - 'a' + 26;
	else
		return c - 'A';
}

inline void ins(int x, int y)
{
	edge[ne].next = head[x];
	edge[ne].tail = y;
	head[x] = ne;
	++ne;
}

int work()
{
	clr(dp, 0);
	rep(i, 0, 25)
		dp[1][i] = 1;
	rep(i, 26, 51)
		dp[0][i] = 1;
	rep(i, 2, u + l)
	{
		rep(j, 0, u)
			rep(k, 0, 51)
				dp0[j][k] = dp[j][k] % mod;
		clr(dp, 0);
		rep(j, 0, u)
			rep(k, 0, 51)
				for (int e = head[k]; e; e = edge[e].next)
				{
					int t = edge[e].tail;
					if (t < 26)
						dp[j + 1][t] = (dp[j + 1][t] + dp0[j][k]) % mod;
					else
						dp[j][t] = (dp[j][t] + dp0[j][k]) % mod;
				}
	}
	int ans = 0;
	rep(i, 0, 51)
		ans = (ans + dp[u][i]) % mod;
	return ans;
}

int main()
{
	freopen("cowlpha.in", "r", stdin);
	freopen("cowlpha.out", "w", stdout);

	int p;
	scanf("%d%d%d", &u, &l, &p);
	ne = 1;
	rep(i, 1, p)
	{
		char str[10];
		scanf("%s", str);
		int x = trans(str[0]);
		int y = trans(str[1]);
		ins(x, y);
	}
	printf("%d\n", work());

	fclose(stdin);
	fclose(stdout);
	return 0;
}

