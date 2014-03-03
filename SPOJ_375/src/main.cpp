/*
 * main.cpp
 *
 *  Created on: Mar 3, 2014
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
#define mm 400100
using namespace std;

struct _node
{
	int top, son, father, size, depth, index, weight;
}node[mm];

struct _edge
{
	int index;
	int u, v, w;
	_edge *next;
}edge[mm];

_edge *head[mm];
int n, ne, ns;
int s[mm], height, size;
int rank[mm];

void dfs(int u)
{
	node[u].size = 1;
	for (_edge* e = head[u]; e; e = e -> next)
	{
		int v = e -> v;
		if (v != node[u].father)
		{
			rank[e -> index] = v;
			node[v].father = u;
			node[v].weight = e -> w;
			node[v].depth = node[u].depth + 1;
			dfs(v);
			node[u].size += node[v].size;
			if (node[u].son == 0 || node[v].size > node[node[u].son].size)
				node[u].son = v;
		}
	}
}

void build(int u, int t)
{
	node[u].index = ++ns;
	node[u].top = t;
	if (node[u].son)
		build(node[u].son, t);
	for (_edge* e = head[u]; e; e = e -> next)
		if (e -> v != node[u].father && e -> v != node[u].son)
			build(e -> v, e -> v);
}

int query(int l, int r)
{
	int ans = 0;
	l += size - 1;
	r += size + 1;
	while (r - l > 1)
	{
		if (l % 2 == 0) ans = max(ans, s[l + 1]);
		if (r % 2 == 1) ans = max(ans, s[r - 1]);
		l /= 2;
		r /= 2;
	}
	return ans;
}

void update(int i, int x)
{
	i += size;
	s[i] = x;
	for (i /= 2; i; i /= 2)
		s[i] = max(s[2 * i], s[2 * i + 1]);
}

int query_tree(int u, int v)
{
	int ans = 0;
	while (node[u].top != node[v].top)
	{
		if (node[node[u].top].depth < node[node[v].top].depth)
		{
			int t = u;
			u = v;
			v = t;
		}
		int t1 = node[u].top;
		if (!node[u].index)
			continue;
		if (node[u].top == u)
		{
			ans = max(ans, s[node[u].index + size]);
			u = node[u].father;
		} else {
			ans = max(ans, query(node[node[t1].son].index, node[u].index));
			u = node[u].top;
		}
	}
	if (node[u].depth > node[v].depth)
	{
		int t = u;
		u = v;
		v = t;
	}
	ans = max(ans, query(node[node[u].son].index, node[v].index));
	return ans;
}

void build_tree()
{
	height = 0;
	for (int i = ns + 1; i; i /= 2)
		++height;
	size = 1 << height;
	clr(s, 0);
	rep(i, 1, n)
		s[node[i].index + size] = node[i].weight;
	for (int i = size - 1; i; --i)
		s[i] = max(s[2 * i], s[2 * i + 1]);
}

inline void ins(int index, int u, int v, int w)
{
	++ne;
	edge[ne].index = index;
	edge[ne].u = u;
	edge[ne].v = v;
	edge[ne].w = w;
	edge[ne].next = head[u];
	head[u] = &edge[ne];
}

int main()
{
	int t;
	scanf("%d", &t);
	rep(i, 1, t)
	{
		clr(head, 0);
		clr(edge, 0);
		clr(node, 0);
		scanf("%d", &n);
		ne = 0;
		rep(i, 1, n - 1)
		{
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			ins(i, x, y, z);
			ins(i, y, x, z);
		}
		ns = 0;
		dfs(1);
		build(1, 1);
		build_tree();
		char str[100];
		scanf("%s", str);
		while (str[0] != 'D')
		{
			int x, y;
			if (str[0] == 'Q')
			{
				scanf("%d%d", &x, &y);
				printf("%d\n", query_tree(x, y));
			} else {
				scanf("%d%d", &x, &y);
				update(node[rank[x]].index, y);
			}
			scanf("%s", str);
		}
	}
}

