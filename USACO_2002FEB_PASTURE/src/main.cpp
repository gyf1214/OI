/*
 * main.cpp
 *
 *  Created on: Jan 27, 2014
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
#define clr(i, a) memset(i, a, sizeof(i))
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))
#define infi 0x7FFFFFFF
#define nm 50
#define mm nm * nm / 2
using namespace std;

bool f[mm][mm], f0[mm][mm];
int a[nm];
int n;

void work()
{
	clr(f, 0);
	f[0][0] = true;
	rep(i, 1, n)
	{
		memcpy(f0, f, sizeof(f));
		rep(j, 0, mm - 1)
			rep(k, 0, mm - 1)
				if (f0[j][k])
				{
					f[j][k] = true;
					if (j + a[i] < mm)
						f[j + a[i]][k] = true;
					if (k + a[i] < mm)
						f[j][k + a[i]] = true;
				}
	}
}

double space(int a, int b, int c)
{
	double p = (a + b + c + .0) / 2;
	return 100.0 * (sqrt(.0 + p * (p - a + .0) * (p - b + .0) * (p - c + .0)) + .0);
}

int main()
{
	freopen("pasture.in", "r", stdin);
	freopen("pasture.out", "w", stdout);

	scanf("%d", &n);
	int sum = 0;
	rep(i, 1, n)
	{
		scanf("%d", &a[i]);
		sum += a[i];
	}
	work();
	double ans = -1;
	rep(i, 1, sum / 2)
		rep(j, 1, sum / 2)
		{
			int k = sum - i - j;
			if (f[i][j] && i + j > k && abs(i - j) < k)
				ans = max(ans, space(i, j, k));
		}
	if (ans <= 0)
		ans = -1;
	printf("%.0lf\n", floor(ans));

	fclose(stdin);
	fclose(stdout);
	return 0;
}
