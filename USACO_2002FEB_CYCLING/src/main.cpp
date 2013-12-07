/*
 * main.cpp
 *
 *  Created on: 2013-12-7
 *      Author: gyf
 */

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define clr(i, a) memset(i, a, sizeof(i))
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))
#define infi 0x7FFFFFFF
#define mm 200
using namespace std;

int f[mm][mm][mm];
int n, e, d;

inline void modify(int& x, int y)
{
	x = max(x, y);
}

void work()
{
	clr(f, 0);
	rep(i, 0, d)
		for (int j = n; j >= 1; --j)
		{
			int t = e - f[i][j][0];
			modify(f[i][j - 1][t], f[i][j][0]);
			rep(k, 1, e)
			{
				int x = e - f[i][j][k];
				int s;
				for (s = 0; s * s < k; ++s);
				rep(t, 1, s)
					modify(f[i + 1][j][k - t * t], f[i][j][k] + t);
				for (s = 0; s * s < x; ++s);
				rep(t, 1, s)
					modify(f[i + 1][j - 1][x - t * t], f[i][j][k] + t);
			}
		}
}

int main()
{
	freopen("cycling.in", "r", stdin);
	freopen("cycling.out", "w", stdout);

	scanf("%d%d%d", &n, &e, &d);
	work();
	int ans = infi;
	rep(i, 0, d)
		rep(j, 1, n)
			rep(k, 0, e)
				if (f[i][j][k] >= d)
					ans = min(ans, i);
	printf("%d\n", ans);

	fclose(stdin);
	fclose(stdout);
	return 0;
}




