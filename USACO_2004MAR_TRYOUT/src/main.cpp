/*
 * main.cpp
 *
 *  Created on: 2013-7-20
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
#define mm 2000
using namespace std;

int q[mm], n, a, b, c;

struct node
{
	int h, w;
	friend bool operator <(node a, node b)
	{
		return a.w < b.w;
	}
}t[mm];

struct node2
{
	int h, w;
	inline friend bool operator <(node2 x, node2 y)
	{
		return (a * x.h + b * x.w) < (a * y.h + b * y.w);
	}
	inline void operator = (node y)
	{
		this->h = y.h;
		this->w = y.w;
	}
}t2[mm];

inline bool check(int x, int h, int w)
{
	return ((a * (t2[x].h - t[h].h) + b * (t2[x].w - t[w].w)) <= c);
}

int work()
{
	int ret = 0;
	sort(t + 1, t + n + 1);
	rep (i, 1, n)
	{
		clr(q, 0);
		clr(t2, 0);
		int l = 0;
		int r = 0;
		int x = 0;
		int k = 0;
		rep (j, 1, n)
			if (t[j].h >= t[i].h)
				t2[k++] = t[j];
		sort(t2, t2 + k);
		rep (j, 1, n)
		{
			while ((x < k) && check(x, i, j))
				q[r++] = x++;
			while ((r > l) && (t2[l].w < t[j].w))
				l++;
			ret = max(ret, r - l);
		}
	}
	return ret;
}

int main()
{
	freopen("tryout.in", "r", stdin);
	freopen("tryout.out", "w", stdout);

	scanf("%d%d%d%d", &n, &a, &b, &c);
	clr(t, 0);
	clr(t2, 0);
	rep (i, 1, n)
	{
		int h, w;
		scanf("%d%d", &h, &w);
		t[i].h = h;
		t[i].w = w;
	}
	printf("%d\n", work());

	fclose(stdin);
	fclose(stdout);
	return 0;
}



