/*
 * main.cpp
 *
 *  Created on: Mar 2, 2014
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
#define mm 100010
#define eps 1e-9
using namespace std;

struct _node
{
	double a, b, rate;
	double ans, x, y;
	int t;

	bool update(double k)
	{
		if (k > ans)
		{
			ans = k;
			y = ans / (rate * a + b);
			x = y * rate;
			return true;
		}
		return false;
	}
}node[mm];

int rank[mm], temp[mm], s1[mm], s2[mm], top1, top2;
int n;

int cmp(double a)
{
	return fabs(a) <= eps ? 0 : (a > -eps ? 1 : -1);
}

bool tk(int a, int b, int c)
{
	double x = (node[c].y - node[b].y) * (node[b].x - node[a].x)
			- (node[b].y - node[a].y) * (node[c].x - node[b].x);
	return cmp(x) > 0 || (cmp(node[c].x - node[b].x) == 0 && node[c].y < node[b].y);
}

double calc(int j, int i)
{
	return node[j].x * node[i].a + node[j].y * node[i].b;
}

bool cmpx(int i, int j)
{
	return cmp(node[j].x - node[i].x) > 0 ||
		(cmp(node[j].x - node[i].x) == 0 && cmp(node[j].y - node[j].y) <= 0);
}

bool cmpk(int i, int j)
{
	return node[i].a / node[i].b > node[j].a / node[j].b;
}

void solve(int l, int r)
{
	if (l >= r)
		return;
	int low = infi, high = 0;
	rep(i, l, r)
	{
		low = min(low, rank[i]);
		high = max(high, rank[i]);
	}
	int mid = (low + high) / 2;
	top1 = top2 = 0;
	rep(i, low, high)
		if (rank[i] <= mid)
			s1[++top1] = rank[i];
		else
			s2[++top2] = rank[i];
	rep(i, 1, top1)
		rank[l + i - 1] = s1[i];
	mid = l + top1 - 1;
	rep(i, 1, top2)
		rank[mid + i] = s2[i];
	solve(l, mid);
	int top = 0;
	temp[0] = rank[l];
	rep(i, l + 1, mid)
	{
		for (; top > 0 && !tk(temp[top - 1], temp[top], rank[i]); --top);
		temp[++top] = rank[i];
	}
	double maxf = .0;
	int maxk;
	rep(i, l, mid)
		if (node[rank[i]].ans > maxf)
		{
			maxf = max(node[rank[i]].ans, maxf);
			maxk = rank[i];
		}
	int j = 0;
	rep(i, mid + 1, r)
	{
		for (;j < top && calc(temp[j], rank[i]) <= calc(temp[j + 1], rank[i]); ++j);
		if (node[rank[i]].update(maxf))
			node[rank[i]].t = maxk;
		if (node[rank[i]].update(calc(temp[j], rank[i])))
			node[rank[i]].t = temp[j];
	}
	solve(mid + 1, r);
	int k = 0;
	j = l;
	rep(i, mid + 1, r)
	{
		for (; j <= mid && cmpx(rank[i], rank[j]); ++j)
			temp[++k] = rank[j];
		temp[++k] = rank[i];
	}
	for (; j <= mid; ++j)
		temp[++k] = rank[j];
	rep(i, 1, k)
		rank[l + i - 1] = temp[i];
}

int main()
{
	//freopen("cash.in", "r", stdin);
	//freopen("cash.out", "w", stdout);
	clr(node, 0);
	double x;
	scanf("%d%lf", &n, &x);
	rep(i, 1, n)
	{
		scanf("%lf%lf%lf", &node[i].a, &node[i].b, &node[i].rate);
		rank[i] = i;
	}
	node[1].update(x);
	sort(rank + 1, rank + 1 + n, cmpk);
	solve(1, n);
	//rep(i, 1, n)
		//printf("%5d %5d %10.3lf\n", i , node[i].t, node[i].ans);
	printf("%.3lf\n", node[n].ans);

	fclose(stdin);
	fclose(stdout);
	return 0;
}



