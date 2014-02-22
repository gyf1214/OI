/*
 * main.cpp
 *
 *  Created on: 2014-2-22
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
#define mm 1000
using namespace std;

int a[mm], b[mm];

int main()
{
	int t;
	scanf("%d", &t);
	rep(x, 1, t)
	{
		int n;
		scanf("%d", &n);
		rep(i, 1, n)
			scanf("%d", &a[i]);
		rep(i, 1, n)
			scanf("%d", &b[i]);
		sort(a + 1, a + 1 + n);
		sort(b + 1, b + 1 + n);
		long long ans = 0;
		rep(i, 1, n)
			ans += ((long long) a[i]) * ((long long) b[n - i + 1]);
		printf("Case #%d: %lld\n", x, ans);
	}
}


