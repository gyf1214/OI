/*
 * main.cpp
 *
 *  Created on: Feb 19, 2014
 *      Author: gyf
 */

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define clr(i, a) memset(i, (a), sizeof(i))
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))
#define infi 0x7FFFFFFF
#define mm 10010
using namespace std;

double a[mm];
int n, k;

double work()
{
	double l = .0, r = 200000.0;
	while (r - l > .0001)
	{
		double m = (l + r) / 2.0;
		int ans = 0;
		rep(i, 1, n)
			ans += floor(a[i] / m);
		if (ans < k)
			r = m;
		else
			l = m;
	}
	return l;
}

int main()
{
	scanf("%d%d", &n, &k);
	rep(i, 1, n)
		scanf("%lf", &a[i]);
	printf("%.2lf\n", work());

	fclose(stdin);
	fclose(stdout);
	return 0;
}


