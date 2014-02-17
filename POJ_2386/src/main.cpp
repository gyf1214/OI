/*
 * main.cpp
 *
 *  Created on: Feb 16, 2014
 *      Author: gyf
 */

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define clr(i, a) memset(i, a, sizeof(i))
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))
#define infi 0x7FFFFFFF
#define mm 110
using namespace std;

typedef pair<int, int> pii;

bool map[mm][mm];
pii q[mm * mm];
bool vis[mm][mm];
int l, r, n, m;


void bfs(int x, int y)
{
	l = 0, r = 1;
	q[0] = make_pair(x, y);
	vis[x][y] = true;
	while (r > l)
	{
		pii now = q[l];
		rep(i, -1, 1)
			rep(j, -1, 1)
			{
				int nx = now.first + i;
				int ny = now.second + j;
				if (map[nx][ny] && !vis[nx][ny])
				{
					q[r] = make_pair(nx, ny);
					++r;
					vis[nx][ny] = true;
				}
			}

		++l;
	}
}

int work()
{
	clr(vis, 0);
	int ans = 0;
	rep(i, 1, n)
		rep(j, 1, m)
			if (!vis[i][j] && map[i][j])
			{
				bfs(i, j);
				++ans;
			}
	return ans;
}

int main()
{
	scanf("%d%d", &n, &m);
	rep(i, 1, n)
	{
		char str[mm];
		scanf("%s", str);
		rep(j, 1, m)
			map[i][j] = str[j - 1] == 'W';
	}
	printf("%d\n", work());

	fclose(stdin);
	fclose(stdout);
	return 0;
}
