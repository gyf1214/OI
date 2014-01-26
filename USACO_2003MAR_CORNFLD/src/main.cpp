/*
 * main.cpp
 *
 *  Created on: Jan 26, 2014
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
#define min(a, b) ((a)>(b)?(a):(b))
#define infi 0x7FFFFFFF
#define mm 500
using namespace std;

int n, b;
int map[mm][mm];
int ans1[mm][mm], ans2[mm][mm];
struct _queue
{
	int s[mm];
	int t[mm];
	int l, r;
	bool greater;
	void clear(bool g)
	{
		l = r = 0;
		clr(s, 0);
		greater = g;
	}
	_queue()
	{
		clear(false);
	}
	void push(int index, int x)
	{
		while (r > l && ((s[r - 1] >= x) ^ greater))
			--r;
		s[r] = x;
		t[r] = index;
		++r;
	}
	int top()
	{
		return s[l];
	}
	void pop(int index)
	{
		while (r > l && t[l] < index)
			++l;
	}
}q;

void work(int (*ans)[mm], bool g)
{
	rep(i, 1, n)
	{
		q.clear(g);
		rep(j, 1, b)
			q.push(j, map[i][j]);
		rep(j, b + 1, n)
		{
			ans[i][j - b] = q.top();
			q.pop(j - b + 1);
			q.push(j, map[i][j]);
		}
		ans[i][n - b + 1] = q.top();
	}
	rep(i, 1, n - b + 1)
	{
		q.clear(g);
		rep(j, 1, b)
			q.push(j, ans[j][i]);
		rep(j, b + 1, n)
		{
			ans[j - b][i] = q.top();
			q.pop(j - b + 1);
			q.push(j, ans[j][i]);
		}
		ans[n - b + 1][i] = q.top();
	}
}

int main()
{
	freopen("cornfld.in", "r", stdin);
	freopen("cornfld.out", "w", stdout);

	int k;
	scanf("%d%d%d", &n, &b, &k);
	rep(i, 1, n)
		rep(j, 1, n)
			scanf("%d", &map[i][j]);
	work(ans1, false);
	work(ans2, true);
	rep(i, 1, k)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%d\n", ans2[x][y] - ans1[x][y]);
	}

	fclose(stdin);
	fclose(stdout);
}
