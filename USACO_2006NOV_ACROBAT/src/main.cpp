/*
 * main.cpp
 *
 *  Created on: 2013-7-27
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
#define mm 50010
using namespace std;

struct cow
{
	int w, s;
	friend bool operator <(cow a, cow b)
	{
		return (a.w + a.s) < (b.w + b.s);
	}
}c[mm];

int main()
{
	freopen("acrobat.in", "r", stdin);
	freopen("acrobat.out", "w", stdout);

	int n;
	scanf("%d", &n);
	rep(i, 1, n)
		scanf("%d%d", &(c[i].w), &(c[i].s));
	sort(c + 1, c + 1 + n);
	int ans = -infi;
	int sum = 0;
	rep(i, 1, n)
	{
		ans = max(ans, sum - c[i].s);
		sum += c[i].w;
	}
	printf("%d\n", ans);

	fclose(stdin);
	fclose(stdout);
	return 0;
}



