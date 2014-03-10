/*
 * main.cpp
 *
 *  Created on: Mar 10, 2014
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
#define mm 15
using namespace std;

struct _node
{
	int index;
	int p[4];
	inline friend bool operator <(_node a, _node b)
	{
		return a.index < b.index;
	}
}node[mm * mm];

bool vis[mm * mm];
int r, c, n;
int map[mm][mm], turn[mm][mm];

int face(int x, int y, int k)
{
	if (x == 0 || y == 0)
		return 0;
	else
		return node[map[x][y]].p[(turn[x][y] + k) % 4];
}

void printface(int k)
{
	if (k == 0)
		printf(" %d", k);
	else
		printf(" %c", 'a' + k - 1);
}

void scanface(int& a)
{
	char k[10];
	scanf("%s", k);
	if (*k == '0')
		a = 0;
	else
		a = *k - 'a' + 1;
}

bool dfs(int x, int y)
{
	if (x == r + 1)
	{
		rep(i, 1, r)
			rep(j, 1, c)
			{
				int k = map[i][j];
				printf("%d", k);
				rep(t, 0, 3)
					printface(node[k].p[(t + turn[i][j]) % 4]);
				printf("\n");
			}
		return true;
	}

	rep(i, 1, n)
		if (!vis[i])
			rep(j, 0, 3)
				if (node[i].p[j] == face(x - 1, y, 2) && node[i].p[(j + 3) % 4] == face(x, y - 1, 1))
				{
					int nx, ny;
					if (y == c)
					{
						if (node[i].p[(j + 1) % 4] != 0)
							continue;
						nx = x + 1;
						ny = 1;
					} else {
						nx = x;
						ny = y + 1;
					}
					if (x == r)
						if (node[i].p[(j + 2) % 4] != 0)
							continue;
					map[x][y] = i;
					turn[x][y] = j;
					vis[i] = true;
					if (dfs(nx, ny))
						return true;
					vis[i] = false;
				}
	return false;
}

int main()
{
	//freopen("jigsaw.in", "r", stdin);
	//freopen("jigsaw.out", "w", stdout);

	scanf("%d%d", &r, &c);
	n = r * c;
	rep(i, 1, n)
	{
		scanf("%d", &node[i].index);
		scanface(node[i].p[0]);
		scanface(node[i].p[1]);
		scanface(node[i].p[2]);
		scanface(node[i].p[3]);
	}
	sort(node + 1, node + 1 + n);

	dfs(1, 1);

	fclose(stdin);
	fclose(stdout);
	return 0;
}
