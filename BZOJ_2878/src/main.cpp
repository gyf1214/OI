//Created At: Tue Jul 22 16:43:04 CST 2014
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
#define mm 100010
using namespace std;

struct Edge
{
	int u, v;
	double w;
	Edge* next, *rev;
}edge[mm * 2], *next = edge, *head[mm];

int n, m, q[mm], tmp[mm];
Edge* p[mm], *nc[mm], *rc[mm];
bool circle[mm];

Edge* _ins(int u, int v, double w)
{
	next -> u = u;
	next -> v = v;
	next -> w = w;
	next -> next = head[u];
	head[u] = next;
	return next++;
}

void ins(int u, int v, double w)
{
	Edge* now = _ins(u, v, w);
	now -> rev = _ins(v, u, w);
	now -> rev -> rev = now;
}

void build_p()
{
	int l = 0, r = 0;
	q[r++] = 1;
	while (r > l)
	{
		int u = q[l++];
		for (Edge* e = head[u]; e; e = e -> next)
			if (!p[e -> v] && e -> v != 1)
			{
				p[e -> v] = e;
				q[r++] = e -> v;
			}
	}
}

void make_circle()
{
	int u, v, k;
	Edge* ce;
	for (Edge* e = edge; e != next; ++e)
		if ((!p[e -> u] || p[e -> u] -> u != e -> v) && (!p[e -> v] || p[e -> v] -> u != e -> u))
		{
			u = e -> u;
			v = e -> v;
			ce = e;
			break;
		}
	clr(tmp, 0);
	clr(circle, 0);
	for (int t = u; p[t]; t = p[t] -> u) tmp[t] = 1;
	tmp[1] = 1;
	for (k = v; !tmp[k]; k = p[k] -> u);
	for (int t = u; t != k; t = p[t] -> u)
	{
		circle[t] = true;
		nc[t] = p[t];
		rc[p[t] -> u] = p[t] -> rev;
	}
	for (int t = v; t != k; t = p[t] -> u)
	{
		circle[t] = true;
		rc[t] = p[t];
		nc[p[t] -> u] = p[t] -> rev;
	}
	nc[v] = ce;
	rc[u] = ce -> rev;
	circle[k] = true;
}

double down[mm], up[mm];
int deg[mm];

void work_down(int s)
{
	int l = 0, r = 0;
	q[r++] = s;
	while (r > l)
	{
		int u = q[l++];
		for (Edge* e = head[u]; e; e = e -> next)
			if (!p[e -> v] && !circle[e -> v] && e -> v != s)
			{
				p[e -> v] = e;
				++deg[u];
				q[r++] = e -> v;
			}
	}
	for (int i = r - 1; i >= 0; --i)
		if (q[i] != s)
		{
			int v = q[i], u = p[v] -> u;
			down[u] += (down[v] + p[v] -> w) / (double)deg[u];
		}
}

void work_up_circle(int s)
{
	if (!circle[s]) return;
	double sum = nc[s] -> w;
	double mul = .5;
	for (int u = nc[s] -> u; nc[u] -> u != s; u = nc[u] -> u)
	{
		up[s] += (sum + down[u]) * mul * (double)deg[u] / (double)(deg[u] + 1);
		sum += nc[u] -> w;
		mul /= (double)(deg[u] + 1);
	}
	up[s] += (sum + down[rc[s] -> u]) * mul;
	sum = rc[s] -> w;
	mul = .5;
	for (int u = rc[s] -> u; rc[u] -> u != s; u = rc[u] -> u)
	{
		up[s] += (sum + down[u]) * mul * (double)deg[u] / (double)(deg[u] + 1);
		sum += rc[u] -> w;
		mul /= (double)(deg[u] + 1);
	}
	up[s] += (sum + down[nc[s] -> u]) * mul;
}

void work_up(int s)
{
	work_up_circle(s);
	int l = 0, r = 0;
	q[r++] = s;
	while (r > l)
	{
		int u = q[l++];
		for (Edge* e = head[u]; e; e = e -> next)
			if (p[e -> v] && p[e -> v] -> u == u)
			{
				up[e -> v] = up[u] + down[u] * (double)deg[u] - down[e -> v] - e -> w;
				if (up[u] == 0)
				{
					up[e -> v] = deg[u] > 1 ? up[e -> v] / (double)(deg[u] - 1) : 0;
				} else if (circle[u])
				{
					up[e -> v] = (up[e -> v] + up[u]) / (double)(deg[u] + 1);
				} else {
					up[e -> v] = up[e -> v] / (double)deg[u];
				}
				up[e -> v] += e -> w;
				q[r++] = e -> v;
			}
	}
}

void pre()
{
	scanf("%d%d", &n, &m);
	rep(i, 1, m)
	{
		int x, y;
		double z;
		scanf("%d%d%lf", &x, &y, &z);
		ins(x, y, z);
	}
	if (m == n)
	{
		build_p();
		make_circle();
	}
	clr(p, 0);
	if (n == m)
	{
		rep(i, 1, n)
			if (circle[i])
				work_down(i);
		rep(i, 1, n)
			if (circle[i])
				work_up(i);
	} else {
		work_down(1);
		work_up(1);
	}
}

int main()
{
	freopen("park.in", "r", stdin);
	freopen("park.out", "w", stdout);
	pre();
	double ans = 0;
	rep(i, 1, n)
		if (circle[i])
			ans += (up[i] * 2.0 + down[i] * (double)deg[i]) / (double)(deg[i] + 2);
		else
		{
			if (p[i])
				ans += (up[i] + down[i] * (double)deg[i]) / (double)(deg[i] + 1);
			else
				ans += down[i];
		}
	printf("%.10lf", ans / (double)n);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

