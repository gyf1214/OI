/*
 * main.cpp
 *
 *  Created on: Mar 13, 2014
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
#define mm 200030
#define offset 100010
#define lb(x) ((x) & (-(x)))
using namespace std;

long long s[mm];

void add(int i, int x)
{
	for (; i < mm; i += lb(i))
		s[i] += x;
}

long long query(int i)
{
	long long ans = 0;
	for (; i > 0; i -= lb(i))
		ans += s[i];
	return ans;
}

int main()
{
	freopen("median.in", "r", stdin);
	freopen("median.out", "w", stdout);

	int sum = 0;
	long long ans = 0;
	int k, n;
	add(sum + offset, 1);
	scanf("%d%d", &n, &k);
	rep(i, 1, n)
	{
		int x;
		scanf("%d", &x);
		sum += x >= k ? 1 : -1;
		ans += query(sum + offset);
		add(sum + offset, 1);
	}

	printf("%lld\n", ans);

	fclose(stdin);
	fclose(stdout);
	return 0;
}


