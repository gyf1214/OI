/*
 * main.cpp
 *
 *  Created on: 2013-11-26
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
#define mm 200010
using namespace std;

struct _node
{
	int s, left, right, length;
	bool lazy;
	int tag;
}node[mm];

int height, size;

inline void update(int i, int t, bool d)
{
	if (node[i].tag > t)
		return;
	node[i].lazy = d;
	node[i].tag = t;
	if (d)
		node[i].left = node[i].right = node[i].s = node[i].length;
	else
		node[i].left = node[i].right = node[i].s = 0;
}

inline void push(int i)
{
	if (node[i].tag != 0)
	{
		update(2 * i, node[i].tag, node[i].lazy);
		update(2 * i + 1, node[i].tag, node[i].lazy);
		node[i].tag = 0;
	}
}

inline void merge(int i)
{
	node[i].length = node[2 * i].length + node[2 * i + 1].length;
	node[i].s = max(node[2 * i].s, node[2 * i + 1].s);
	node[i].s = max(node[i].s, node[2 * i].right + node[2 * i + 1].left);
	node[i].left = node[2 * i].left;
	if (node[2 * i].left == node[2 * i].length)
		node[i].left += node[2 * i + 1].left;
	node[i].right = node[2 * i + 1].right;
	if (node[2 * i + 1].right == node[2 * i + 1].length)
		node[i].right += node[2 * i].right;
}

void push_all(int i)
{
	for (int k = height; k > 0; k -= 1)
		push(i >> k);
}

void fill(int l, int r, int t, bool d)
{
	l += size - 1;
	r += size + 1;
	int ll = l;
	int rr = r;
	push_all(l);
	push_all(r);
	while (r - l > 1)
	{
		if (l % 2 == 0) update(l + 1, t, d);
		if (r % 2 == 1) update(r - 1, t, d);
		l /= 2;
		r /= 2;
	}
	while (ll > 1 && rr > 1)
	{
		ll /= 2;
		rr /= 2;
		merge(ll);
		merge(rr);
	}
}

void build(int n)
{
	height = 0;
	for (int t = n + 1; t > 0; t /= 2)
		++height;
	size = 1 << height;
	clr(node, 0);
	rep(i, 0, size - 1)
		node[i + size].length = 1;
	rep(i, 1, n)
		update(i + size, 0, true);
	for (int i = size - 1; i > 0; --i)
		merge(i);
}

int query(int k)
{
	if (node[1].s < k)
		return 0;
	int now = 1;
	int prefix = 0;
	int suffix = 0;
	int lmax = 0;
	int rmax = 0;
	while (now < size)
	{
		int l = now * 2;
		int r = now * 2 + 1;
		push(now);
		int lmax1 = max(node[l].s, lmax);
		int rmax1 = max(node[r].s, rmax);
		int prefix1 = node[l].right;
		if (node[l].right == node[l].length)
			prefix1 += prefix;
		int suffix1 = node[r].left;
		if (node[r].left == node[r].length)
			suffix1 += suffix;
		if (lmax1 >= k || prefix1 + suffix1 >= k)
		{
			suffix = suffix1;
			rmax = rmax1;
			now = l;
		} else {
			prefix = prefix1;
			lmax = lmax1;
			now = r;
		}
	}
	if (node[now].right == 0)
		++now;
	return now - size;
}

void work()
{
	int m;
	scanf("%d", &m);
	rep(i, 1, m)
	{
		int x;
		scanf("%d", &x);
		if (x == 1)
		{
			int y;
			scanf("%d", &y);
			int ans = query(y);
			printf("%d\n", ans);
			if (ans != 0)
				fill(ans, ans + y - 1, i, false);
		} else {
			int y, z;
			scanf("%d%d", &y, &z);
			fill(y, y + z - 1, i, true);
		}
	}
}

void pre()
{
	int n;
	scanf("%d", &n);
	build(n);
}

int main()
{
	freopen("hotel.in", "r", stdin);
	freopen("hotel.out", "w", stdout);

	pre();
	work();

	fclose(stdin);
	fclose(stdout);
	return 0;
}


