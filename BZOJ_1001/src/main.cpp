//orz zyx
//ntr czr

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
#define nm 3000000
#define mm 6000000
using namespace std;

typedef pair<int, int> pii;

struct Edge
{
	int u, v;
	int w;
	Edge* next;
}edge[mm], *next = edge;

Edge* head[nm];

void ins(int u, int v, int w)
{
	next -> u = u;
	next -> v = v;
	next -> w = w;
	next -> next = head[u];
	head[u] = next;
	++next;
}

pii h[mm];
int hn, n;
int dis[nm];

void pop()
{
	pop_heap(h, h + hn, greater<pii>());
	--hn;
}

void push(pii p)
{
	h[hn] = p;
	++hn;
	push_heap(h, h + hn, greater<pii>());
}

void dijistra(int s)
{
	rep(i, 1, n)
		dis[i] = infi;
	dis[s] = 0;
	rep(i, 1, n)
		h[i] = make_pair(dis[i], i);
	make_heap(h, h + 1, greater<pii>());
	hn = n;
	rep(i, 1, n)
	{
		while (hn > 0 && h[0].first != dis[h[0].second])
			pop();
		int u = h[0].second;
		pop();
		for (Edge* e = head[u]; e; e = e -> next)
		{
			int v = e -> v;
			if (dis[v] - e -> w > dis[u])
			{
				dis[v] = e -> w + dis[u];
				push(make_pair(dis[v], v));
			}
		}
	}
}

int main()
{
	int m;
	scanf("%d%d", &n, &m);
	int w, u, v;
	int s = 1;
	int t = 2 * (m - 1) * (n - 1) + 2;
	if (n == 1 || m == 1)
	{
		rep(j, 1, max(m, n) - 1)
		{
			scanf("%d", &w);
			ins(s, t, w);
		}
	} else {
		rep(j, 1, m - 1)
		{
			scanf("%d", &w);
			ins(s, j + 1, w);
		}
		rep(i, 2, n - 1)
			rep(j, 1, m - 1)
			{
				scanf("%d", &w);
				u = (2 * i - 3) * (m - 1) + j + 1;
				v = u + m - 1;
				ins(u, v, w);
			}
		rep(j, 1, m - 1)
		{
			scanf("%d", &w);
			u = (2 * n - 3) * (m - 1) + j + 1;
			ins(u, t, w);
		}
		rep(i, 1, n - 1)
		{
			scanf("%d", &w);
			u = (2 * i - 1) * (m - 1) + 2;
			ins(u, t, w);
			rep(j, 2, m - 1)
			{
				scanf("%d", &w);
				u = (2 * i - 2) * (m - 1) + j;
				v = u + m;
				ins(v, u, w);
			}
			scanf("%d", &w);
			v = (2 * i - 1) * (m - 1) + 1;
			ins(s, v, w);
		}
		rep(i, 1, n - 1)
			rep(j, 1, m - 1)
			{
				scanf("%d", &w);
				u = (2 * i - 2) * (m - 1) + j + 1;
				v = u + m - 1;
				ins(u, v, w);
			}
	}
	n = t;
	dijistra(s);
	printf("%d\n", dis[t]);

	fclose(stdin);
	fclose(stdout);
	return 0;
}


