/*
 * main.cpp
 *
 *  Created on: 2013-7-19
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
#define mm 200000

int s[mm], n, m, height, size;

inline void merge(int i)
{
	s[i] = min(s[2 * i], s[2 * i + 1]);
}

void pre()
{
	scanf("%d%d", &n, &m);
	height = 0;
	for (int i = n + 1; i > 0; i /= 2)
		++height;
	size = 1 << height;
	clr(s, 0);
	rep(i, 1, n)
		scanf("%d", s + size + i);
	for (int i = size - 1; i > 0; --i)
		merge(i);
}

int query(int l, int r)
{
	l += size - 1;
	r += size + 1;
	int ret = infi;
	while (r - l >= 2)
	{
		if (r % 2 == 1) ret = min(ret, s[r - 1]);
		if (l % 2 == 0) ret = min(ret, s[l + 1]);
		r /= 2;
		l /= 2;
	}
	return ret;
}

int main()
{
	freopen("cavecow2.in", "r", stdin);
	freopen("cavecow2.out", "w", stdout);

	pre();
	rep(i, 1, m)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%d\n", query(l, r));
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}


