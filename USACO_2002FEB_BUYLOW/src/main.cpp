/*
 * main.cpp
 *
 *  Created on: 2013-12-28
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
#define mm 6000
using namespace std;

int a[mm], n;
int l[mm];
int f[mm], g[mm];

void work()
{
	clr(l, 0);
	clr(f, 0);
	clr(g, 0);
	a[0] = infi;
	g[0] = 1;
	n += 1;
	a[n] = 0;
	rep(i, 1, n)
		for (l[i] = i - 1; l[i] > 0 && a[i] != a[l[i]]; --l[i]);
	rep(i, 1, n)
	{
		rep(j, l[i], i - 1)
			if (a[j] > a[i])
				f[i] = max(f[i], f[j] + 1);
		rep(j, l[i], i - 1)
			if (a[j] > a[i] && f[i] == f[j] + 1)
				g[i] += g[j];
	}
}

int main()
{
	freopen("buylow.in", "r", stdin);
	freopen("buylow.out", "w", stdout);

	scanf("%d", &n);
	rep(i, 1, n)
		scanf("%d", a + i);
	work();
	printf("%d %d", f[n] - 1, g[n]);
}

