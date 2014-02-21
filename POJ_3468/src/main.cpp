/*
 * main.cpp
 *
 *  Created on: Feb 20, 2014
 *      Author: gyf
 */

#include <cstdlib>
#include <cstdio>
#include <cstring>
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
	long long val, length, tag;
}node[mm];

int size, height, n, a[mm];

void merge(int i)
{
	node[i].val = node[2 * i].val + node[2 * i + 1].val;
	node[i].length = node[2 * i].length + node[2 * i + 1].length;
}

void update(int i, long long c)
{
	node[i].val += c * node[i].length;
	node[i].tag += c;
}

void push(int i)
{
	if (node[i].tag != 0)
	{
		update(2 * i, node[i].tag);
		update(2 * i + 1, node[i].tag);
	}
	node[i].tag = 0;
}

void push_all(int i)
{
	for (int j = height; j > 0; --j)
		push(i >> j);
}

void modify(int l, int r, long long c)
{
	l += size - 1;
	r += size + 1;
	push_all(l);
	push_all(r);
	int ll = l;
	int rr = r;
	while (r - l > 1)
	{
		if (l % 2 == 0) update(l + 1, c);
		if (r % 2 == 1) update(r - 1, c);
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

long long query(int l, int r)
{
	l += size - 1;
	r += size + 1;
	push_all(l);
	push_all(r);
	long long ans = 0;
	while (r - l > 1)
	{
		if (l % 2 == 0) ans += node[l + 1].val;
		if (r % 2 == 1) ans += node[r - 1].val;
		l /= 2;
		r /= 2;
	}
	return ans;
}

void build()
{
	clr(node, 0);
	for (int i = n + 1; i > 0; i /= 2)
		++height;
	size = 1 << height;
	rep(i, 1, n)
	{
		node[i + size].val = a[i];
		node[i + size].length = 1;
	}
	for (int j = size - 1; j > 0; --j)
		merge(j);
}

int main()
{
	int m;
	scanf("%d%d", &n, &m);
	rep(i, 1, n)
		scanf("%d", &a[i]);
	build();
	rep(i, 1, m)
	{
		char str[100];
		int l, r;
		scanf("%s%d%d", str, &l, &r);
		if (*str == 'Q')
		{
			printf("%lld\n", query(l, r));
		} else {
			int c;
			scanf("%d", &c);
			modify(l, r, c);
		}
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}


