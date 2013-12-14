/*
 * main.cpp
 *
 *  Created on: 2013-12-14
 *      Author: gyf
 */

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define clr(i, a) memset(i, a, sizeof(i))
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))
#define infi 0x7FFFFFFF
#define mm 100010
using namespace std;

int a[mm], f[mm], g[mm];
int q[mm], l, r;
int n;

inline void push(int j)
{
	while (r > l && a[j] - f[j + 1] >= a[q[r - 1]] - f[q[r - 1] + 1])
		--r;
	q[r] = j;
	++r;
}

inline int pop(int i)
{
	while (r > l && a[q[l]] - f[q[l] + 1] >= a[i - 1])
		++l;
	return q[l - 1];
}

void work()
{
	clr(f, 0);
	l = r = 0;
	for (int i = n; i >= 1; --i)
	{
		push(i);
		int j = pop(i);
		g[i] = j;
		f[i] = a[j] - a[i - 1];
	}
}

void pre()
{
	clr(a, 0);
	scanf("%d", &n);
	rep(i, 1, n)
	{
		int x;
		scanf("%d", &x);
		a[i] = a[i - 1] + x;
	}
}

int main()
{
	freopen("tower.in", "r", stdin);
	freopen("tower.out", "w", stdout);

	pre();
	work();
	int now = 1, ans = 0;
	while (now <= n)
	{
		now = g[now] + 1;
		++ans;
	}
	printf("%d\n", ans);

	fclose(stdin);
	fclose(stdout);
	return 0;
}
