/*
 * main.cpp
 *
 *  Created on: 2013-12-20
 *      Author: gyf
 */

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#define rep(i, a, b) for (long long i = (a); i <= (b); ++i)
#define clr(i, a) memset(i, (a), sizeof(i))
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))
#define infi 0x7FFFFFFF
#define mm 50010
using namespace std;

struct _node
{
	long long h, w;
	inline friend bool operator <(_node a, _node b)
	{
		return a.h < b.h || (a.h == b.h && a.w < b.w);
	}
}a[mm], b[mm];
long long dp[mm];
long long q[mm], l, r;
long long n;

void pre()
{
	scanf("%lld", &n);
	rep(i, 1, n)
		scanf("%lld%lld", &a[i].h, &a[i].w);
	sort(a + 1, a + 1 + n);
	long long k = 1;
	rep(i, 1, n)
	{
		b[k] = a[i];
		while (k > 1 && b[k].w >= b[k - 1].w && b[k].h >= b[k - 1].h)
		{
			b[k - 1] = b[k];
			--k;
		}
		++k;
	}
	n = k - 1;
}

inline void push(long long j)
{
	while (r - l > 1 &&
			(dp[j - 1] - dp[q[r - 1] - 1]) * (b[q[r - 2]].w - b[q[r - 1]].w) <=
			(dp[q[r - 1] - 1] - dp[q[r - 2] - 1]) * (b[q[r - 1]].w - b[j].w))
		--r;
	q[r] = j;
	++r;
}

inline long long pop(long long i)
{
	while (r - l > 1 &&
			dp[q[l] - 1] + b[i].h * b[q[l]].w >=
			dp[q[l + 1] - 1] + b[i].h * b[q[l + 1]].w)
		++l;
	return q[l];
}

void work()
{
	l = r = 0;
	dp[0] = 0;
	dp[1] = b[1].w * b[1].h;
	push(1);
	rep(i, 2, n)
	{
		long long j = pop(i);
		dp[i] = min(dp[j - 1] + b[i].h * b[j].w, dp[i - 1] + b[i].h * b[i].w);
		push(i);
	}
}

int main()
{
	freopen("acquire.in", "r", stdin);
	freopen("acquire.out", "w", stdout);

	pre();
	work();
	printf("%lld\n", dp[n]);

	fclose(stdin);
	fclose(stdout);
	return 0;
}

