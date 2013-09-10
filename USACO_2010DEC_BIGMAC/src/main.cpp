/*
 * main.cpp
 *
 *  Created on: 2013-9-9
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
#define nm 5000
#define mm 26010
#define mini 1e-9
using namespace std;

struct _edge
{
	int s, t;
	double w;
}edge[mm];

double dist[nm];

int n, m, s, t;

int cmp(double a, double b)
{
	if (abs(a - b + .0) < mini)
		return 0;
	if (a > b)
		return 1;
	else
		return -1;
}

bool work(int s)
{
	rep(i, 1, n)
		dist[i] = 1e99;
	dist[s] = 1.0;
	rep(i, 1, n)
		rep(j, 1, m)
			dist[edge[j].t] = min(dist[edge[j].s] * edge[j].w, dist[edge[j].t]);
	bool flag = false;
	rep(i, 1, m)
		if (cmp(dist[edge[i].s] * edge[i].w, dist[edge[i].t]) < 0)
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
	bool ret = work(s);
	if (ret || dist[t] == .0)
		printf("0\n");
	else
		printf("%.8lf\n", k * dist[t]);

	fclose(stdin);
	fclose(stdout);
	return 0;
}
