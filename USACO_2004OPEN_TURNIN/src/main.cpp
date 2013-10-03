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
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))
#define infi 0x7FFFFFFF
#define mm 1010
using namespace std;

struct _node
{
	int x, t;
	friend bool operator <(_node a, _node b)
	{
		return a.x < b.x;
	}
}node[mm];

int f[mm][mm], g[mm][mm];
int n, b;

inline bool in(int x)
{
	return (x >= 0) && (x <= n);
}

inline int dis(int i, int j)
{
	return abs(node[i].x - node[j].x);
}

inline void pro(bool fg1, bool fg2, int i, int j, int k)
{
	if (in(k))
	{
		if (fg1)
		{
			if (fg2)
				f[i][k] = min(f[i][k], max(f[i - 1][j] + dis(j, k), node[k].t));
			else
				f[i][k] = min(f[i][k], max(g[i - 1][j] + dis(j, k), node[k].t));
		}
		else
		{
			if (fg2)
				g[i][k] = min(g[i][k], max(f[i - 1][j] + dis(j, k), node[k].t));
			else
				g[i][k] = min(g[i][k], max(g[i - 1][j] + dis(j, k), node[k].t));
		}
	}
}

void pre()
{
	int h;
	scanf("%d%d%d", &n, &h, &b);
	rep(i, 1, n)
		scanf("%d%d", &node[i].x, &node[i].t);
	node[0].t = 0;
	node[0].x = 0;
	sort(node, node + n + 1);
}

int work()
{
	rep(l, 0, n)
		rep(i, 0, n)
			{
				f[l][i] = infi / 3;
				g[l][i] = infi / 3;
			}
	f[0][0] = 0;
	rep(i, 1, n)
	{
		rep(j, 0, n)
		{
			pro(true, true, i, j, j + 1);
			pro(false, true, i, j, n - i + j + 1);
			pro(true, false, i, j, i + j - n);
			pro(false, false, i, j, j - 1);
		}
	}
	int ans = infi / 3;
	rep(i, 0, n)
		ans = min(ans, min(f[n][i], g[n][i]) + abs(node[i].x - b));
	return ans;
}

int main()
{
	freopen("turnin.in", "r", stdin);
	freopen("turnin.out", "w", stdout);

	pre();
	printf("%d\n", work());

	fclose(stdin);
	fclose(stdout);
	return 0;
}
