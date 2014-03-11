/*
 * main.cpp
 *
 *  Created on: Mar 11, 2014
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
#define mm 1000100
#define lb(x) ((x) & (-(x)))
using namespace std;

long long s[mm];
long long v[mm];
long long n, l, c, vmax;

void modify(long long i, long long x)
{
	for (; i <= vmax + 10; i += lb(i))
		s[i] += x;
}

long long query(long long i)
{
	long long ans = 0;
	for (; i > 0; i -= lb(i))
		ans += s[i];
	return ans;
}

long long work()
{
	sort(v + 1, v + 1 + n, greater<long long>());
	vmax = v[1];
	long long sum = 0, ans = -n * (n - 1) / 2;
	rep(i, 1, n)
	{
		long long t = l * v[i] / vmax;
		long long k = l * v[i] % vmax;
		ans += sum - t * (i - 1);
		sum += t;
		ans += query(vmax - k);
		modify(vmax - k, 1);
	}
	return ans;
}

int main()
{
	freopen("running.in", "r", stdin);
	freopen("running.out", "w", stdout);

	scanf("%lld%lld%lld", &n, &l, &c);
	rep(i, 1, n)
		scanf("%lld", &v[i]);
	printf("%lld\n", work());

	fclose(stdin);
	fclose(stdout);
	return 0;
}
