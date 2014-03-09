/*
 * main.cpp
 *
 *  Created on: Mar 9, 2014
 *      Author: gyf
 */

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <iostream>
#include <algorithm>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define clr(i, a) memset(i, (a), sizeof(i))
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))
#define infi 0x7FFFFFFF
#define mm 100010
using namespace std;

long long s[mm];
int n;

int main()
{
	freopen("restack.in", "r", stdin);
	freopen("restack.out", "w", stdout);

	scanf("%d", &n);
	clr(s, 0);
	rep(i, 1, n)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		s[i] = s[i - 1] + (long long)a - (long long)b;
	}
	sort(s + 1, s + 1 + n);
	long long k = s[(n + 1) / 2];
	long long ans = 0;
	rep(i, 1, n)
		ans += abs(s[i] - k);
	printf("%lld\n", ans);

	fclose(stdin);
	fclose(stdout);
}


