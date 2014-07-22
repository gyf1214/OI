//Created At: Tue Jul 22 21:39:04 CST 2014
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
#define infi 0x7FFFFFF
#define tm 110
#define pm 1010
#define nm 10010
#define mm 100010
using namespace std;

struct Edge
{
	int u, v, f, c;
	Edge* next, *rev;
}edge[mm], *next = edge, *head[nm];

Edge* p[nm];

int s, t, d[nm], q[nm];
bool vis[mm];
int node[tm][pm], tim[tm][tm];
int nn, ans;
int n, m;

int spfa()
{
	int l = 0, r = 1;
	q[l] = s;
	clr(vis, 0);
	rep(i, 1, nn)
		d[i] = infi;
	d[s] = 0;
	vis[s] = true;
	while (r != l)
	{
		int u = q[l];
		l = (l + 1) % nm;
		vis[u] = false;
		for (Edge* e = head[u]; e; e = e -> next)
			if (e -> f > 0 && d[e -> v] > d[u] + e -> c)
			{
				d[e -> v] = e -> c + d[u];
				p[e -> v] = e;
				if (!vis[e -> v])
				{
					q[r] = e -> v;
					r = (r + 1) % nm;
					vis[e -> v] = true;
				}
			}
	}

	if (d[t] == infi) return 0;
	int delta = infi;
	for (int i = t; p[i]; i = p[i] -> u)
		delta = min(delta, p[i] -> f);
	for (int i = t; p[i]; i = p[i] -> u)
	{
		p[i] -> f -= delta;
		p[i] -> rev -> f += delta;
	}

	ans += d[t] * delta;
	return p[t] -> u;
}

Edge* _ins(int u, int v, int f, int c)
{
	next -> u = u;
	next -> v = v;
	next -> f = f;
	next -> c = c;
	next -> next = head[u];
	head[u] = next;
	return next++;
}

void ins(int u, int v, int f, int c)
{
	Edge* now = _ins(u, v, f, c);
	now -> rev = _ins(v, u, 0, -c);
	now -> rev -> rev = now;
}

void extend(int i)
{
	node[i][++node[i][0]] = ++nn;
	ins(nn, t, 1, 0);
	rep(j, 1, n)
		ins(j + 1, nn, 1, tim[j][i] * node[i][0]);
	return;
}

void work()
{
	scanf("%d%d", &n, &m);
	s = 1, t = n + 2;
	nn = t;
	rep(i, 1, n)
	{
		int x;
		scanf("%d", &x);
		ins(s, 1 + i, x, 0);
	}
	rep(i, 1, n)
		rep(j, 1, m)
			scanf("%d", &tim[i][j]);
	clr(node, 0);
	rep(i, 1, m)
		extend(i);
	ans = 0;
	int u;
	while (u = spfa())
		rep(i, 1, m)
			if (node[i][node[i][0]] == u)
			{
				extend(i);
				break;
			}
	printf("%d\n", ans);
}

int main()
{
	freopen("delicacy.in", "r", stdin);
	freopen("delicacy.out", "w", stdout);
	work();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

