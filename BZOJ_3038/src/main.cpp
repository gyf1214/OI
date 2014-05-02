/*
 * main.cpp
 *
 *  Created on: May 2, 2014
 *      Author: gyf
 */

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
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
	int l, r;
	long long sum;
	bool flag;
	_node* son[2];

	void merge();
	long long query(int l, int r);
	void change(int l, int r);
}node[mm], *nn = node, *root;

long long a[mm];
int n;

void _node::merge()
{
	if (l == r)
		return;
	sum = son[0] -> sum + son[1] -> sum;
	flag = son[0] -> flag && son[1] -> flag;
}

long long _node::query(int l, int r)
{
	if (l <= this -> l && r >= this -> r)
		return this -> sum;
	int mid = (this -> l + this -> r) / 2;
	long long ans = 0;
	if (l <= mid)
		ans += son[0] -> query(l, r);
	if (r > mid)
		ans += son[1] -> query(l, r);
	return ans;
}

void _node::change(int l, int r)
{
	if (flag)
		return;
	if (this -> l == this -> r)
	{
		sum = (long long) sqrt(sum);
		if (sum <= 1)
			flag = true;
	} else {
		int mid = (this -> l + this -> r) / 2;
		if (l <= mid)
			son[0] -> change(l, r);
		if (r > mid)
			son[1] -> change(l, r);
		merge();
	}
}

_node* build(int l, int r)
{
	_node* ans = ++nn;
	ans -> l = l;
	ans -> r = r;
	if (l == r)
	{
		ans -> flag = false;
		ans -> son[0] = ans -> son[1] = NULL;
		ans -> sum = a[l];
	} else {
		int m = (l + r) / 2;
		ans -> son[0] = build(l, m);
		ans -> son[1] = build(m + 1, r);
		ans -> merge();
	}
	return ans;
}

int main()
{
	scanf("%d", &n);
	rep(i, 1, n)
		scanf("%lld", &a[i]);
	root = build(1, n);
	int q;
	scanf("%d", &q);
	rep(i, 1, q)
	{
		int k, l, r;
		scanf("%d%d%d", &k, &l, &r);
		if (l > r)
		{
			int t = l;
			l = r;
			r = t;
		}
		if (k == 0)
			root -> change(l, r);
		else
			printf("%lld\n", root -> query(l, r));
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
