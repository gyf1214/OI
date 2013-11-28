/*
 * main.cpp
 *
 *  Created on: 2013-11-28
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
#define nm 210010
#define mm 5000010
using namespace std;

struct _edge
{
	int u, v;
	int weight, next;
}edge[mm];

int head[nm], ne;

int dis[nm];
int heap[nm], map[nm], hn;

int n;

inline void ins(int u, int v, int w)
{
	++ne;
	edge[ne].u = u;
	edge[ne].v = v;
	edge[ne].weight = w;
	edge[ne].next = head[u];
	head[u] = ne;
}

inline void swap(int i, int j)
{
	int t = heap[i];
	heap[i] = heap[j];
	heap[j] = t;
	map[heap[i]] = i;
	map[heap[j]] = j;
}

void up(int i)
{
	int j = i / 2;
	if (j > 0 && dis[heap[i]] < dis[heap[j]])
	{
		swap(i, j);
		up(j);
	}
}

void down(int i)
{
	int j = 2 * i;
	if (j + 1 < hn && dis[heap[j]] > dis[heap[j + 1]])
		++j;
	if (j < hn && dis[heap[j]] < dis[heap[i]])
	{
		swap(i, j);
		down(j);
	}
}

inline void push(int x)
{
	heap[hn] = x;
	map[x] = hn;
	up(hn);
	++hn;
}

inline int top()
{
	return heap[1];
}

inline void pop()
{
	--hn;
	swap(1, hn);
	down(1);
}

inline void del(int x)
{
	int i = map[x];
	int t = dis[x];
	dis[x] = -1;
	up(i);
	pop();
	dis[x] = t;
}

void dijistra(int s)
{
	clr(map, 0);
	rep(i, 1, n)
		dis[i] = infi;
	dis[s] = 0;
	hn = 1;
	rep(i, 1, n)
		push(i);
	rep(i, 1, n)
	{
		int u = top();
		map[u] = 0;
		pop();
		for (int e = head[u]; e; e = edge[e].next)
		{
			int v = edge[e].v;
			int w = edge[e].weight;
			if (map[v] && dis[v] - w > dis[u])
			{
				dis[v] = dis[u] + w;
				del(v);
				push(v);
			}
		}
	}
}

void pre()
{
	int m, k;
	scanf("%d%d%d", &n, &m, &k);
	rep(i, 1, m)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		rep(j, 0, k)
		{
			ins(j * n + x, j * n + y, z);
			ins(j * n + y, j * n + x, z);
		}
		rep(j, 1, k)
		{
			ins((j - 1) * n + x, j * n + y, 0);
			ins((j - 1) * n + y, j * n + x, 0);
		}
	}
	int t = n * (k + 1) + 1;
	rep(i, 0, k)
		ins(n * (i + 1), t, 0);
	n = t;
}

int main()
{
	freopen("revamp.in", "r", stdin);
	freopen("revamp.out", "w", stdout);

	pre();
	dijistra(1);
	printf("%d\n", dis[n]);

	fclose(stdin);
	fclose(stdout);
	return 0;
}
