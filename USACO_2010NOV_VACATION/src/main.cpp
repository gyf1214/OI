/*
 * main.cpp
 *
 *  Created on: Jan 25, 2014
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
#define mm 60000
using namespace std;

struct _edge
{
	int next, tail;
}edge[mm * 2];
int head[mm];
int f[mm], g[mm];
bool vis[mm];
int n, ne;

inline void ins(int u, int v)
{
	++ne;
	edge[ne].next = head[u];
	edge[ne].tail = v;
	head[u] = ne;
}

void dfs(int u)
{
	vis[u] = true;
	f[u] = 1;
	g[u] = 0;
	for (int e = head[u]; e; e = edge[e].next)
	{
		int v = edge[e].tail;
		if (vis[v])
			continue;
		dfs(v);
		f[u] += g[v];
		g[u] += max(f[v], g[v]);
	}
}

int main()
{
	freopen("vacation.in", "r", stdin);
	freopen("vacation.out", "w", stdout);

	scanf("%d", &n);
	clr(vis, 0);
	rep(i, 1, n - 1)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		ins(x, y);
		ins(y, x);
	}
	dfs(1);
	printf("%d\n", max(f[1], g[1]));

	fclose(stdin);
	fclose(stdout);
	return 0;
}
