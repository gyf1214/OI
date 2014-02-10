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
#include <queue>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define clr(i, a) memset(i, (a), sizeof(i))
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))
#define infi 0x7FFFFFFF
#define nm 260
#define mm 50010
using namespace std;

int f[nm][nm];
bool g[nm][nm], cut[nm][nm];
int dfn[nm], low[nm];
int u[mm], v[mm], w[mm];
int dis[nm];
bool vis[nm];
int n, m, temp, ans0;

void tarjan(int u, int p)
{
	low[u] = dfn[u] = ++temp;
	rep(v, 1, n)
		if (g[u][v])
		{
			if (!dfn[v])
			{
				tarjan(v, u);
				if (low[v] > dfn[u])
					cut[u][v] = cut[v][u] = true;
				low[u] = min(low[u], low[v]);
			} else if (v != p)
				low[u] = min(low[u], dfn[v]);
		}
}

void pre()
{
	scanf("%d%d", &n, &m);
	rep(i, 1, n)
		rep(j, 1, n)
			f[i][j] = infi / 3;
	rep(i, 1, n)
		f[i][i] = 0;
	rep(i, 1, m)
	{
		scanf("%d%d%d", &u[i], &v[i], &w[i]);
		f[u[i]][v[i]] = f[v[i]][u[i]] = w[i];
	}
	rep(k, 1, n)
		rep(i, 1, n)
			rep(j, 1, n)
				f[i][j] = min(f[i][j], f[i][k] + f[j][k]);
	ans0 = f[1][n];
	clr(g, 0);
	rep(i, 1, m)
		if (f[1][n] == f[1][u[i]] + w[i] + f[v[i]][n]
		|| f[1][n] == f[1][v[i]] + w[i] + f[u[i]][n])
		{
			g[u[i]][v[i]] = g[v[i]][u[i]] = true;
		}
	clr(cut, 0);
	temp = 0;
	tarjan(1, 0);
	rep(i, 1, n)
		rep(j, 1, n)
			f[i][j] = infi / 3;
	rep(i, 1, m)
		f[u[i]][v[i]] = f[v[i]][u[i]] = w[i];
}

int dijistra()
{
	clr(vis, 0);
	rep(i, 1, n)
		dis[i] = infi / 3;
	dis[1] = 0;
	rep(j, 2, n)
	{
		int k = 0, best = infi;
		rep(i, 1, n)
			if (!vis[i] && best > dis[i])
			{
				best = dis[i];
				k = i;
			}
		vis[k] = true;
		rep(i, 1, n)
			if (dis[k] < dis[i] - f[i][k])
				dis[i] = dis[k] + f[i][k];
	}
	return dis[n];
}

int main()
{
	freopen("rblock.in", "r", stdin);
	freopen("rblock.out", "w", stdout);

	pre();
	int ans = 0;
	rep(i, 1, m)
		if (cut[u[i]][v[i]] || cut[v[i]][u[i]])
		{
			f[u[i]][v[i]] *= 2;
			f[v[i]][u[i]] *= 2;
			ans = max(ans, dijistra());
			f[u[i]][v[i]] /= 2;
			f[v[i]][u[i]] /= 2;
		}
	printf("%d\n", ans - ans0);

	fclose(stdin);
	fclose(stdout);
	return 0;
	fclose(stdout);
}
