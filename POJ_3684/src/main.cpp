/*
 * main.cpp
 *
 *  Created on: Mar 1, 2014
 *      Author: gyf
 */

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define clr(i, a) memset(i, (a), sizeof(i))
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))
#define infi 0x7FFFFFFF
#define mm 10010
using namespace std;

const double g = 10.0;

double a[mm];

double work(int h, int t)
{
	if (t <= 0)
		return h;
	double k = 2 * sqrt(2.0 * (h + .0) / g);
	double f = fmod(t, k);
	if (f > k / 2.0)
	{
		return h + .0 - (k - f) * (k - f) * g / 2;
	} else {
		return h + .0 - f * f * g / 2;
	}
}

int main()
{
	int c;
	int n, h, r, t;
	while (scanf("%d", &c) != EOF)
		rep(i, 1, c)
		{
			scanf("%d%d%d%d", &n, &h, &r, &t);
			rep(i, 1, n)
				a[i] = work(h, t - i + 1);
			sort(a + 1, a + 1 + n);
			rep(i, 1, n)
				printf("%0.2lf%c", a[i] + 2.0 * (r + .0) * (i - 1) / 100.0, i == n ? '\n' : ' ');
		}

	fclose(stdin);
	fclose(stdout);
	return 0;
}

