/*
 * main.cpp
 *
 *  Created on: May 17, 2014
 *      Author: gyf
 */

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#define rep(i, a, b) for (int i =(a); i <= (b); ++i)
#define clr(i, a) memset(i, (a), sizeof(i))
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))
#define infi 0x7FFFFFFF
#define mm 20010
using namespace std;

struct _edge
{
	int u, v;
	_edge* next;
}edge[mm * 2];

int p[mm][100];
_edge* head[mm];
int depth[mm];
int n, m, k, ne;
int s[mm], t[mm];
int temp[mm];
bool vis[mm];
int belong[mm];

void ins(int u, int v)
{
	++ne;
	edge[ne].u = u;
	edge[ne].v = v;
	edge[ne].next = head[u];
	head[u] = &edge[ne];
}

void dfs1(int u)
{
	for (_edge* e = head[u]; e; e = e -> next)
		if (p[u][0] != e -> v)
		{
			p[e -> v][0] = u;
			depth[e -> v] = depth[u] + 1;
			dfs1(e -> v);
		}
}

int lca(int u, int v)
{
	if (depth[u] > depth[v])
	{
		int t = u;
		u = v;
		v = t;
	}
	for (int j = 100 - 1; j >= 0; --j)
	{
		int k = p[v][j];
		if (depth[k] >= depth[u])
			v = k;
	}
	if (u == v)
		return u;
	for (int j = 100 - 1; j >= 0; --j)
		if (p[u][j] != p[v][j])
		{
			u = p[u][j];
			v = p[v][j];
		}
	return p[u][0];
}

void work1()
{
	rep(i, 1, k)
		scanf("%d%d", &s[i], &t[i]);
	rep(i, 1, m)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		ins(u, v);
		ins(v, u);
	}
	depth[1] = 1;
	dfs1(1);
	rep(j, 1, 100 - 1)
		rep(i, 1, n)
			p[i][j] = p[p[i][j - 1]][j - 1];
	rep(i, 1, k)
	{
		int v = lca(s[i], t[i]);
		vis[v] = true;
		for (int u = s[i]; u != v; u = p[u][0])
			if (vis[u])
			{
				printf("NO\n");
				return;
			} else vis[u] = true;
		for (int u = t[i]; u != v; u = p[u][0])
			if (vis[u])
			{
				printf("NO\n");
				return;
			} else vis[u] = true;
	}
	printf("YES\n");
	rep(i, 1, k)
	{
		int v = lca(s[i], t[i]);
		printf("%d ", depth[s[i]] + depth[t[i]] - 2 * depth[v] + 1);
		for (int u = s[i]; u != v; u = p[u][0])
			printf("%d ", u);
		printf("%d ", v);
		int tp = 0;
		for (int u = t[i]; u != v; u = p[u][0])
			temp[tp++] = u;
		for (--tp; tp >= 0; --tp)
			printf("%d%c", temp[tp], tp == 0 ? '\n' : ' ');
	}
}

void dfs2(int u)
{
	for (_edge* e = head[u]; e; e = e -> next)
		if (p[u][0] !=  e -> v)
		{
			p[e -> v][0] = u;
			if (!vis[e -> v])
			{
				vis[e -> v] = true;
				dfs2(e -> v);
			} else {
			}
		}
}

void work()
{
	ne = 0;
	clr(vis, 0);
	clr(p, 0);
	clr(head, 0);
	scanf("%d%d%d", &n, &m, &k);
	if (n == m + 1)
		work1();
}

int main()
{
	int t;
	scanf("%d", &t);
	rep(i, 1, t)
		work();

	fclose(stdin);
	fclose(stdout);
}

