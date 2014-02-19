/*
 * main.cpp
 *
 *  Created on: Feb 19, 2014
 *      Author: gyf
 */

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define clr(i, a) memset(i, (a), sizeof(i))
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))
#define infi 0x7FFFFFFF
#define nm 1010
#define mm 10010
using namespace std;

struct _edge
{
	int u, v, w;
}edge[mm];

int n, m, dis[nm];

bool work()
{
	rep(i, 1, n)
		dis[i] = infi / 2;
	dis[1] = 0;
	rep(i, 1, n)
		rep(j, 1, m)
		{
			int u = edge[j].u;
			int v = edge[j].v;
			int w = edge[j].w;
			dis[v] = min(dis[v], dis[u] + w);
		}
	rep(j, 1, m)
	{
		int u = edge[j].u;
		int v = edge[j].v;
		int w = edge[j].w;
		if (dis[v] > dis[u] + w)
			return false;
	}
	return true;
}

int main()
{
	int ml, md;
	scanf("%d%d%d", &n, &ml, &md);
	rep(i, 1, ml)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		edge[i].u = min(u, v);
		edge[i].v = max(u, v);
		edge[i].w = w;
	}
	rep(i, ml + 1, ml + md)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		edge[i].u = max(u, v);
		edge[i].v = min(u, v);
		edge[i].w = -w;
	}
	m = ml + md;
	bool ans = work();
	if (!ans)
		printf("%d\n", -1);
	else
		printf("%d\n", dis[n] == infi / 2 ? -2 : dis[n]);

	fclose(stdin);
	fclose(stdout);
	return 0;
}


