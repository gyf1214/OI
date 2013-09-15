/*
 * main.cpp
 *
 *  Created on: 2013-9-15
 *      Author: gyf
 */

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define clr(i, a) memset(i, a, sizeof(i))
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))
#define infi 0x7FFFFFFF
#define nm 10010
#define mm 50010
using namespace std;

int head[nm], next[mm], tail[mm];
int dfn[nm], low[nm], scc[nm], count[nm], k;
int s[nm], top;
int n, ne;

inline void ins(int u, int v)
{
	next[++ne] = head[u];
	head[u] = ne;
	tail[ne] = v;
}

void tarjan(int u)
{
	low[u] = dfn[u] = ++k;
	s[++top] = u;
	for (int e = head[u]; e; e = next[e])
	{
		int v = tail[e];
		if (!dfn[v])
		{
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}
		else if (!scc[v])
			low[u] = min(low[u], dfn[v]);
	}
	int v;
	if (low[u] == dfn[u])
		do
		{
			v = s[top--];
			scc[v] = u;
			count[u]++;
		} while (u != v);
}

void pre()
{
	clr(head, 0);
	clr(next, 0);
	clr(tail, 0);
	clr(dfn, 0);
	clr(low, 0);
	clr(scc, 0);
	clr(count, 0);
	clr(s, 0);
	top = 0;
	k = 0;
	ne = 0;
	int m;
	scanf("%d%d", &n, &m);
	rep(i, 1, m)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		ins(u, v);
	}
	rep(i, 1, n)
		if (!dfn[i])
			tarjan(i);
}

int main()
{
	freopen("date2.in", "r", stdin);
	freopen("date2.out", "w", stdout);

	pre();
	int ans = 0;
	rep(i, 1, n)
		ans = max(ans, count[i]);
	printf("%d\n", ans);

	fclose(stdin);
	fclose(stdout);
	return 0;
}
