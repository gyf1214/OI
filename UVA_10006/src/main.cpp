/*
 * main.cpp
 *
 *  Created on: 2014-2-22
 *      Author: gyf
 */

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#define rep(i, a, b) for (long long i = (a); i <= (b); ++i)
#define clr(i, a) memset(i, (a), sizeof(i))
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))
#define infi 0x7FFFFFFF
#define mm 70000
using namespace std;

bool flag[mm];

void prime()
{
	clr(flag, 0);
	rep(i, 2, mm - 1)
		if (!flag[i])
			for (long long j = i * i; j < mm; j += i)
				flag[j] = true;
}

bool check(long long x, long long n)
{
	long long s = 1, y = x;
	for (long long i = n; i > 0; i /= 2)
	{
		if (i % 2 == 1) s = (s * y) % n;
		y = (y * y) % n;
	}
	return s % n == x % n;
}

int main()
{
	long long n;
	prime();
	scanf("%lld", &n);
	while (n != 0)
	{
		bool ans = flag[n];
		if (ans)
			rep(i, 2, n - 1)
				if (!check(i, n))
				{
					ans = false;
					break;
				}
		if (ans)
			printf("The number %lld is a Carmichael number.\n", n);
		else
			printf("%lld is normal.\n", n);
		scanf("%lld", &n);
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
