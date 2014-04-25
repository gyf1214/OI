/*
 * main.cpp
 *
 *  Created on: Apr 25, 2014
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
#define nm 60010
#define mm 480010
using namespace std;

struct _edge
{
	int u, v;
	int f;
	_edge *next, *rev;
}edge[mm];

_edge* head[nm], *qe[nm];
int d[nm], q[nm];
int ne, s, t, delta, sum;

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

bool bfs()
{
	int l = 0, r = 1;
	clr(d, 0);
	q[0] = s;
	d[s] = 1;
	while (r > l)
	{
		int u = q[l++];
		for (_edge* e = head[u]; e; e = e -> next)
		{
			int v = e -> v;
			if (d[v] == 0 && e -> f > 0)
			{
				d[v] = d[u] + 1;
				q[r++] = v;
			}
		}
	}
	return d[t] != 0;
}

int dfs()
{
	int top = 1, ret = 0;
	while (top)
	{
		int u = top == 1 ? s : qe[top - 1] -> v;
		if (u == t)
		{
			int f = infi;
			int back;
			rep(i, 1, top - 1)
				if (qe[i] -> f < f)
				{
					f = qe[i] -> f;
					back = i;
				}
			rep(i, 1, top - 1)
			{
				qe[i] -> f -= f;
				qe[i] -> rev -> f += f;
			}
			ret += f;
			top = back;
		} else {
			_edge* e = NULL;
			for (e = head[u]; e; e = e -> next)
			{
				int v = e -> v;
				if (d[v] == d[u] + 1 && e -> f > 0)
					break;
			}
			if (e)
				qe[top++] = e;
			else
			{
				--top;
				d[u] = 0;
			}
		}
	}
	return ret;
}

int work()
{
	int ans = 0;
	while (bfs())
		ans += dfs();
	return ans;
}

void pre()
{
	int n, m;
	scanf("%d%d", &n, &m);
	s = 1, t = n + m + 2;
	rep(i, 1, n)
	{
		int x;
		scanf("%d", &x);
		ins(s, i + 1, x);
	}
	sum = 0;
	rep(i, 1, m)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		sum += z;
		ins(i + 1 + n, t, z);
		ins(1 + x, i + 1 + n, infi);
		ins(1 + y, i + 1 + n, infi);
	}
}

int main()
{
	pre();
	printf("%d\n", sum - work());

	fclose(stdin);
	fclose(stdout);
	return 0;
}


