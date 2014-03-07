/*
 * main.cpp
 *
 *  Created on: Mar 7, 2014
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
#define nm 40010
#define mm 1000010
using namespace std;

struct _edge
{
	int u, v, w, f;
	_edge* next, *other;
}edge[mm];

_edge* head[nm],* head1[nm];

int d[nm], q[nm];
int s, t, delta;
int n, ne;

bool bfs()
{
	clr(d, 0);
	int l = 0, r = 1;
	q[0] = s;
	d[s] = 1;
	while (r > l)
	{
		int u = q[l++];
		for (_edge* e = head[u]; e; e = e -> next)
		{
			int v = e -> v;
			if (!d[v])
			{
				if (e -> w > 0)
				{
					if (e -> f < e -> w)
					{
						d[v] = d[u] + 1;
						q[r++] = v;
					}
				} else {
					e -= ne;
					if (e -> f > 0)
					{
						d[v] = d[u] + 1;
						q[r++] = v;
					}
					e += ne;
				}
			}
		}
	}
	return d[t] != 0;
}

bool dfs(int u, int k)
{
	if (u == t)
	{
		delta = k;
		return true;
	}
	for (_edge* e = head1[u]; e; e = e -> next)
	{
		int v = e -> v;
		if (d[v] == d[u] + 1)
		{
			if (e -> w > 0)
			{
				if (e -> f < e -> w && dfs(v, min(k, e -> w - e -> f)))
				{
					e -> f += delta;
					return true;
				}
			} else {
				e -= ne;
				if (e -> f > 0 && dfs(v, min(k, e -> f)))
				{
					e -> f -= delta;
					return true;
				}
				e += ne;
			}
			head1[u] = e;
		}
	}

	return false;
}

_edge* ins(int u, int v, int w)
{
	++ne;
	edge[ne].u = u;
	edge[ne].v = v;
	edge[ne].w = w;
	edge[ne].f = 0;
	edge[ne].next = head[u];
	head[u] = &edge[ne];

	return &edge[ne];
}

void pre()
{
	int m;
	scanf("%d%d", &n, &m);
	ne = 0;
	s = n + 1, t = n + 2;
	rep(i, 1, n)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		ins(s, i, x);
		ins(i, t, y);
	}
	rep(i, 1, m)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		ins(x, y, z);
		ins(y, x, z);
	}
	rep(i, 1, ne)
	{
		edge[i + ne].u = edge[i].v;
		edge[i + ne].v = edge[i].u;
		edge[i + ne].w = -edge[i].w;
		edge[i + ne].next = head[edge[i].v];
		head[edge[i].v] = &edge[i + ne];
	}
}

int dinic()
{
	int ans = 0;
	while (bfs())
	{
		memcpy(head1, head, sizeof(head));
		while (dfs(s, infi))
			ans += delta;
	}
	return ans;
}

int main()
{
	pre();
	printf("%d\n", dinic());

	fclose(stdin);
	fclose(stdout);
	return 0;
}
