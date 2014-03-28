/*
 * main.cpp
 *
 *  Created on: 2014-3-28
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
#define mm 40000
#define lb(x) ((x) & (-(x)))
using namespace std;

struct _node
{
	int x, y;
	inline friend bool operator <(_node a, _node b)
	{
		return a.x < b.x;
	}
}node[mm];

int s[mm], n, ans[mm];

void modify(int i)
{
	for (; i < mm; i += lb(i))
		++s[i];
}

int query(int i)
{
	int ans = 0;
	for (; i > 0; i -= lb(i))
		ans += s[i];
	return ans;
}

int main()
{
	scanf("%d", &n);
	rep(i, 1, n)
		scanf("%d%d", &node[i].x, &node[i].y);
	sort(node + 1, node + 1 + n);
	int now = 1;
	clr(ans, 0);
	while (now <= n)
	{
		int k = now;
		modify(node[now].y);
		while (now < n && node[now].x == node[now + 1].x)
		{
			++now;
			modify(node[now].y);
		}
		rep(i, k, now)
		{
			int t = query(node[i].y) - 1;
			++ans[t];
		}
		++now;
	}

	rep(i, 0, n - 1)
		printf("%d\n", ans[i]);

	fclose(stdin);
	fclose(stdout);
	return 0;
}


