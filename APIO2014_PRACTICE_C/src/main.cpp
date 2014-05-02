/*
 * main.cpp
 *
 *  Created on: May 1, 2014
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
#define infi 0x7FFFFFF
#define mm 300010
#define lb(x) ((x) & (-(x)))
using namespace std;

struct _node
{
	int l, r, x;
	inline friend bool operator <(_node a, _node b)
	{
		return a.l < b.l;
	}
}node[mm];
int s[mm], n, m;

void modify(int i, int d)
{
	for (; i <= n; i += lb(i))
		s[i] = max(s[i], d);
}

int query(int i)
{
	int ans = -infi;
	for (; i; i -= lb(i))
		ans = max(ans, s[i]);
	return ans;
}

void pre()
{
	scanf("%d%d", &n, &m);
	rep(i, 1, m)
		scanf("%d%d%d", &node[i].l, &node[i].r, &node[i].x);
	sort(node + 1, node + 1 + m);
}

void work()
{
	rep(i, 1, n)
		s[i] = -infi;
	int k = 1;
	rep(i, 1, n)
	{
		while (k <= m && node[k].l <= i)
		{
			modify(n + 1 - node[k].r, node[k].x - node[k].l);
			++k;
		}
		int ans = query(n + 1 - i);
		if (ans == -infi)
			ans = 0;
		else
			ans += i;
		printf("%d%c", ans, i == n ? '\n' : ' ');
	}
}

int main()
{
	freopen("trading.in", "r", stdin);
	freopen("trading.out", "w", stdout);

	pre();
	work();

	fclose(stdin);
	fclose(stdout);
	return 0;
}
