/*
 * main.cpp
 *
 *  Created on: Feb 25, 2014
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
#define nm 40
#define mm 300
using namespace std;

double dp[nm][mm];
int t[nm];
int n, m, a, b;

struct _edge
{
	int u, v, w;
	_edge* next;
}edge[nm * nm];

_edge* head[nm];
int ne;

inline void ins(int x, int y, int z)
{
	++ne;
	edge[ne].u = x;
	edge[ne].v = y;
	edge[ne].w = z;
	edge[ne].next = head[x];
	head[x] = &edge[ne];
}

bool pre()
{
	clr(head, 0);
	clr(edge, 0);
	ne = 0;
	int p;
	scanf("%d%d%d%d%d", &n, &m, &p, &a, &b);
	if (n == 0)
		return false;
	rep(i, 1, n)
		scanf("%d", &t[i]);
	rep(i, 1, m)
		rep(j, 0, (1 << n) - 1)
			dp[i][j] = infi + .0;
	rep(i, 1, p)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		ins(x, y, z);
		ins(y, x, z);
	}
	return true;
}

double work()
{
	dp[a][0] = 0;
	rep(i, 0, (1 << n) - 1)
		rep(j, 1, m)
			for (_edge* e = head[j]; e; e = e -> next)
			{
				int v = e -> v;
				rep(k, 1, n)
					if ((i & (1 << (k - 1))) == 0)
						dp[v][i | (1 << (k - 1))] = min(
								dp[v][i | (1 << (k - 1))],
								dp[j][i] + (e -> w + .0) / t[k]);
			}
	double ans = infi;
	rep(i, 0, (1 << n) - 1)
		ans = min(ans, dp[b][i]);
	return ans;
}

int main()
{
	while (pre())
	{
		double ans = work();
		if (ans >= infi)
			printf("Impossible\n");
		else
			printf("%.3f\n", ans);
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}



