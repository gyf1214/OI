/*
 * main.cpp
 *
 *  Created on: Mar 8, 2014
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
#define mm 6000010
#define nm 10010
using namespace std;

struct _node
{
	long long val, tag;
}node[mm];

int height, size;

struct _vertex
{
	long long x, y, w;
	inline friend bool operator <(_vertex a , _vertex b)
	{
		return a.y < b.y;
	}
}v[mm];

int n, k, f;

void merge(int i)
{
	node[i].val = max(node[2 * i].val, node[2 * i + 1].val);
}

void update(int i, long long x)
{
	node[i].val += x;
	node[i].tag += x;
}

void push_down(int i)
{
	if (node[i].tag != 0)
	{
		update(2 * i, node[i].tag);
		update(2 * i + 1, node[i].tag);
		node[i].tag = 0;
	}
}

void push_all(int i)
{
	for (int j = height; j; --j)
		push_down(i >> j);
}

void modify(int l, int r, long long x)
{
	l += size - 1;
	r += size + 1;
	int ll = l, rr = r;
	push_all(l);
	push_all(r);
	while (r - l > 1)
	{
		if (l % 2 == 0) update(l + 1, x);
		if (r % 2 == 1) update(r - 1, x);
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

long long query(int l, int r)
{
	l += size - 1;
	r += size + 1;
	push_all(l);
	push_all(r);
	long long ans = 0;
	while (r - l > 1)
	{
		if (l % 2 == 0) ans = max(ans, node[l + 1].val);
		if (r % 2 == 0) ans = max(ans, node[r - 1].val);
		l /= 2;
		r /= 2;
	}
	return ans;
}

void pre()
{
	long long a, b;
	scanf("%d%d%lld%lld%d", &n, &f, &a, &b, &k);
	rep(i, 1, k)
	{
		long long x1, y1;
		scanf("%lld%lld%lld%lld", &v[i].x, &v[i].y, &x1, &y1);
		v[i].w = a * x1 + b * y1;
	}
	sort(v + 1, v + 1 + k);
	clr(node, 0);
	height = 0;
	for (int i = n + 1; i; i /= 2)
		++height;
	size = 1 << height;
}

int work()
{
	int j = 0;
	int ans = 0;
	rep(i, 1, n)
	{
		while (j < n && v[j + 1].y <= v[i].y + f)
		{
			++j;
			modify(v[j].x - f, v[j].x, v[j].w);
		}
		ans = max(ans, node[1].val);
		modify(v[i].x - f, v[i].x, -v[j].w);
	}
	return ans;
}

int main()
{
	pre();
	printf("%d\n", work());
}

