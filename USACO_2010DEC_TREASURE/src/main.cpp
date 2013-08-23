/*
 * main.cpp
 *
 *  Created on: 2013-8-23
 *      Author: gyf
 */

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define clr(i, a) memset(i, a, sizeof(i))
#define max(a, b) (a)>(b):(a)?(b)
#define min(a, b) (a)<(b):(a)?(b)
#define infi 0x7FFFFFFF
#define mm 5010
using namespace std;

int c[mm], f[mm][2], f0[mm][2];
int n;

int work()
{
	clr(f, 0);
	clr(f0, 0);
	int t = n % 2;
	rep(i, 1, n)
		f[i][t] = c[i];
	rep(l, 2, n)
	{
		rep(i, 1, n)
		{
			f0[i][0] = f[i][0];
			f0[i][1] = f[i][1];
		}
		t = 1 - t;
		rep(i, 1, n - l + 1)
		{
			int j = i + l - 1;
			if (f0[i][t] + c[j] > f0[i + 1][t] + c[i])
			{
				f[i][t] = f0[i][t] + c[j];
				f[i][1 - t] = f0[i][1 - t];
			} else {
				f[i][t] = f0[i + 1][t] + c[i];
				f[i][1 - t] = f0[i + 1][1 - t];
			}
		}
	}
	return f[1][1];
}

int main()
{
	freopen("treasure.in", "r", stdin);
	freopen("treasure.out", "w", stdout);

	scanf("%d", &n);
	rep(i, 1, n)
		scanf("%d", c + i);
	printf("%d\n", work());

	fclose(stdin);
	fclose(stdout);
	return 0;
}


