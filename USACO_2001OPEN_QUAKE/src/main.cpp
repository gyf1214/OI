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
#define mm 10010
using namespace std;

int n, m, f;
double k;
int p[mm];

int find(int u)
{
	if (p[u] != u)
		p[u] = find(p[u]);
	return p[u];
}

void merge(int u, int v)
{
	u = find(u);
	v = find(v);
	p[u] = v;
}

struct _edeg
{
	int start, tail, cost, time;
	double weight;
	inline friend bool operator < (_edeg a, _edeg b)
	{
		return a.weight < b.weight;
	}
}edeg[mm];

bool check(double t)
{
	k = t;
	double ans = .0;
	rep(i, 1, n)
		p[i] = i;
	rep(i, 1, m)
		edeg[i].weight = (edeg[i].time + .0) * k + edeg[i].cost;
	sort(edeg + 1, edeg + 1 + m);
	rep(i, 1, m)
	{
		int u = edeg[i].start;
		int v = edeg[i].tail;
		if (find(u) != find(v))
		{
			ans += edeg[i].weight;
			merge(u, v);
		}
	}
	return ans > (f + .0);
}

void pre()
{
	scanf("%d%d%d", &n, &m, &f);
	rep(i, 1, m)
		scanf("%d%d%d%d", &(edeg[i].start), &(edeg[i].tail), &(edeg[i].cost), &(edeg[i].time));
}

void work()
{
	double l = .0;
	double r = f + .0;
	while (r - l > .000001)
	{
		double mid = (l + r) / 2;
		if (check(mid))
			r = mid;
		else
			l = mid;
	}
	printf("%.4lf\n", l);
}

int main()
{
	freopen("quake.in", "r", stdin);
	freopen("quake.out", "w", stdout);

	pre();
	work();

	fclose(stdin);
	fclose(stdout);
	return 0;
}
