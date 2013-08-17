/*
 * main.cpp
 *
 *  Created on: 2013-7-26
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
#define mm 500
using namespace std;

int s[mm], b[mm], f[mm][mm], g[mm][mm], c[mm];
int n, m;

void pre()
{
	scanf("%d%d", &n, &m);
	clr(s, 0);
	clr(b, 0);
	rep(i, 0, n)
		rep(j, 0, n)
			g[i][j] = f[i][j] = - infi / 3;
	g[0][0] = f[0][0] = 0;
	rep(i, 1, n)
	{
		int x;
		scanf("%d%d", c + i, &x);
		b[i] = s[x];
		s[x] = i;
	}
}

void dfs(int u)
{
	if (u == 0)
		return;
	dfs(s[u]);
	dfs(b[u]);
	rep(i, 0, n)
		rep(j, 0, i)
		{
			f[u][i] = max(f[u][i], g[s[u]][j] + f[b[u]][i - j]);
			if (j != i)
				f[u][i] = max(f[u][i], f[s[u]][j] + f[b[u]][i - j - 1] + c[u]);
			g[u][i] = max(g[u][i], g[s[u]][j] + g[b[u]][i - j]);
			g[u][i] = max(g[u][i], f[s[u]][j] + g[b[u]][i - j] + c[u]);
		}
}

int main()
{
	freopen("tselect.in", "r", stdin);
	freopen("tselect.out", "w", stdout);

	pre();
	dfs(s[0]);
	int ans = -1;
	rep(i, 1, n)
		rep(j, 0, n)
			if (g[i][j] >= m)
			{
				ans = max(ans, j);
			}
	printf("%d\n", ans);

	fclose(stdin);
	fclose(stdout);
	return 0;
}




