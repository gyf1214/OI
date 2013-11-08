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
#define max(a, b) (a)>(b)?(a):(b)
#define min(a, b) (a)<(b)?(a):(b)
#define infi 0x7FFFFFFF
#define mm 310
using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int sx[mm], sy[mm];
int map[mm][mm], dis[mm][mm];
int n, m, startx, starty, endx, endy;

void pre()
{
	char str[mm];
	gets(str);
	sscanf(str, "%d%d", &n, &m);
	clr(sx, 0);
	clr(sy, 0);
	clr(map, 0);
	rep(i, 1, n)
	{
		gets(str);
		rep(j, 1, m)
		{
			if (str[j - 1] == '#')
				map[i][j] = -1;
			if (str[j - 1] >= 'A' && str[j - 1] <= 'Z')
			{
				map[i][j] = str[j - 1] - 'A' + 1;
				sx[str[j - 1] - 'A' + 1] += i;
				sy[str[j - 1] - 'A' + 1] += j;
			}
			if (str[j - 1] == '@')
			{
				startx = i;
				starty = j;
			}
			if (str[j - 1] == '=')
			{
				endx = i;
				endy = j;
			}
		}
	}
}

int work()
{
	int qx[mm * mm], qy[mm * mm];
	clr(qx, 0);
	clr(qy, 0);
	clr(dis, 0);
	int l = 0;
	int r = 1;
	qx[0] = startx;
	qy[0] = starty;
	dis[startx][starty] = 1;
	while (r > l)
	{
		rep(i, 0, 3)
		{
			int nx = qx[l] + dx[i];
			int ny = qy[l] + dy[i];
			if (nx < 1 || nx > n || ny < 1 || ny > m)
				continue;
			if (map[nx][ny] == -1)
				continue;
			if (map[nx][ny] > 0)
			{
				int t = map[nx][ny];
				nx = sx[t] - nx;
				ny = sy[t] - ny;
			}
			if (dis[nx][ny] == 0)
			{
				dis[nx][ny] = dis[qx[l]][qy[l]] + 1;
				if (nx == endx && ny == endy)
					return dis[nx][ny] - 1;
				qx[r] = nx;
				qy[r] = ny;
				r++;
			}
		}
		l++;
	}
	return dis[endx][endy] - 1;
}

int main()
{
	freopen("cornmaze.in", "r", stdin);
	freopen("cornmaze.out", "w", stdout);

	pre();
	printf("%d\n", work());

	fclose(stdin);
	fclose(stdout);
	return 0;
}


