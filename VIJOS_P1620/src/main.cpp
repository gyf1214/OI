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
#define mm 400010
using namespace std;

struct _node
{
	int length;
	int lsum, rsum, sum, val;
	int tag, time;
	_node()
	{
		length = 0;
		lsum = rsum = sum = val = 0;
		tag = time = 0;
	}
}node[mm];

int size, height;

struct _tree
{
	int father, son, top;
	int depth, size, weight;
	int index;
}tree[mm];

int ns, n;

struct _edge
{
	int u, v;
	_edge* next;
}edge[mm];

_edge* head[mm];
int ne;

_node merge_node(_node l, _node r)
{
	_node ret;
	ret.length = l.length + r.length;
	ret.sum = l.sum + r.sum;
	ret.lsum = max(l.lsum, l.sum + r.lsum);
	ret.rsum = max(r.rsum, r.sum + l.rsum);
	ret.val = max(max(l.val, r.val), l.rsum + r.lsum);
	return ret;
}

void merge(int i)
{
	node[i] = merge_node(node[2 * i], node[2 * i + 1]);
}

void update(int i, int x, int t)
{
	if (node[i].time > t)
		return;
	node[i].sum = x * node[i].length;
	node[i].val = node[i].lsum = node[i].rsum = x > 0 ? x : 0;
	node[i].tag = x;
	node[i].time = t;
}

void push_down(int i)
{
	if (node[i].time != 0)
	{
		update(2 * i, node[i].tag, node[i].time);
		update(2 * i + 1, node[i].tag, node[i].time);
	}
	node[i].time = 0;
}

void push_all(int i)
{
	for (int j = height; j; --j)
		push_down(i >> j);
}

void modify(int l, int r, int x, int t)
{
	l += size - 1;
	r += size + 1;
	int ll = l, rr = r;
	push_all(l);
	push_all(r);
	while (r - l > 1)
	{
		if (l % 2 == 0) update(l + 1, x, t);
		if (r % 2 == 1) update(r - 1, x, t);
		l /= 2;
		r /= 2;
	}
	while (ll > 0 && rr > 0)
	{
		ll /= 2;
		rr /= 2;
		merge(ll);
		merge(rr);
	}
}

_node query(int l, int r)
{
	l += size - 1;
	r += size + 1;
	push_all(l);
	push_all(r);
	_node ll, rr;
	while (r - l > 1)
	{
		if (l % 2 == 0)
			ll = merge_node(ll, node[l + 1]);
		if (r % 2 == 1)
			rr = merge_node(node[r - 1], rr);
		l /= 2;
		r /= 2;
	}
	return merge_node(ll, rr);
}

inline void swap(int& x, int& y)
{
	int t = x;
	x = y;
	y = t;
}

inline void swap(_node& x, _node& y)
{
	_node t = x;
	x = y;
	y = t;
}

void modify_tree(int u, int v, int x, int t)
{
	while (tree[u].top != tree[v].top)
	{
		if (tree[tree[u].top].depth < tree[tree[v].top].depth)
			swap(u, v);
		int t = tree[u].top;
		if (t == u)
		{
			modify(tree[u].index, tree[u].index, x, t);
			u = tree[u].father;
		} else {
			modify(tree[tree[t].son].index, tree[u].index, x, t);
			u = t;
		}
	}
	if (tree[u].depth > tree[v].depth)
		swap(u, v);
	modify(tree[u].index, tree[v].index, x, t);
}

int query_tree(int u, int v)
{
	_node uu, vv;
	while (tree[u].top != tree[v].top)
	{
		if (tree[tree[u].top].depth < tree[tree[v].top].depth)
		{
			swap(u, v);
			swap(uu, vv);
		}
		int t = tree[u].top;
		if (t == u)
		{
			uu = merge_node(query(tree[u].index, tree[u].index), uu);
			u = tree[u].father;
		} else {
			uu = merge_node(query(tree[tree[t].son].index, tree[u].index), uu);
			u = t;
		}
	}
	if (tree[u].depth > tree[v].depth)
	{
		swap(u, v);
		swap(uu, vv);
	}
	swap(uu.lsum, uu.rsum);
	return merge_node(merge_node(uu, query(tree[u].index, tree[v].index)), vv).val;
}

inline void ins(int u, int v)
{
	++ne;
	edge[ne].u = u;
	edge[ne].v = v;
	edge[ne].next = head[u];
	head[u] = &edge[ne];
}

void dfs(int u)
{
	tree[u].size = 1;
	for (_edge* e = head[u]; e; e = e -> next)
		if (e -> v != tree[u].father)
		{
			int v = e -> v;
			tree[v].father = u;
			tree[v].depth = tree[u].depth + 1;
			dfs(v);
			tree[u].size += tree[v].size;
			if (tree[u].son == 0 || tree[tree[u].son].size < tree[v].son)
				tree[u].son = v;
		}
}

void build_tree(int u, int t)
{
	tree[u].index = ++ns;
	tree[u].top = t;
	if (tree[u].son != 0)
		build_tree(tree[u].son, t);
	for (_edge* e = head[u]; e; e = e -> next)
		if (e -> v != tree[u].son && e -> v != tree[u].father)
			build_tree(e -> v, e -> v);
}

void build(int n)
{
	height = 0;
	for (int i = n + 1; i; i /= 2)
		++height;
	size = 1 << height;
	rep(i, 1, n)
	{
		node[tree[i].index + size].length = 1;
		update(tree[i].index + size, tree[i].weight, 0);
	}
	for (int i = size - 1; i; --i)
		merge(i);
}

int main()
{
	scanf("%d", &n);
	rep(i, 1, n)
		scanf("%d", &tree[i].weight);
	ne = 0;
	rep(i, 1, n - 1)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		ins(x, y);
		ins(y, x);
	}
	dfs(1);
	ns = 0;
	build_tree(1, 1);
	build(ns);
	int m;
	scanf("%d", &m);
	bool flag = false;
	rep(i, 1, m)
	{
		int c, x, y, z;
		scanf("%d", &c);
		if (c == 1)
		{
			scanf("%d%d", &x, &y);
			printf("%s%d", flag ? " " : "", query_tree(x, y));
			flag = true;
		} else {
			scanf("%d%d%d", &x, &y, &z);
			modify_tree(x, y, z, i);
		}
	}
	printf("\n");

	fclose(stdin);
	fclose(stdout);
	return 0;
}

