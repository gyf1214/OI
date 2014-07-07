//Created At: Mon Jul 7 16:40:12 CST 2014
//orz zyx
//ntr czr
//Author: gyf

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
#define nm 60
#define mm 30000
using namespace std;

struct Edge
{
	int u, v, f;
	Edge* next, *rev;
}edge[mm], *next = edge;

Edge* head[nm], *cur[nm];

int d[nm], n, q[nm], s, t, delta;
int map[nm][nm];

inline Edge* _ins(int u, int v, int f)
{
	next -> u = u;
	next -> v = v;
	next -> f = f;
	next -> next = head[u];
	head[u] = next;
	return next++;
}

inline void ins(int u, int v, int c)
{
	Edge* now = _ins(u, v, c);
	now -> rev = _ins(v, u, 0);
	now -> rev -> rev = now;
}

bool bfs()
{
	clr(d, 0);
	d[s] = 1;
	int l = 0, r = 1;
	q[l] = s;
	while (l < r)
	{
		int u = q[l++];
		for (Edge* e = head[u]; e; e = e -> next)
			if (e -> f > 0 && !d[e -> v])
			{
				d[e -> v] = d[u] + 1;
				q[r++] = e -> v;
			}
	}
	return d[t] > 0;
}

bool dfs(int u, int x)
{
	if (u == t)
	{
		delta = x;
		return true;
	}
	for (Edge* e = cur[u]; e; e = e -> next)
		if (e -> f > 0 && d[e -> v] == d[u] + 1)
			if (dfs(e -> v, min(x, e -> f)))
			{
				e -> f -= delta;
				e -> rev -> f += delta;
				cur[u] = e;
				return true;
			}
	return false;
}

int dinic()
{
	int ans = 0;
	while (bfs())
	{
		memcpy(cur, head, sizeof(head));
		while (dfs(s, infi))
			ans += delta;
	}
	return ans;
}

void inis()
{
	clr(head, 0);
	next = edge;
	rep(i, 1, n)
		rep(j, 1, n)
			if (map[i][j] == 2)
				ins(i, j, 1);
			else if (map[i][j] == 1)
				ins(i, j, infi);
}

bool work()
{
	int a1, a2, an, b1, b2, bn;
	scanf("%d%d%d", &a1, &a2, &an);
	scanf("%d%d%d", &b1, &b2, &bn);
	a1 += 1; a2 += 1;
	b1 += 1; b2 += 1;
	rep(i, 1, n)
	{
		char buffer[100];
		scanf("%s", buffer);
		rep(j, 1, n)
			map[i][j] = buffer[j - 1] == 'X' ? 0 : (buffer[j - 1] == 'O' ? 2 : 1);
	}
	s = n + 1, t = n + 2;
	inis();
	ins(s, a1, an);
	ins(s, b1, bn);
	ins(a2, t, an);
	ins(b2, t, bn);
	int t1 = dinic();
	inis();
	ins(s, a1, an);
	ins(s, b2, bn);
	ins(a2, t, an);
	ins(b1, t, bn);
	int t2 = dinic();
	return t1 == an + bn && t2 == an + bn;
}

int main()
{
	//freopen("bridge.in", "r", stdin);

	while (scanf("%d", &n) != EOF)
		printf("%s\n", work() ? "Yes" : "No");

	fclose(stdin);
	fclose(stdout);
	return 0;
}

