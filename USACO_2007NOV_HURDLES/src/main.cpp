/*
 * main.cpp
 *
 *  Created on: 2013-8-4
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
#define max(a, b) (a)>(b)?(a):(b)
#define min(a, b) (a)<(b)?(a):(b)
#define infi 0x7FFFFFFF
#define mm 310

int dis[mm][mm];
int n, k;

void floyd()
{
	rep(k, 1, n)
		rep(i, 1, n)
			rep(j, 1, n)
				dis[i][j] = min(dis[i][j], max(dis[i][k], dis[k][j]));
}

void pre()
{
	int m;
	scanf("%d%d%d", &n, &m, &k);
	rep(i, 1, n)
		rep(j, 1, n)
			dis[i][j] = infi;
	rep(i, 1, n)
		dis[i][i] = 0;
	rep(i, 1, m)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		dis[x][y] = z;
	}
	floyd();
}

void work()
{
	rep(i, 1, k)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%d\n", dis[x][y] == infi?-1:dis[x][y]);
	}
}

int main()
{
	freopen("hurdles.in", "r", stdin);
	freopen("hurdles.out", "w", stdout);

	pre();
	work();

	fclose(stdin);
	fclose(stdout);
	return 0;
}
