/*
 * main.cpp
 *
 *  Created on: 2013-12-14
 *      Author: gyf
 */

#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#define rep(i, a, b) for (long long i = (a); i <= (b); ++i)
#define clr(i, a) memset(i, a, sizeof(i))
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)>(b)?(a):(b))
#define infi 0x7FFFFFFFLL
#define nm 600
#define mm 10010
using namespace std;

struct _node
{
	long long x, c, f;
	inline friend bool operator <(_node a, _node b)
	{
		return a.x < b.x;
	}
}node[nm];
long long f[mm], f0[mm];
long long q[mm], l, r;
long long n, m, e;

inline long long calc(long long i, long long j, long long k)
{
	return f0[k] + k * k * node[i].x + node[i].c * (j - k);
}

inline long long pop(long long i, long long j)
{
	while (r > l && q[l] < j - node[i].f)
		++l;
	return q[l];
}

inline void push(long long i, long long j, long long k)
{
	while (r > l && calc(i, j, k) <= calc(i, j, q[r - 1]))
		--r;
	q[r] = k;
	r++;
}

void work()
{
	rep(i, 1, m)
		f[i] = infi * infi;
	f[0] = 0;
	rep(i, 1, n)
	{
		l = r = 0;
		rep(j, 0, m)
			f0[j] = f[j];
		f[0] = 0;
		push(i, 0, 0);
		rep(j, 1, m)
		{
			push(i, j, j);
			long long k = pop(i, j);
			f[j] = calc(i, j, k);
		}
	}
}

void pre()
{
	scanf("%lld%lld%lld", &m, &e, &n);
	rep(i, 1, n)
		scanf("%lld%lld%lld", &node[i].x, &node[i].f, &node[i].c);
	sort(node + 1, node + 1 + n);
	e -= node[n].x;
	for (long long i = n; i >= 2; --i)
		node[i].x -= node[i - 1].x;
}

int main()
{
	freopen("feed.in", "r", stdin);
	freopen("feed.out", "w", stdout);

	pre();
	work();
	printf("%lld\n", f[m] + m * m * e);

	fclose(stdin);
	fclose(stdout);
	return 0;
}


