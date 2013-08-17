/*
 * main.cpp
 *
 *  Created on: 2013-7-25
 *      Author: gyf
 */

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define clr(i, a) memset(i, a, sizeof(i))
#define max(a, b) (a)>(b)?(a):(b)
#define min(a, b) (a)<(b)?(a):(b)
#define infi 0x7FFFFFFF
#define nm 10010
#define mm 60010

int head[nm], next[mm], start[mm], tail[mm];
int dfn[nm], low[nm], scc[nm], count[nm], k, scccnt;
int s[nm], top;
int n, ne;

inline void ins(int u, int v)
{
	next[++ne] = head[u];
	head[u] = ne;
	start[ne] = u;
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
	{
		scccnt++;
		do
		{
			v = s[top--];
			scc[v] = u;
			count[u]++;
		} while (u != v);
	}
}

void pre()
{
	clr(head, 0);
	clr(next, 0);
	clr(tail, 0);
	clr(start, 0);
	clr(dfn, 0);
	clr(low, 0);
	clr(scc, 0);
	clr(count, 0);
	clr(s, 0);
	top = 0;
	k = 0;
	ne = 0;
	scccnt = 0;
	int m;
	scanf("%d%d", &n, &m);
	rep(i, 1, m)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		ins(x, y);
	}
	rep(i, 1, n)
		if (!dfn[i])
			tarjan(i);
}

int work()
{
	bool ans[nm];
	if (scccnt <= 1)
		return n;
	rep(i, 1, n)
		ans[i] = true;
	rep(i, 1, ne)
		if (scc[start[i]] != scc[tail[i]])
			ans[scc[start[i]]] = false;
	int t;
	int cnt = 0;
	rep(i, 1, n)
		if (count[i] > 0 && ans[i])
		{
			cnt++;
			t = i;
		}
	if (cnt > 1)
		return 0;
	else
		return count[t];
}

int main()
{
	freopen("popular.in", "r", stdin);
	freopen("popular.out", "w", stdout);

	pre();
	printf("%d\n", work());

	fclose(stdin);
	fclose(stdout);
	return 0;
}


