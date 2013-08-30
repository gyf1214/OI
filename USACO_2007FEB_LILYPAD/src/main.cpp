/*
 * main.cpp
 *
 *  Created on: 2013-8-30
 *      Author: gyf
 */

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define clr(i, a) memset(i, a, sizeof(i))
#define max(a, b) (a)>(b)?(a):(b)
#define min(a, b) (a)<(b)?(a):(b)
#define infi 0x7FFFFFFF
#define mm 1100
#define nm 32
using namespace std;

long long cnt[nm][nm];
int dis[nm][nm];
int a[nm][nm];
bool next[nm][nm];
int m, n;
int move[2][8] = {
	{ 1,  2, 2, 1, -1, -2, -2, -1},
	{-2, -1, 1, 2,  2,  1, -1, -2}
};

struct _node
{
	int x, y;
	_node(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};
queue<_node> q;

void dfs(int x, int y)
{
	if (x <= 0 || x > n || y <= 0 || y > m || a[x][y] == 2 || next[x][y])
		return;
	next[x][y] = true;
	if (a[x][y] == 0)
		return;
	rep(i, 0, 7)
		dfs(x + move[0][i], y + move[1][i]);
}

void bfs(int sx, int sy)
{
	clr(dis, 0);
	clr(cnt, 0);
	dis[sx][sy] = 1;
	cnt[sx][sy] = 1;
	_node s(sx, sy);
	q.push(s);
	while (!q.empty())
	{
		_node now = q.front();
		clr(next, 0);
		a[now.x][now.y] = 1;
		dfs(now.x, now.y);
		a[now.x][now.y] = 0;
		rep(i, 1, n)
			rep(j, 1, m)
				if (next[i][j] && a[i][j] == 0)
				{
					if (dis[i][j] == 0)
					{
						_node ne(i, j);
						dis[i][j] = dis[now.x][now.y] + 1;
						q.push(ne);
					}
					if (dis[i][j] == dis[now.x][now.y] + 1)
						cnt[i][j] += cnt[now.x][now.y];
				}
		q.pop();
	}
}

int main()
{
	 freopen("lilypad.in", "r", stdin);
	 freopen("lilypad.out", "w", stdout);

	scanf("%d%d", &n, &m);
	int sx, sy, tx, ty;
	rep(i, 1, n)
		rep(j, 1, m)
		{
			scanf("%d", &a[i][j]);
			if (a[i][j] == 3)
			{
				sx = i;
				sy = j;
				a[i][j] = 1;
			}
			if (a[i][j] == 4)
			{
				tx = i;
				ty = j;
				a[i][j] = 0;
			}
		}
	bfs(sx, sy);
	if (dis[tx][ty] == 0)
		printf("%d\n", -1);
	else
		printf("%d\n%lld\n", dis[tx][ty] - 2, cnt[tx][ty]);

	fclose(stdin);
	fclose(stdout);
	return 0;
}
