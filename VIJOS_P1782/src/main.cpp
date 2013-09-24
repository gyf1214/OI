/*
 * main.cpp
 *
 *  Created on: 2013-9-24
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
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))
#define infi 0x7FFFFFFF
#define mm 1000010

struct _req
{
	int s, t, d;
}req[mm];

int a[mm], b[mm], n, m;

bool work(int k)
{
	rep(i, 1, n)
		b[i] = a[i];
	rep(i, 1, k)
	{
		b[req[i].s] -= req[i].d;
		b[req[i].t + 1] += req[i].d;
	}
	int x = 0;
	rep(i, 1, n)
	{
		x += b[i];
		if (x < 0)
			return false;
	}
	return true;
}

int main()
{
	scanf("%d%d", &n, &m);
	rep(i, 1, n)
		scanf("%d", a + i);
	rep(i, 1, m)
		scanf("%d%d%d", &req[i].d, &req[i].s, &req[i].t);
	for (int i = n; i > 1; --i)
		a[i] = a[i] - a[i - 1];
	int l = 1, r = m + 1;
	while (r - l > 1)
	{
		int mid = (l + r) / 2;
		if (work(mid))
			l = mid;
		else
			r = mid;
	}
	if (work(m))
		printf("0\n");
	else
		printf("-1\n%d\n", l + 1);
	return 0;
}
