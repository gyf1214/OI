/*
 * main.cpp
 *
 *  Created on: 2013-11-8
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
#define mm 50
using namespace std;

bool map[mm][mm];
int dis[mm][mm];
int dx[8], dy[8];

struct _state
{
	int x, y;
}queue[mm * mm];

int n, m, l, r;

inline bool in(int x, int y)
{
	return x > 0 && x <= n && y > 0 && y <= m;
}

void work(int sx, int sy)
{
	l = 0;
	r = 1;
	queue[0] = {sx, sy};
	clr(dis, 0);
	dis[sx][sy] = 1;
	while (l < r)
	{
		_state now = queue[l++];
		rep(i, 0, 7)
		{
			_state next = {now.x + dx[i], now.y + dy[i]};
			if (in(next.x, next.y) && map[next.x][next.y] && !dis[next.x][next.y])
			{
				queue[r++] = next;
				dis[next.x][next.y] = dis[now.x][now.y] + 1;
			}
		}
	}
}

int main()
{
	freopen("bronlily.in", "r", stdin);
	freopen("bronlily.out", "w", stdout);

	int mx, my;
	scanf("%d%d%d%d", &n, &m, &mx, &my);
	int k = 0;
	rep(i, 0, 1)
		rep(j, 0, 1)
		{
			dx[k] = (i * 2 - 1) * mx;
			dy[k] = (j * 2 - 1) * my;
			++k;
		}
	rep(i, 0, 1)
		rep(j, 0, 1)
		{
			dx[k] = (i * 2 - 1) * my;
			dy[k] = (j * 2 - 1) * mx;
			++k;
		}
	int sx, sy, tx, ty;
	rep(i, 1, n)
		rep(j, 1, m)
		{
			int x;
			scanf("%d", &x);
			map[i][j] = x > 0 && x != 2;
			if (x == 3)
			{
				sx = i;
				sy = j;
			}
			if (x == 4)
			{
				tx = i;
				ty = j;
			}
		}
	work(sx, sy);
	printf("%d\n", dis[tx][ty] - 1);

	fclose(stdin);
	fclose(stdout);
	return 0;
}
