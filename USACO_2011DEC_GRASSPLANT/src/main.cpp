/*
 * main.cpp
 *
 *  Created on: Feb 12, 2014
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
#define mm 1000010
#define lb(x) ((x) & (-(x)))
using namespace std;

struct _edge
{
	int u, v;
	int next;
}edge[mm];

struct _node
{
	int son, father, top, index, size, depth;
}node[mm];

int head[mm], ne;
int s[mm], ns;
int n, m;

void ins(int u, int v)
{
	++ne;
	edge[ne].u = u;
	edge[ne].v = v;
	edge[ne].next = head[u];
	head[u] = ne;
}

void dfs(int u)
{
	node[u].size = 1;
	for (int e = head[u]; e; e = edge[e].next)
		if (edge[e].v != node[u].father)
		{
			int v = edge[e].v;
			node[v].father = u;
			node[v].depth = node[u].depth + 1;
			dfs(v);
			if (!node[u].son || node[node[u].son].size < node[v].size)
				node[u].son = v;
			node[u].size += node[v].size;
		}
}

void build(int u, int top)
{
	node[u].index = ++ns;
	node[u].top = top;
	if (node[u].son)
		build(node[u].son, top);
	for (int e = head[u]; e; e = edge[e].next)
		if (edge[e].v != node[u].father && edge[e].v != node[u].son)
			build(edge[e].v, edge[e].v);
}

void modify(int i, int x)
{
	for (; i <= n; i += lb(i))
		s[i] += x;
}

int query(int i)
{
	int ans = 0;
	for (; i > 0; i -= lb(i))
		ans += s[i];
	return ans;
}

void update(int u, int v)
{
	while (node[u].top != node[v].top)
	{
		int t1 = node[u].top;
		int t2 = node[v].top;
		if (node[t1].depth < node[t2].depth)
		{
			int t = t1;
			t1 = t2;
			t2 = t;
			t = u;
			u = v;
			v = t;
		}
		if (!node[u].index)
			continue;
		if (node[u].top == u)
		{
			modify(node[u].index, 1);
			modify(node[u].index + 1, -1);
			u = node[u].father;
		} else {
			modify(node[node[t1].son].index, 1);
			modify(node[u].index + 1, -1);
			u = node[u].top;
		}
	}
	if (node[u].depth > node[v].depth)
	{
		int t = u;
		u = v;
		v = t;
	}
	modify(node[node[u].son].index, 1);
	modify(node[v].index + 1, -1);
}

void pre()
{
	scanf("%d%d", &n, &m);
	rep(i, 1, n - 1)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		ins(x, y);
		ins(y, x);
	}
	dfs(1);
	ns = -1;
	build(1, 1);
}

int main()
{
	freopen("grassplant.in", "r", stdin);
	freopen("grassplant.out", "w", stdout);

	pre();
	rep(i, 1, m)
	{
		char str[10];
		int x, y;
		scanf("%s%d%d", str, &x, &y);
		if (str[0] == 'Q')
		{
			if (node[y].father == x)
				x = y;
			printf("%d\n", query(node[x].index));
		} else {
			update(x, y);
		}
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}

