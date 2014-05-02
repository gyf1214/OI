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
#define clr(i, a) memset(i, a, sizeof(i));
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))
#define infi 0x7FFFFFFF
#define mm 100010
using namespace std;

struct _edge
{
	int u, v, w;
	_edge* next, * rev;
}edge[mm * 2];

_edge* head[mm];
int ne, n;
_edge* p[mm];
int d[mm];
int ans;

void ins(int u, int v)
{
	++ne;
	edge[ne].u = u;
	edge[ne].v = v;
	edge[ne].w = 1;
	edge[ne].next = head[u];
	head[u] = &edge[ne];
}

void dfs1(int u)
{
	for (_edge* e = head[u]; e; e = e -> next)
		if (!p[u] || p[u] -> u != e -> v)
		{
			p[e -> v] = e;
			d[e -> v] = d[u] + 1;
			dfs1(e -> v);
		}
}

int work1()
{
	clr(p, 0);
	clr(d, 0);
	dfs1(1);
	int k = 1;
	rep(i, 2, n)
		if (d[k] < d[i])
			k = i;
	clr(p, 0);
	clr(d, 0);
	dfs1(k);
	int t = 1;
	rep(i, 2, n)
		if (d[t] < d[i])
			t = i;
	for (int u = t; p[u]; u = p[u] -> u)
	{
		p[u] -> w = -1;
		p[u] -> rev -> w = -1;
	}
	return d[t];
}

void dfs2(int u)
{
	int m1 = 0, m2 = 0;
	for (_edge* e = head[u]; e; e = e -> next)
		if (!p[u] || p[u] -> u != e -> v)
		{
			p[e -> v] = e;
			dfs2(e -> v);
			if (d[e -> v] + e -> w > m1)
			{
				m2 = m1;
				m1 = d[e -> v] + e -> w;
			} else if (d[e -> v] + e -> w > m2)
				m2 = d[e -> v] + e -> w;
		}
	d[u] = m1;
	if (ans < m1 + m2)
		ans = m1 + m2;
}

int work2()
{
	int ret = 2 * (n - 1) - work1() + 1;
	clr(d, 0);
	clr(p, 0);
	ans = 0;
	dfs2(1);
	return ret - ans + 1;
}

int main()
{
	//freopen("patrol.in", "r", stdin);
	//freopen("patrol.out", "w", stdout);

	int x;
	scanf("%d%d", &n, &x);
	rep(i, 1, n - 1)
	{
		int y, z;
		scanf("%d%d", &y, &z);
		ins(y, z);
		ins(z, y);
		edge[ne].rev = &edge[ne - 1];
		edge[ne - 1].rev = &edge[ne];
	}
	if (x == 1)
		printf("%d\n", 2 * n - 1 - work1());
	else
		printf("%d\n", work2());

	fclose(stdin);
	fclose(stdout);
	return 0;
}


