/*
 * main.cpp
 *
 *  Created on: 2013-8-16
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
#define max(a, b) (a)>(b)?(a):(b)
#define min(a, b) (a)<(b)?(a):(b)
#define infi 0x7FFFFFFF
#define abs(x) (((x) > 0) ? (x) : (-(x)))
#define mm 400010
using namespace std;

struct _interval
{
	int num;
	long long val;
	bool st;
	friend bool operator < (_interval a, _interval b)
	{
		return (a.val < b.val) || (a.st < b.st && a.val == b.val);
	}
}inter[mm];

struct _line
{
	int st, ed;
	int nextl, nextr;
	long long minl, minr;
}line[mm];

int n;
int s[mm], lazy[mm], height, size;

long long dis(int i, int j)
{
	if (i == 0)
		return abs(inter[j].val);
	if (j == 0)
		return abs(inter[i].val);
	return abs(inter[j].val - inter[i].val);
}

void merge(int i)
{
	s[i] = max(s[2 * i], s[2 * i + 1]);
}

void update(int i, int x)
{
	lazy[i] = max(lazy[i], x);
	s[i] = x;
}

void push_down(int i)
{
	if (lazy[i] == 0)
		return;
	update(2 * i, lazy[i]);
	update(2 * i + 1, lazy[i]);
	lazy[i] = 0;
}

void push_all(int i)
{
	for (int k = height; k > 0; --k)
		push_down(i >> k);
}

void build(int n)
{
	clr(s, 0);
	clr(lazy, 0);
	height = 0;
	for (int i = n + 1; i > 0; i /= 2)
		++height;
	size = 1 << height;
}

void add(int i, int k)
{
	int l = line[i].st + size - 1;
	int r = line[i].ed + size + 1;
	push_all(l);
	push_all(r);
	int ll = l;
	int rr = r;
	while (r - l >= 2)
	{
		if (l % 2 == 0) update(l + 1, k);
		if (r % 2 == 1) update(r - 1, k);
		l /= 2;
		r /= 2;
	}
	rep(i, 1, height)
	{
		ll /= 2;
		rr /= 2;
		merge(ll);
		merge(rr);
	}
}

int query(int i)
{
	int ans = 0;
	int l = i + size - 1;
	int r = i + size + 1;
	push_all(l);
	push_all(r);
	while (r - l >= 2)
	{
		if (l % 2 == 0) ans = max(ans, s[l + 1]);
		if (r % 2 == 1) ans = max(ans, s[r - 1]);
		l /= 2;
		r /= 2;
	}
	return ans;
}

void pre()
{
	int t;
	scanf("%d%d", &n, &t);
	clr(inter, 0);
	clr(line, 0);
	n += 1;
	inter[1].val = t;
	inter[1].num = 1;
	inter[1].st = true;
	inter[n + 1].val = t;
	inter[n + 1].num = 1;
	inter[n + 1].st = false;
	for (int i = n; i >= 2; --i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		inter[i].val = x;
		inter[i].num = i;
		inter[i].st = true;
		inter[i + n].val = y;
		inter[i + n].num = i;
		inter[i + n].st = false;
	}
	sort(inter + 1, inter + n + n);
	rep(i, 1, n + n)
	{
		if (inter[i].st)
			line[inter[i].num].st = i;
		else
			line[inter[i].num].ed = i;
	}
	build(n + n);
}

int work()
{
	for (int i = n; i >= 1; --i)
	{
		line[i].nextl = n - query(line[i].st) + 1;
		line[i].nextr = n - query(line[i].ed) + 1;
		add(i, n - i + 1);
	}
	rep(i, 2, n + 1)
	{
		line[i].minl = line[i].minr = infi;
	}
	rep(i, 1, n)
	{
		int l = line[i].nextl;
		int r = line[i].nextr;
		line[l].minl = min(line[l].minl, line[i].minl + dis(line[i].st, line[l].st));
		line[l].minr = min(line[l].minr, line[i].minl + dis(line[i].st, line[l].ed));
		line[r].minl = min(line[r].minl, line[i].minr + dis(line[i].ed, line[r].st));
		line[r].minr = min(line[r].minr, line[i].minr + dis(line[i].ed, line[r].ed));
	}
	return min(line[n + 1].minl, line[n + 1].minr);
}

int main()
{
	freopen("obstacle.in", "r", stdin);
	freopen("obstacle.out", "w", stdout);

	pre();
	printf("%d\n", work());

	fclose(stdin);
	fclose(stdout);
	return 0;
}
