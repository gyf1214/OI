/*
 * main.cpp
 *
 *  Created on: Mar 26, 2014
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
#define mm
using namespace std;

int p[] = {
		1,
		1,
		1,
		1,
		1,
		1,
		33,
		97,
		225,
		481,
		993,
		993,
		993,
		993,
		993,
		993,
		33761,
		99297,
		230369,
		492513,
		1016801,
		1016801,
		1016801,
		1016801,
		1016801,
		1016801,
};

int ans, n, m, x;
int f[34000000];
int s;

void dfs1(int k)
{
	if (k == n / 2 + 1)
	{
		++f[s];
		return;
	}
	rep(i, 1, 26)
	{
		int t = s;
		s = ((33 * s) ^ i) % (1 << m);
		dfs1(k + 1);
		s = t;
	}
}

void dfs2(int k)
{
	if (k == n / 2)
	{
		ans += f[s];
		return;
	}
	rep(i, 1, 26)
	{
		int t = s;
		s = ((long long)(s ^ i) * (long long)p[m]) % (1 << m);
		dfs2(k - 1);
		s = t;
	}
}

int main()
{
	freopen("hash.in", "r", stdin);
	freopen("hash.out", "w", stdout);

	scanf("%d%d%d", &n, &x, &m);
	clr(f, 0);
	s = 0;
	dfs1(1);
	s = x;
	dfs2(n);
	printf("%d\n", ans);

	fclose(stdin);
	fclose(stdout);
	return 0;
}
