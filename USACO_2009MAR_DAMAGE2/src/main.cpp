/*
 * main.cpp
 *
 *  Created on: Jan 30, 2014
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
#define nm 3100
#define mm 23000
using namespace std;

struct _edge
{
	int u, v;
	int w, f;
	int next;
}edge[mm * 4];

int head[nm * 2], n, ne;
int delta, s, t;
bool vis[nm * 2], con[nm][nm];

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

inline void ins(int u, int v, int w)
{
	++ne;
	edge[ne].u = u;
	edge[ne].v = v;
	edge[ne].w = w;
	edge[ne].next = head[u];
	head[u] = ne;
}

void pre()
{
	int m, p;
	scanf("%d%d%d", &n, &m, &p);
	clr(con, 0);
	clr(vis, 0);
	clr(edge, 0);
	rep(i, 1, m)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		if (x == y || con[x][y])
			continue;
		con[x][y] = con[y][x] = true;
		if (x == 1 || y == 1)
		{
			int t = max(x, y);
			ins(1, t, infi);
		} else {
			ins(x + n, y, infi);
			ins(y + n, x, infi);
		}
	}
	rep(i, 1, p)
	{
		int x;
		scanf("%d", &x);
		vis[x] = true;
		ins(x + n, n + n + 1, infi);
	}
	rep(i, 2, n)
		if (vis[i])
			ins(i, i + n, infi);
		else
			ins(i, i + n, 1);
	rep(i, 1, ne)
	{
		edge[i + ne].u = edge[i].v;
		edge[i + ne].v = edge[i].u;
		edge[i + ne].next = head[edge[i].v];
		head[edge[i].v] = i + ne;
	}
	s = 1;
	t = n + n + 1;
}

int main()
{
	freopen("damage2.in", "r", stdin);
	freopen("damage2.out", "w", stdout);

	pre();
	printf("%d\n", work());
}
