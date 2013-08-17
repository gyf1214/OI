/*
 * main.cpp
 *
 *  Created on: 2013-8-3
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
#define mm 510
using namespace std;

struct _node
{
	int num, weight;
	friend bool operator < (_node a, _node b)
	{
		return a.weight < b.weight;
	}
}node[mm];

int dis[mm][mm], ans[mm][mm], rank[mm];
int n, k;

void floyd()
{
	rep(i, 1, n)
		rep(j, 1, n)
			ans[i][j] = infi;
	rep(k, 1, n)
		rep(i, 1, n)
			rep(j, 1, n)
			{
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
				int t = max(node[i].weight, node[j].weight);
				t = max(t, node[k].weight);
				ans[i][j] = min(ans[i][j], dis[i][j] + t);
			}
}

void pre()
{
	int m;
	scanf("%d%d%d", &n, &m, &k);
	rep(i, 1, n)
	{
		node[i].num = i;
		scanf("%d", &(node[i].weight));
	}
	sort(node + 1, node + 1 + n);
	rep(i, 1, n)
		rank[node[i].num] = i;
	rep(i, 1, n)
		rep(j, 1, n)
			dis[i][j] = infi / 2;
	rep(i, 1, n)
		dis[i][i] = 0;
	rep(i, 1, m)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		dis[rank[x]][rank[y]] = dis[rank[y]][rank[x]] = z;
	}
	floyd();
}

void work()
{
	rep(i, 1, k)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%d\n", ans[rank[x]][rank[y]]);
	}
}

int main()
{
	freopen("toll.in", "r", stdin);
	freopen("toll.out", "w", stdout);

	pre();
	work();

	fclose(stdin);
	fclose(stdout);
	return 0;
}




