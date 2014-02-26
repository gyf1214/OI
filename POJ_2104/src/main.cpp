/*
 * main.cpp
 *
 *  Created on: Feb 26, 2014
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
#define mm 4000010
#define nm 100010
using namespace std;

struct _node
{
	int val, l, r;
	_node *lch, *rch;
}node[mm];
int nt;
_node* version[nm];

struct _number
{
	int index, val;
	inline friend bool operator <(_number a, _number b)
	{
		return a.val < b.val;
	}
}temp[nm];
int a[nm], b[nm], n, m;


_node* update(_node* u, int i)
{
	++nt;
	_node* v = node + nt;
	*v = *u;
	++(v -> val);
	if (v -> l < v -> r)
	{
		int m = (v -> l + v -> r) / 2;
		if (i <= m)
			v -> lch = update(v -> lch, i);
		else
			v -> rch = update(v -> rch, i);
	}
	return v;
}

int query(int l, int r, int k)
{
	_node *lu = version[l - 1], *ru = version[r];
	while (lu -> lch)
	{
		int t = ru -> lch -> val - lu -> lch -> val;
		if (t >= k)
		{
			lu = lu -> lch;
			ru = ru -> lch;
		} else {
			k -= t;
			lu = lu -> rch;
			ru = ru -> rch;
		}
	}
	return lu -> l;
}

_node* build(int l, int r)
{
	++nt;
	_node* v = node + nt;
	v -> l = l;
	v -> r = r;
	v -> val = 0;
	if (l < r)
	{
		int m = (l + r) / 2;
		v -> lch = build(l, m);
		v -> rch = build(m + 1, r);
	}
	return v;
}

void pre()
{
	scanf("%d%d", &n, &m);
	rep(i, 1, n)
	{
		scanf("%d", &temp[i].val);
		temp[i].index = i;
	}
	sort(temp + 1, temp + 1 + n);
	int k = 1;
	rep(i, 1, n)
	{
		a[temp[i].index] = k;
		b[k] = temp[i].val;
		if (i < n && temp[i].val != temp[i + 1].val)
			++k;
	}
	version[0] = build(1, k);
	rep(i, 1, n)
		version[i] = update(version[i - 1], a[i]);
}

int main()
{
	pre();
	rep(i, 1, m)
	{
		int l, r, k;
		scanf("%d%d%d", &l, &r, &k);
		int t = query(l, r, k);
		printf("%d\n", b[t]);
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
