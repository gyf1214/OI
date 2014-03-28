/*
 * main.cpp
 *
 *  Created on: 2014-3-28
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
#define infill 0x7FFFFFFFFFFFFFFLL
#define infi 0x7FFFFFFF
#define nm 10000
#define mm 50000
using namespace std;

struct _edge
{
	int u, v, f;
	long long c;
	_edge* next, *rev;
}edge[mm];
int ne, n, s, t;
_edge* head[nm], *pre[nm];
long long q[mm], dis[nm];
bool vis[nm];

void ins(int u, int v, int f, int c)
{
	edge[ne].u = u, edge[ne].v = v, edge[ne].f = f, edge[ne].c = c;
	edge[ne].next = head[u];
	edge[ne].rev = edge + ne + 1;
	head[u] = edge + ne;
	++ne;
	edge[ne].u = v, edge[ne].v = u, edge[ne].f = 0, edge[ne].c = -c;
	edge[ne].next = head[v];
	edge[ne].rev = edge + ne - 1;
	head[v] = edge + ne;
	++ne;
}

bool spfa()
{
	clr(vis, 0);
	clr(pre, 0);
	rep(i, 1, n)
		dis[i] = -infill;
	dis[s] = 0;
	int l = 0, r = 1;
	q[0] = s;
	vis[s] = true;
	while (l != r)
	{
		int u = q[l];
		for (_edge* e = head[u]; e; e = e -> next)
		{
			int v = e -> v;
			if (e -> f > 0 && dis[v] < dis[u] + e -> c)
			{
				dis[v] = dis[u] + e -> c;
				pre[v] = e;
				if (!vis[v])
				{
					q[r] = v;
					r = (r + 1) % nm;
					vis[v] = true;
				}
			}
		}
		vis[u] = false;
		l = (l + 1) % nm;
	}

	return dis[t] != -infill;
}

long long mcmf()
{
	long long ans = 0;
	while (spfa())
	{
		int delta = infi;
		for (_edge* e = pre[t]; e; e = pre[e -> u])
			delta = min(delta, e -> f);
		for (_edge* e = pre[t]; e; e = pre[e -> u])
		{
			e -> f -= delta;
			e -> rev -> f += delta;
		}
		ans += dis[t] * (long long)delta;
	}
	return ans;
}

int main()
{
	int k, x, y;
	//scanf("%d%d%d", &k, &x, &y);
	scanf("%d", &x);
	y = x;
	k = 3;
	rep(i, 1, x)
		rep(j, 1, y)
		{
			int z;
			scanf("%d", &z);
			int u = 2 * (i - 1) * y + 2 * j;
			ins(u, u + 1, 1, z);
		}
	rep(i, 1, x - 1)
		rep(j, 1, y)
		{
			int u = 2 * (i - 1) * y + 2 * j;
			int v = 2 * i * y + 2 * j;
			ins(u, v, infi, 0);
			ins(u + 1, v, infi, 0);
		}
	rep(i, 1, x)
		rep(j, 1, y - 1)
		{
			int u = 2 * (i - 1) * y + 2 * j;
			int v = 2 * (i - 1) * y + 2 * (j + 1);
			ins(u, v, infi, 0);
			ins(u + 1, v, infi, 0);
		}
	s = 1, t = 2 * x * y + 2;
	n = t;
	ins(s, 2, k, 0);
	ins(2 * x * y + 1, t, infi, 0);
	ins(2 * x * y, t, infi, 0);
	printf("%lld\n", mcmf());

	fclose(stdin);
	fclose(stdout);
	return 0;
}

