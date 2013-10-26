/*
 * main.cpp
 *
 *  Created on: 2013-10-22
 *      Author: gyf
 */

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <iostream>
#include <algorithm>
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define clr(i, a) memset(i, a, sizeof(i))
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))
#define infi 0x7FFFFFFF
#define nm 500
#define mm 250000
using namespace std;

struct _edge
{
	int u, v;
	int next;
}edge[mm];

struct _node
{
	int head;
	int x, y;
	double dis;
}node[nm];

_node* heap[nm];

int n, ne, nh;

inline bool operator <(_node& a, _node& b)
{
	return a.dis < b.dis;
}

inline double dis(_node* u, _node* v)
{
	return sqrt((u->x - v->x) * (u->x - v->x) +
			(u->y - v->y) * (u->y - v->y));
}

inline void ins(int u, int v)
{
	edge[++ne].next = node[u].head;
	node[u].head = ne;
	edge[ne].u = u;
	edge[ne].v = v;
}

void dijistra(int s)
{
	rep(i, 1, n)
		node[i].dis = 1e100;
	node[s].dis = .0;
	nh = 1;
	heap[0] = node + s;
	make_heap(heap, heap + nh, less<_node*>());
	rep(i, 1, n)
	{
		pop_heap(heap, heap + nh, less<_node*>());
		--nh;
		for (int e = heap[nh]->head; e; e = edge[e].next)
		{
			int v = edge[e].v;
			push_heap(heap, heap + nh, less<_node*>());
		}
	}
}

