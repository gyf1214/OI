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
#define mm 20
using namespace std;

long long p10[mm];

inline int bit(int k, int t)
{
	return (k / p10[t]) % 10;
}

void work(int k, long long * ret)
{
	rep(i, 0, 9)
		ret[i] = 0;
	int t;
	for (t = 0; k >= p10[t]; ++t);
	--t;
	for (int i = t; i >= 0; --i)
	{
		int now = bit(k, i);
		for (int j = t; j > i; --j)
			ret[bit(k, j)] += now * p10[i];
		rep(j, 0, now - 1)
		{
			ret[j] += p10[i];
			if (i != 0)
				rep(k, 0, 9)
					ret[k] += i * p10[i - 1];
		}
	}
	ret[0] -= t + 1;
	rep(i, 1, t)
		ret[0] -= (t - i + 1) * 9 * p10[i - 1];
}

int main()
{
	freopen("dream.in", "r", stdin);
	freopen("dream.out", "w", stdout);

	p10[0] = 1;
	rep(i, 1, mm - 1)
		p10[i] = 10 * p10[i - 1];
	int a, b;
	long long ans1[10], ans2[10];
	scanf("%d%d", &a, &b);
	work(a, ans1);
	work(b + 1, ans2);
	rep(i, 0, 8)
		printf("%lld ", ans2[i] - ans1[i]);
	printf("%lld\n", ans2[9] - ans1[9]);

	fclose(stdin);
	fclose(stdout);
	return 0;
}


