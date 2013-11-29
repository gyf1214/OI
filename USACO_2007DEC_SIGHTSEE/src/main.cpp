/*
 * main.cpp
 *
 *  Created on: 2013-7-22
 *      Author: gyf
 */


#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define clr(i, a) memset(i, a, sizeof(a))
#define max(a, b) (a)>(b)?(a):(b)
#define min(a, b) (a)<(b)?(a):(b)
#define infi 0x7FFFFFFF
#define mm 40000
using namespace std;

struct _edge
{
	int u, v;
	int time, fine;
}edge[mm];
int n, ne;
double st, ed;
double dis[mm];

void pre()
{
	int m, mini, sum;
	st = .0;
	sum = 0;
	mini = infi;
	scanf("%d%d", &n, &m);
	rep(i, 1, n)
	{
		int x;
		scanf("%d", &x);
		sum += x;
		++ne;
		edge[ne].u = i;
		edge[ne].v = i + n;
		edge[ne].fine = x;
		edge[ne].time = 0;
	}
	rep(i, 1, m)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		mini = min(mini, z);
		++ne;
		edge[ne].u = x + n;
		edge[ne].v = y;
		edge[ne].fine = 0;
		edge[ne].time = z;
	}
	rep(i, 1, n)
	{
		++ne;
		edge[ne].u = 0;
		edge[ne].v = i;
		edge[ne].time = 0;
		edge[ne].fine = 0;
	}
	ed = (sum + .0) / (mini + .0);
}

bool ford(double k)
{
	rep(i, 1, 2 * n)
		dis[i] = 1e99;
	dis[0] = 0;
	rep(i, 0, 2 * n)
		rep(j, 1, ne)
		{
			double weight = k * (edge[j].time + .0) - (edge[j].fine - .0);
			int u = edge[j].u;
			int v = edge[j].v;
			if (dis[v] - weight > dis[u])
				dis[v] = dis[u] + weight;
		}
	rep(j, 1, ne)
	{
		double weight = k * (edge[j].time + .0) - (edge[j].fine - .0);
		int u = edge[j].u;
		int v = edge[j].v;
		if (dis[v] - weight > dis[u])
			return false;
	}
	return true;
}

int main()
{
	freopen("sightsee.in", "r", stdin);
	freopen("sightsee.out", "w", stdout);

	pre();
	while (ed - st > .0001)
	{
		double mid = (st + ed) / 2;
		if (!ford(mid))
			st = mid;
		else
			ed = mid;
	}
	printf("%.2lf\n", ed);

	fclose(stdin);
	fclose(stdout);
	return 0;
}
