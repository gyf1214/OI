/*
 * main.cpp
 *
 *  Created on: Feb 2, 2014
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
#define mm 2000
using namespace std;

int f[mm][4], f0[mm][4];
int n, k;
struct _node
{
	int x, y;
	friend inline bool operator <(_node a, _node b)
	{
		return a.y < b.y;
	}
}node[mm];


void work()
{
	rep(i, 0, k)
	{
		f[i][0] = f[i][1] = f[i][2] = f[i][3] = infi / 3;
	}
	int now = 1;
	f[1][2] = f[2][3] = 2;
	if (node[now].y == node[now + 1].y)
		++now;
	else
		f[1][node[now].x - 1] = 1;
	++now;
	while (now <= n)
	{
		memcpy(f0, f, sizeof(f));
		bool flag = now < n && node[now].y == node[now + 1].y;
		rep(i, 1, k)
		{
			f[i][0] = f[i][1] = f[i][2] = f[i + 1][3] = infi / 3;
			int t = min(f0[i - 1][0], f0[i - 1][1]);
			t = min(t, f0[i - 1][2]);
			t = min(t, f0[i - 1][3]);
			int dy = node[now].y - node[now - 1].y;
			f[i][2] = min(t + 2, f0[i][2] + 2 * dy);
			f[i + 1][3] = min(t + 2, f0[i][0] + dy + 1);
			f[i + 1][3] = min(f[i + 1][3], f0[i][1] + dy + 1);
			f[i + 1][3] = min(f[i + 1][3], f0[i + 1][3] + 2 * dy);
			if (!flag)
			{
				int x = node[now].x - 1;
				f[i][x] = min(t + 1, f0[i][x] + dy);
				f[i][x] = min(f[i][x], f0[i][3] + dy);
			}
		}
		now += flag ? 2 : 1;
	}
}

int main()
{
	freopen("lazy.in", "r", stdin);
	freopen("lazy.out", "w", stdout);

	int b;
	scanf("%d%d%d", &n, &k, &b);
	rep(i, 1, n)
		scanf("%d%d", &node[i].x, &node[i].y);
	sort(node + 1, node + 1 + n);
	work();
	int ans = infi;
	rep(i, 1, k)
	{
		ans = min(ans, f[i][0]);
		ans = min(ans, f[i][1]);
		ans = min(ans, f[i][2]);
		ans = min(ans, f[i][3]);
	}
	printf("%d\n", ans);

	fclose(stdin);
	fclose(stdout);
	return 0;
}
