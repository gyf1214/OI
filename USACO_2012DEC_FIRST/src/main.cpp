/*
 * main.cpp
 *
 *  Created on: 2013-10-3
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
#define mm 3001000
#define em 30010
#define nm 26
using namespace std;

struct _node
{
	int p, s, b;
	int ch;
	bool end;
}node[mm];
int nn;

struct _edge
{
	int u, v;
	int next;
}edge[nm * nm];
int head[nm], ne;
char str[mm];
bool vis[nm];

int a[em], n;
bool ans[em];

inline void ins(int u, int v)
{
	++ne;
	edge[ne].next = head[u];
	edge[ne].u = u;
	edge[ne].v = v;
	head[u] = ne;
}

void dfs(int u)
{
	for (int e = head[u]; e; e = edge[e].next)
	{
		int v = edge[e].v;
		if (!vis[v])
		{
			vis[v] = true;
			dfs(v);
		}
	}
}

bool check(int k)
{
	clr(head, 0);
	clr(edge, 0);
	ne = 0;
	for (int i = k; i; i = node[i].p)
	{
		if (i != k && node[i].end)
			return false;
		for (int j = node[node[i].p].s; j; j = node[j].b)
			if (i != j)
				ins(node[i].ch, node[j].ch);
	}
	rep(i, 0, nm - 1)
	{
		clr(vis, 0);
		dfs(i);
		if (vis[i])
			return false;
	}
	return true;
}

void pre()
{
	clr(node, 0);
	nn = 0;
	scanf("%d", &n);
	rep(c, 1, n)
	{
		scanf("%s", str);
		int length = strlen(str);
		int now = 0;
		rep(i, 0, length - 1)
		{
			int ch = str[i] - 'a';
			int k = 0;
			for (int j = node[now].s; j; j = node[j].b)
				if (node[j].ch == ch)
					k = j;
			if (k == 0)
			{
				++nn;
				node[nn].p = now;
				node[nn].b = node[now].s;
				node[nn].ch = ch;
				node[now].s = nn;
				k = nn;
			}
			now = k;
		}
		node[now].end = true;
		a[c] = now;
	}
}

int main()
{
	freopen("first.in", "r", stdin);
	freopen("first.out", "w", stdout);

	pre();
	int cnt = 0;
	clr(ans, 0);
	rep(i, 1, n)
		if (check(a[i]))
		{
			ans[i] = true;
			++cnt;
		}
	printf("%d\n", cnt);
	rep(i, 1, n)
		if (ans[i])
		{
			int t = 0;
			for (int k = a[i]; k; k = node[k].p)
			{
				str[t] = node[k].ch + 'a';
				++t;
			}
			for (int k = t - 1; k >= 0; --k)
				printf("%c", str[k]);
			printf("\n");
		}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
