/*
 * main.cpp
 *
 *  Created on: 2013-9-14
 *      Author: gyf
 */

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define clr(i, a) memset(i, a, sizeof(i))
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))
#define infi 0x7FFFFFFF
#define mm 2600
using namespace std;

int dp[mm], s[mm];

int main()
{
	freopen("quad.in", "r", stdin);
	freopen("quad.out", "w", stdout);

	int n;
	scanf("%d", &n);
	int k;
	if (n % 2 == 1)
		k = n / 2;
	else
		k = n / 2 - 1;
	clr(dp, 0);
	clr(s, 0);
	rep(i, 1, k)
		dp[i] = 1;
	rep(i, 1, n)
		s[i] = s[i - 1] + dp[i];
	rep(i, 2, 4)
	{
		rep(j, 1, n)
			dp[j] = s[j - 1] - s[max(1, j - k) - 1];
		rep(j, 1, n)
			s[j] = s[j - 1] + dp[j];
	}

	printf("%d\n", dp[n]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}



