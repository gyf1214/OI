/*
 * main.cpp
 *
 *  Created on: 2013-11-3
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
#define nm 110
#define mm 40010
using namespace std;

int f[mm], g[mm];
int v[nm], c[nm];
int a[mm], b[mm];
int n, m, l, r;

void ins(int x, int y)
{
	while (l <= r && b[r] >= y)
		--r;
	++r;
	a[r] = x;
	b[r] = y;
}

int top(int i, int j)
{
	while (a[l] < j - c[i])
		++l;
	return b[l];
}

void work1()
{
	rep(i, 0, mm - 1)
		f[i] = infi / 3;
	f[0] = 0;
	rep(i, 1, n)
	{
		if ((mm - 1) / v[i] < c[i])
			c[i] = (mm - 1) / v[i];
		rep(k, 0, v[i] - 1)
		{
			l = 1, r = 0;
			rep(j, 0, (mm - 1 - k) / v[i])
			{
				ins(j, f[j * v[i] + k] - j);
				f[j * v[i] + k] = top(i, j) + j;
			}
		}
	}
}

void work2()
{
	rep(i, 0, mm - 1)
		g[i] = infi / 3;
	g[0] = 0;
	rep(i, 1, n)
		rep(j, 0, mm - 1)
			if (j >= v[i])
				g[j] = min(g[j], g[j - v[i]] + 1);
}

int main()
{
	freopen("fewcoins.in", "r", stdin);
	freopen("fewcoins.out", "w", stdout);

	scanf("%d%d", &n, &m);
	rep(i, 1, n)
		scanf("%d", &v[i]);
	rep(i, 1, n)
		scanf("%d", &c[i]);

	work1();
	work2();
	int ans = infi / 3;
	rep(i, 0, mm - m - 1)
		ans = min(ans, g[m + i] + f[i]);
	printf("%d\n", ans == infi / 3 ? -1 : ans);

	fclose(stdin);
	fclose(stdout);
	return 0;
}
