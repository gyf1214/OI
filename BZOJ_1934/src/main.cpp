/*
 * main.cpp
 *
 *  Created on: May 2, 2014
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
#define nm 310
#define mm 210000
using namespace std;

struct _edge
{
	int u, v, f;
	_edge *next, *rev;
}edge[mm];

_edge* head[mm];
int ne, s, t, n, delta;
bool vis[mm];

void ins(int u, int v, int w)
{
	++ne;
	edge[ne].u = u;
	edge[ne].v = v;
	edge[ne].f = w;
	edge[ne].next = head[u];
	head[u] = &edge[ne];
	++ne;
	edge[ne].u = v;
	edge[ne].v = u;
	edge[ne].f = 0;
	edge[ne].next = head[v];
	head[v] = &edge[ne];
	edge[ne].rev = &edge[ne - 1];
	edge[ne - 1].rev = &edge[ne];
}

bool dfs(int u, int x)
{
	if (u == t)
	{
		delta = x;
		return true;
	}
	for (_edge* e = head[u]; e; e = e -> next)
		if (!vis[e -> v] && e -> f > 0)
		{
			vis[e -> v] = true;
			if (dfs(e -> v, min(e -> f, x)))
			{
				e -> f -= delta;
				e -> rev -> f += delta;
				return true;
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
	int m;
	scanf("%d%d", &n, &m);
	s = 1 + n, t = 2 + n;
	rep(i, 1, n)
	{
		int x;
		scanf("%d", &x);
		if (x)
			ins(s, i, 1);
		else
			ins(i, t, 1);
	}
	rep(i, 1, m)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		ins(x, y, 1);
		ins(y, x, 1);
	}
}

int main()
{
	pre();
	printf("%d\n", work());

	fclose(stdin);
	fclose(stdout);
	return 0;
}
