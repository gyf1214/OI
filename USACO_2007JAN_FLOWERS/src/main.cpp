/*
 * main.cpp
 *
 *  Created on: 2013-8-25
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
#define mm 100010
using namespace std;

struct _cow
{
	int t, d;
	friend bool operator <(_cow a, _cow b)
	{
		return a.t * b.d < b.t * a.d;
	}
}cow[mm];
int n;

int main()
{
	freopen("flowers.in", "r", stdin);
	freopen("flowers.out", "w", stdout);

	scanf("%d", &n);
	rep(i, 1, n)
		scanf("%d%d", &cow[i].t, &cow[i].d);
	sort(cow + 1, cow + n + 1);
	long long ans = 0;
	int now = 0;
	rep(i, 1, n)
	{
		ans += cow[i].d * now;
		now += cow[i].t * 2;
	}
	printf("%lld\n", ans);

	fclose(stdin);
	fclose(stdout);
	return 0;
}
