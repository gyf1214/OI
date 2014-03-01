/*
 * main.cpp
 *
 *  Created on: Mar 1, 2014
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
#define infi 0x3FFFFFFF
#define mm 500100
#define lb(x) ((x) & (-(x))	)
using namespace std;

struct _sorter
{
	int l, r;
	inline friend bool operator <(_sorter a, _sorter b)
	{
		return a.l < b.l;
	}
}node[mm];
int s[mm], n, m;

void modify(int i, int x)
{
	for (; i <= n; i += lb(i))
		s[i] = min(s[i], x);
}

int query(int i)
{
	int ans = infi;
	for (; i > 0; i -= lb(i))
		ans = min(ans, s[i]);
	return ans;
}

void pre()
{
	scanf("%d%d", &n, &m);
	rep(i, 1, n)
		s[i] = infi;
	rep(i, 1, m)
		scanf("%d%d", &node[i].l, &node[i].r);
	modify(n, 0);
}

int work()
{
	rep(i, 1, m)
	{
		int k = query(n + 1 - node[i].l) + 1;
		modify(n + 1 - node[i].r, k);
	}
	return query(1);
}

int main()
{
	pre();
	printf("%d\n", work());

	fclose(stdin);
	fclose(stdout);
	return 0;
}
