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
#define mm 20010
using namespace std;

struct _edge
{
	int tail, next;
}edge[mm];
int head[mm], ne;
int s[mm], b[mm], n;
int f[mm], g[mm], h[mm];

inline void ins(int x, int y)
{
	edge[ne].next = head[x];
	edge[ne].tail = y;
	head[x] = ne;
	++ne;
}

void build(int u, int p)
{
	int last = 0;
	for (int e = head[u]; e; e = edge[e].next)
	{
		int v = edge[e].tail;
		if (v == p)
			continue;
		s[u] = v;
		b[v] = last;
		last = v;
		build(v, u);
	}
}

void pre()
{
	clr(s, 0);
	clr(b, 0);
	scanf("%d", &n);
	ne = 1;
	rep(i, 1, n - 1)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		ins(x, y);
		ins(y, x);
	}
	build(1, 0);
}

void dfs(int u)
{
	if (s[u] > 0)
		dfs(s[u]);
	if (b[u] > 0)
		dfs(b[u]);
	f[u] = 1;
	g[u] = 0;
	if (s[u] != 0)
		h[u] = 0;
	else
		h[u] = infi;
	for (int v = s[u]; v; v = b[v])
	{
		f[u] += min(f[v], g[v]);
		g[u] += min(f[v], h[v]);
		h[u] += f[v];
	}
}

int main()
{
	freopen("tower.in", "r", stdin);
	freopen("tower.out", "w", stdout);

	pre();
	dfs(1);
	printf("%d\n", min(f[1], h[1]));

	fclose(stdin);
	fclose(stdout);
	return 0;
}
