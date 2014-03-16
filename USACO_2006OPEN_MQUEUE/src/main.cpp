/*
 * main.cpp
 *
 *  Created on: Mar 16, 2014
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
#define mm 25010
using namespace std;

struct _cow
{
	int a, b;
	inline friend bool operator <(_cow a, _cow b)
	{
		return max(a.a + a.b + b.b, a.a + b.a + b.b) <
				max(b.a + b.b + a.b, b.a + a.a + a.b);
	}
}cow[mm];

int n;

int main()
{
	freopen("mqueue.in", "r", stdin);
	freopen("mqueue.out", "w", stdout);

	scanf("%d", &n);
	rep(i, 1, n)
		scanf("%d%d", &cow[i].a, &cow[i].b);
	sort(cow + 1, cow + 1 + n);
	int sa = 0, sb = 0, ans = 0;
	rep(i, 1, n)
		sb += cow[i].b;
	rep(i, 1, n)
	{
		sa += cow[i].a;
		ans = max(ans, sa + sb);
		sb -= cow[i].b;
	}
	printf("%d\n", ans);

	fclose(stdin);
	fclose(stdout);
	return 0;
}


