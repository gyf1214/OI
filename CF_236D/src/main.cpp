/*
 * main.cpp
 *
 *  Created on: Jun 1, 2014
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
#define mm 100010
using namespace std;

double p[mm], dp[mm], f[mm];
int n;

double work()
{
	dp[0] = .0;
	f[0] = .0;
	rep(i, 1, n)
	{
		f[i] = (f[i - 1] + 1) * p[i];
		dp[i] = dp[i - 1] + (2 * f[i - 1] + 1) * p[i];
	}
	return dp[n];
}

int main()
{
	scanf("%d", &n);
	rep(i, 1, n)
		scanf("%lf", &p[i]);
	printf("%.15lf\n", work());

	fclose(stdin);
	fclose(stdout);
	return 0;
}


