/*
 * main.cpp
 *
 *  Created on: Mar 15, 2014
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
#define nm 15
#define mm 10010
using namespace std;

struct _node
{
	int x, y;
}node[mm];

int y[nm], x, n, m, next[nm];
int s[mm], top;

int det(int x1, int y1, int x2, int y2, int x3, int y3)
{
	return (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
}

bool cross(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
	int s1 = det(x1, y1, x2, y2, x3, y3);
	int s2 = det(x1, y1, x2, y2, x4, y4);
	return (s1 > 0 && s2 > 0) || (s1 < 0 && s2 < 0) || s1 == 0;
}

bool check(int k)
{
	top = 0;
	clr(next, 0);
	int p = 0;
	rep(i, 1, n)
		if (((1 << (i - 1)) & k) != 0)
		{
			next[p] = i;
			p = i;
		}
	next[p] = n + 1;
	rep(i, 1, m)
	{
		if ((node[i - 1].x >= x && node[i].x > x) ||
				(node[i - 1].x <= x && node[i].x < x))
			continue;
		int t;
		rep(j, 0, n)
			if (next[j] != 0 &&
					!cross(node[i - 1].x, node[i - 1].y, node[i].x, node[i].y,
					x, y[j], x, y[next[j]]))
			{
				t = j;
				break;
			}
		int pre = node[i].x > node[i - 1].x ? 1 : -1;
		++top;
		s[top] = pre * t;
		if (top > 1 && abs(s[top] + s[top - 1]) == 0)
			top -= 2;
	}
	return top == 0;
}

int main()
{
	freopen("tied.in", "r", stdin);
	freopen("tied.out", "w", stdout);

	scanf("%d%d%d%d", &n, &m, &node[0].x, &node[0].y);
	rep(i, 1, n)
		scanf("%d%d", &x, &y[i]);
	rep(i, 0, m)
		scanf("%d%d", &node[i].x, &node[i].y);
	sort(y + 1, y + 1 + n);
	y[0] = -10010;
	y[n + 1] = 10010;
	int ans = 0;
	rep(i, 0, ((1 << n) - 1))
		if (check(i))
		{
			int k = 0;
			rep(j, 1, n)
				if (((1 << (j - 1)) & i) != 0)
					++k;
			ans = max(ans, k);
		}
	printf("%d\n", n - ans);

	fclose(stdin);
	fclose(stdout);
	return 0;
}
