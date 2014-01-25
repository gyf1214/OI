/*
 * main.cpp
 *
 *  Created on: Jan 25, 2014
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
#define mm 10010
using namespace std;

struct _node
{
	int x, y;
	int up, down;
	friend inline bool operator <(_node i, _node j)
	{
		return i.y < j.y;
	}
}node[mm];
int n, h;
int q[mm], l, r;
int dis[mm];

inline bool pass(int i, int j)
{
	return (node[i].x - node[j].x) * (node[i].x - node[j].x) +
			(node[i].y - node[j].y) * (node[i].y - node[j].y) <=
			1000 * 1000;
}

int bfs()
{
	int ans = infi;
	clr(dis, 0);
	l = r = 0;
	rep(i, 1, n)
	{
		if (node[i].y > 1000)
			break;
		q[r++] = i;
		dis[i] = 1;
	}
	while (l < r)
	{
		int u = q[l++];
		rep(i, node[u].down, node[u].up)
			if (dis[i] == 0 && pass(i, u))
			{
				dis[i] = dis[u] + 1;
				q[r++] = i;
				if (node[i].y >= h - 1000)
					ans = min(ans, dis[i]);
			}
	}
	return ans;
}

void pre()
{
	scanf("%d%d", &h, &n);
	rep(i, 1, n)
		scanf("%d%d", &node[i].x, &node[i].y);
	sort(node + 1, node + 1 + n);
	rep(i, 1, n)
	{
		int l = 0;
		int r = i - 1;
		while (r - l > 1)
		{
			int m = (l + r) / 2;
			if (node[m].y >= node[i].y - 1000)
				r = m;
			else
				l = m;
		}
		node[i].down = max(r, 1);
		l = i + 1;
		r = n + 1;
		while (r - l > 1)
		{
			int m = (l + r) / 2;
			if (node[m].y <= node[i].y + 1000)
				l = m;
			else
				r = m;
		}
		node[i].up = min(l, n);
	}
}

int main()
{
	freopen("wall.in", "r", stdin);
	freopen("wall.out", "w", stdout);

	pre();
	printf("%d\n", bfs());

	fclose(stdin);
	fclose(stdout);
}
