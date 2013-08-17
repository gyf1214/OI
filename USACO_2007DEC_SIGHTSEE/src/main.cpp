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
#define mm 20000

int head[mm], next[mm], tail[mm], tim[mm], fine[mm];
double weight[mm], st, ed;
int n, ne;

void ins(int a, int b, int t, int f)
{
	next[++ne] = head[a];
	head[a] = ne;
	tail[ne] = b;
	tim[ne] = t;
	fine[ne] = f;
}

bool SPFA(double k, int s)
{
	rep(i, 1, ne)
		weight[i] = k * (tim[i] + .0) - fine[i];
	double dis[mm];
	int q[mm];
	int t[mm];
	bool vis[mm];
	clr(q, 0);
	clr(t, 0);
	clr(vis, 0);
	rep(i, 1, 2 * n)
		dis[i] = 1e99;
	int l = 0;
	int r = 1;
	q[0] = s;
	vis[s] = true;
	t[s] = 1;
	dis[s] = .0;
	while (r != l)
	{
		int u = q[l];
		for (int e = head[u]; e != 0; e = next[e])
		{
			int v = tail[e];
			if (dis[v] > dis[u] + weight[e])
			{
				dis[v] = dis[u] + weight[e];
				if (!vis[v])
				{
					if (++t[v] > n)
						return false;
					vis[v] = true;
					q[r] = v;
					r = (r + 1) % mm;
				}
			}
		}
		l = (l + 1) % mm;
		vis[u] = false;
	}
	return true;
}

void pre()
{
	int m, mini, sum;
	st = .0;
	sum = 0;
	mini = infi;
	ne = 0;
	scanf("%d%d", &n, &m);
	rep(i, 1, n)
	{
		int x;
		scanf("%d", &x);
		sum += x;
		ins(i, i + n, 0, x);
	}
	rep(i, 1, m)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		mini = min(mini, z);
		ins(x + n, y, z, 0);
	}
	rep(i, 1, n)
		ins(2 * n + 1, i, 0, 0);
	ed = (sum + .0) / (mini + .0);
}

int main()
{
	//freopen("sightsee.in", "r", stdin);
	//freopen("sightsee.out", "w", stdout);

	pre();
	while (ed - st > .0001)
	{
		double mid = (st + ed) / 2;
		if (!SPFA(mid, 2 * n + 1))
			st = mid;
		else
			ed = mid;
	}
	printf("%.2lf\n", st);

	fclose(stdin);
	fclose(stdout);
	return 0;
}
