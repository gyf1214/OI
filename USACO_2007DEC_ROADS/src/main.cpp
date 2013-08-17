/*
 * main.cpp
 *
 *  Created on: 2013-7-22
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
#define max(a, b) (a)>(b)?(a):(b)
#define min(a, b) (a)<(b)?(a):(b)
#define infi 0x7FFFFFFF
#define mm 2000

bool link[mm][mm];
int x[mm], y[mm];
int n;

inline double dis(int a, int b)
{
	if (link[a][b])
		return .0;
	else
		return 	sqrt((.0 + x[a] - x[b]) * (.0 + x[a] - x[b])
				+ (.0 + y[a] - y[b]) * (.0 + y[a] - y[b]));
}

double work()
{
	double ans = .0;
	double cost[mm];
	rep(i, 2, n)
		cost[i] = dis(1, i);
	cost[1] = -1;
	rep(i, 1, n - 1)
	{
		double s = infi;
		int k;
		rep(j, 1, n)
			if (cost[j] > -1 && s > cost[j])
			{
				s = cost[j];
				k = j;
			}
		ans += cost[k];
		cost[k] = -1;
		rep(j, 1, n)
			if (dis(j, k) < cost[j])
				cost[j] = dis(j, k);
	}
	return ans;
}

int main()
{
	freopen("roads.in", "r", stdin);
	freopen("roads.out", "w", stdout);

	int m;
	scanf("%d%d", &n, &m);
	clr(link, 0);
	rep(i, 1, n)
		scanf("%d%d", x + i, y + i);
	rep(i, 1, m)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		link[a][b] = link[b][a] = true;
	}
	printf("%.2lf\n", work());

	fclose(stdin);
	fclose(stdout);
	return 0;
}




