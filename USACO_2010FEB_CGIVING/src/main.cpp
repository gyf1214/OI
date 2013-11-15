/*
 * main.cpp
 *
 *  Created on: 2013-11-15
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
#define min(a, b) ((a)>(b)?(a):(b))
#define infi 0x7FFFFFFF
#define nm 50010
#define mm 200010
using namespace std;

struct _edge
{
	int start, tail;
	int weight, next;
}edge[mm];
int head[nm], ne, n;

int dis[nm];
int heap[nm], map[nm], hn;

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
	int j = i * 2;
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

void dijkstra(int s)
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
			int v = edge[e].tail;
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

inline void ins(int u, int v, int w)
{
	edge[ne].next = head[u];
	edge[ne].start = u;
	edge[ne].tail = v;
	edge[ne].weight = w;
	head[u] = ne;
	++ne;
}

int main()
{
	freopen("cgiving.in", "r", stdin);
	freopen("cgiving.out", "w", stdout);

	int m, b;
	scanf("%d%d%d", &n, &m, &b);
	ne = 1;
	rep(i, 1, m)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		ins(u, v, w);
		ins(v, u, w);
	}
	dijkstra(1);
	rep(i, 1, b)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		printf("%d\n", dis[u] + dis[v]);
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
