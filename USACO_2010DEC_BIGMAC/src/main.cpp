/*
 * main.cpp
 *
 *  Created on: 2013-9-9
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
#define nm 5000
#define mm 26010
using namespace std;

struct _edge
{
	int s, t;
	double w;
}edge[mm];

double dist[nm][nm];

int n, m, s, t;

bool work()
{
	rep(i, 1, n)
		rep(j, 1, n)
			dist[i][j] = 1e99;
	rep(i, 1, n)
		dist[i][i] = 1.0;
	rep(i, 1, m)
		dist[edge[i].s][edge[i].t] = edge[i].w + .0;
	rep(i, 1, n)
		rep(j, 1, m)
			dist[edge[j].s][edge[j].t] = min(dist[edge[j].s][i] * dist[i][edge[j].t],
					dist[edge[j].s][edge[j].t]);
	bool flag = false;
	rep(i, 1, n)
		rep(j, 1, m)
			if (dist[edge[j].s][i] * dist[i][edge[j].t] < dist[edge[j].s][edge[j].t])
				flag = true;
	return flag;
}

int main()
{
	freopen("bigmac.in", "r", stdin);
	freopen("bigmac.out", "w", stdout);

	double k;
	scanf("%d%d%lf%d%d", &n, &m, &k, &s, &t);
	rep(i, 1, m)
		scanf("%d%d%lf", &edge[i].s, &edge[i].t, &edge[i].w);
	bool ret = work();
	if (ret || dist[s][t] == 0)
		printf("0\n");
	else
		printf("%.8lf\n", k * dist[s][t]);

	fclose(stdin);
	fclose(stdout);
	return 0;
}
