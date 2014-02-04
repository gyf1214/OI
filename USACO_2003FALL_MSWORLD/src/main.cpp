/*
 * main.cpp
 *
 *  Created on: Feb 4, 2014
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
#define mm 50010
using namespace std;

struct _point
{
	int x, y;
	_point(int x = 0, int y = 0) : x(x), y(y)
	{}
	inline friend int operator ^(_point a, _point b)
	{
		return a.x * b.y - a.y * b.x;
	}
	inline friend _point operator -(_point a, _point b)
	{
		_point ret(a.x - b.x, a.y - b.y);
		return ret;
	}
	inline int abs()
	{
		return x * x + y * y;
	}
	inline friend bool operator <(_point a, _point b);
}p[mm];

int n;
int s[mm], top;

inline bool operator <(_point a, _point b)
{
	int ans = (a - p[0]) ^ (b - p[0]);
	return ans > 0 || (ans == 0 && (a - p[0]).abs() > (b - p[0]).abs());
}

void graham()
{
	int u = 0;
	rep(i, 1, n - 1)
		if (p[u].y > p[i].y || (p[u].y == p[i].y && p[u].x > p[i].x))
			u = i;
	if (u != 0)
	{
		_point t = p[0];
		p[0] = p[u];
		p[u] = t;
	}
	sort(p + 1, p + n);
	top = 1;
	s[0] = 0;
	s[1] = 1;
	rep(i, 2, n - 1)
	{
		while (top > 0 && ((p[s[top]] - p[s[top - 1]]) ^ (p[i] - p[s[top]])) < 0)
			--top;
		++top;
		s[top] = i;
	}
	++top;
}

int rc()
{
	int ans = 0;
	int k = 0;
	s[top] = s[0];
	rep(i, 0, top - 1)
	{
		while (abs((p[s[k]] - p[s[i]]) ^ (p[s[i + 1]] - p[s[i]]))
				< abs((p[s[k + 1]] - p[s[i]]) ^ (p[s[i + 1]] - p[s[i]])))
			k = (k + 1) % top;
		ans = max(ans, (p[s[i]] - p[s[k]]).abs());
		ans = max(ans, (p[s[i + 1]] - p[s[k]]).abs());
	}
	return ans;
}

int main()
{
	freopen("msworld.in", "r", stdin);
	freopen("msworld.out", "w", stdout);

	scanf("%d", &n);
	rep(i, 0, n - 1)
		scanf("%d%d", &p[i].x, &p[i].y);
	graham();
	printf("%d\n", rc());

	fclose(stdin);
	fclose(stdout);
	return 0;
}
