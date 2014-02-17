/*
 * main.cpp
 *
 *  Created on: Feb 17, 2014
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
#define nm 5010
#define mm 10010
using namespace std;

struct _edge
{
	_edge *next;
	int u, v;
	bool bridge;
}edge[mm];

_edge *head[nm];
int ne, n;
int dfn[nm], low[nm], temp;
int s[nm], top, bcc[nm];
int cnt[nm];

void tarjan(int u, _edge* p)
{
	dfn[u] = low[u] = ++temp;
	s[++top] = u;
	for (_edge* e = head[u]; e; e = e -> next)
	{
		int v = e -> v;
		if (!dfn[v])
		{
			tarjan(v, e);
			low[u] = min(low[u], low[v]);
		} else if (p && v != p -> u)
			low[u] = min(low[u], dfn[v]);
	}
	if (low[u] == dfn[u])
	{
		if (p)
			p -> bridge = true;
		int v;
		do
		{
			v = s[top--];
			bcc[v] = u;
		} while (u != v);
	}
}

int work()
{
	rep(i, 1, ne)
	{
		if (edge[i].bridge)
		{
			++cnt[bcc[edge[i].u]];
			++cnt[bcc[edge[i].v]];
		}
	}
	int ans = 0;
	rep(i, 1, n)
		if (cnt[i] == 1)
			++ans;
	return (ans + 1) / 2;
}

inline void ins(int u, int v)
{
	++ne;
	edge[ne].u = u;
	edge[ne].v = v;
	edge[ne].next = head[u];
	head[u] = edge + ne;
}

int main()
{
	freopen("rpaths.in", "r", stdin);
	freopen("rpaths.out", "w", stdout);

	int m;
	scanf("%d%d", &n, &m);
	ne = 0;
	clr(edge, 0);
	clr(head, 0);
	clr(cnt, 0);
	clr(bcc, 0);
	clr(s, 0);
	top = 0;
	rep(i, 1, m)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		ins(u, v);
		ins(v, u);
	}
	tarjan(1, NULL);
	printf("%d\n", work());

	fclose(stdin);
	fclose(stdout);
	return 0;
}
