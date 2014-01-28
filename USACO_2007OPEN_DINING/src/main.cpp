/*
 * main.cpp
 *
 *  Created on: Jan 28, 2014
 *      Author: gyf
 */

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define clr(i, a) memset(i, a, sizeof(i))
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))
#define infi 0x7FFFFFFF
#define mm 50000

struct _edge
{
	int u, v;
	int w, f;
	int next;
}edge[mm];

int head[mm];
int n, f, d, ne;
int s, t, delta;
bool vis[mm];

inline void ins(int u, int v, int w)
{
	++ne;
	edge[ne].next = head[u];
	edge[ne].u = u;
	edge[ne].v = v;
	edge[ne].w = w;
	head[u] = ne;
}

bool dfs(int u, int d)
{
	if (u == t)
	{
		delta = d;
		return true;
	}
	vis[u] = true;
	for (int e = head[u]; e; e = edge[e].next)
	{
		int v = edge[e].v;
		if (vis[v])
			continue;
		if (e <= ne)
		{
			if (edge[e].f < edge[e].w)
				if (dfs(v, min(d, edge[e].w - edge[e].f)))
				{
					edge[e].f += delta;
					return true;
				}
		} else {
			if (edge[e - ne].f > 0)
				if (dfs(v, min(d, edge[e - ne].f)))
				{
					edge[e - ne].f -= delta;
					return true;
				}
		}
	}
	return false;
}

int work()
{
	int ans = 0;
	clr(vis, 0);
	while (dfs(s, infi))
	{
		ans += delta;
		clr(vis, 0);
	}
	return ans;
}

void pre()
{
	clr(edge, 0);
	clr(head, 0);
	scanf("%d%d%d", &n, &f, &d);
	s = 1;
	t = 1 + f + n + n + d + 1;
	rep(i, 1, f)
		ins(s, 1 + i, 1);
	rep(i, 1, d)
		ins(1 + f + n + n + i, t, 1);
	rep(i, 1, n)
	{
		ins(1 + f + i, 1 + f + n + i, 1);
		int x, y, z;
		scanf("%d%d", &x, &y);
		rep(j, 1, x)
		{
			scanf("%d", &z);
			ins(1 + z, 1 + f + i, 1);
		}
		rep(j, 1, y)
		{
			scanf("%d", &z);
			ins(1 + f + n + i, 1 + f + n + n + z, 1);
		}
	}
	rep(i, 1, ne)
	{
		edge[i + ne].next = head[edge[i].v];
		edge[i + ne].u = edge[i].v;
		edge[i + ne].v = edge[i].u;
		head[edge[i].v] = i + ne;
	}
}

int main()
{
	freopen("dining.in", "r", stdin);
	freopen("dining.out", "w", stdout);

	pre();
	printf("%d\n", work());

	fclose(stdin);
	fclose(stdout);
	return 0;
}
