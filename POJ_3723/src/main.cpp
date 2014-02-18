/*
 * main.cpp
 *
 *  Created on: Feb 18, 2014
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
#define nm 20010
#define mm 50010
using namespace std;

struct _edge
{
	int u, v, w;
	inline friend bool operator <(_edge a, _edge b)
	{
		return a.w > b.w;
	}
}edge[mm];

int p[nm], n, m, r;

int find(int u)
{
	if (u != p[u])
		p[u] = find(p[u]);
	return p[u];
}

void pre()
{
	scanf("%d%d%d", &n, &m, &r);
	rep(i, 0, r - 1)
	{
		scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);
		edge[i].v += n;
	}
	sort(edge, edge + r);
	rep(i, 0, m + n - 1)
		p[i] = i;
}

int work()
{
	int ans = (n + m) * 10000;
	rep(i, 0, r - 1)
	{
		int u = find(edge[i].u);
		int v = find(edge[i].v);
		if (u != v)
		{
			p[u] = v;
			ans -= edge[i].w;
		}
	}
	return ans;
}

int main()
{
	int t;
	scanf("%d", &t);
	rep(i, 1, t)
	{
		pre();
		printf("%d\n", work());
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}

