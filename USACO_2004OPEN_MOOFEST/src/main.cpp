/*
 * main.cpp
 *
 *  Created on: 2013-7-16
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
#define mm 30000
#define lb(x) ((x)&(-(x)))
using namespace std;

long long sx[mm], ss[mm], s[mm], c[mm];
int n;

struct cow
{
	int v, x;
	friend bool operator <(cow a, cow b)
	{
		return a.x < b.x;
	}
}p[mm];

void insert(int index)
{
	int y = p[index].v;
	for (int i = y; i <= mm; i += lb(i))
	{
		sx[i] += p[index].x * y;
		ss[i] += p[index].x;
		s[i] += y;
		++c[i];
	}
}

long long _query(long long* a, int i)
{
	long long ans = 0;
	for (; i > 0; i -= lb(i))
		ans += a[i];
	return ans;
}

long long _query(long long* a, int s, int t)
{
	return _query(a, t) - _query(a, s - 1);
}

long long query(int index)
{
	long long xi = p[index].x;
	long long vi = p[index].v;
	return 	xi * vi * _query(c, 1, vi) +
			xi * _query(s, vi + 1, mm) -
			vi * _query(ss, 1, vi) -
			_query(sx, vi + 1, mm);
}


int main()
{
	freopen("moofest.in", "r", stdin);
	freopen("moofest.out", "w", stdout);

	scanf("%d", &n);
	clr(p, 0);
	rep(i, 1, n)
		scanf("%d%d", &(p[i].v), &(p[i].x));
	sort(p + 1, p + 1 + n);
	long long ans = 0;
	clr(s, 0);
	clr(ss, 0);
	clr(c, 0);
	clr(sx, 0);
	rep(i, 1, n)
	{
		ans += query(i);
		insert(i);
	}
	printf("%lld\n", ans);

	fclose(stdin);
	fclose(stdout);
	return 0;
}
