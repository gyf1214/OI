/*
 * main.cpp
 *
 *  Created on: 2013-12-29
 *      Author: gyf
 */

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define clr(i, a) memset(i, a, sizeof(i))
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))
#define infi 0x7FFFFFFF
#define nm 1100000
#define mm 26000
using namespace std;

struct interval
{
	int l, r, v, id;
}q0[mm], q[mm], inter[mm], temp[mm];

int n, m, p;
int left[mm], right[mm], last[mm], v[nm];

struct _difl
{
	bool operator() (interval a, interval b)
	{
		return a.l < b.l;
	}
}difl;

struct _difr
{
	bool operator() (interval a, interval b)
	{
		return a.r < b.r;
	}
}difr;

struct _difv
{
	bool operator() (interval a, interval b)
	{
		return a.v < b.v;
	}
}difv;

void pre()
{
	scanf("%d%d", &n, &m);
	rep(i, 1, m)
	{
		scanf("%d%d%d", &q0[i].l, &q0[i].r, &q0[i].v);
		temp[i].id = i;
		temp[i].v = q0[i].v;
	}
	sort(temp + 1, temp + 1 + m, difv);
	int t = 0;
	rep(i, 1, m)
	{
		if (i == 1 || temp[i].v != temp[i - 1].v)
			++t;
		q0[temp[i].id].v = t;
	}
}

bool work(int l)
{
	if (l > m)
		return false;
	rep(i, 1, l)
		q[i] = q0[i];
	sort(q + 1, q + 1 + l, difl);
	rep(i, 1, m)
		right[i] = n;
	clr(left, 0);
	clr(last, 0);
	rep(i, 1, l)
	{
		left[q[i].v] = max(left[q[i].v], q[i].l);
		right[q[i].v] = min(right[q[i].v], q[i].r);
	}
	p = 0;
	rep(i, 1, m)
		if (left[i] != 0)
		{
			++p;
			inter[p].l = left[i];
			inter[p].r = right[i];
			inter[p].v = i;
		}
	sort(inter + 1, inter + 1 + p, difr);
	priority_queue<interval, vector<interval>, _difv> pq;
	int i1 = 1, i2 = 1;
	rep(i, 1, n)
	{
		for (; i1 <= l && q[i1].l == i; ++i1)
			pq.push(q[i1]);
		while (!pq.empty() && pq.top().r < i)
			pq.pop();
		if (pq.empty())
			v[i] = 0;
		else
			v[i] = pq.top().v;
		last[v[i]] = i;
		for (; i2 <= p && inter[i2].r == i; ++i2)
			if (last[inter[i2].v] < inter[i2].l)
				return false;
	}
	return true;
}

int main()
{
	freopen("bales.in", "r", stdin);
	freopen("bales.out", "w", stdout);

	pre();
	int gap = 1 << 16;
	int ans = 0;
	for (; gap; gap /= 2)
		if (work(ans + gap))
			ans += gap;
	printf("%d\n", (ans < m) ? (ans + 1) : 0);

	fclose(stdin);
	fclose(stdout);
	return 0;
}
