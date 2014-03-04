/*
 * main.cpp
 *
 *  Created on: Mar 4, 2014
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
#define infi 0x4FFFFFFFFFFFFFFFLL
#define lb(x) ((x) & (-(x)))
#define nm 10010
#define mm 100010
using namespace std;

struct _node
{
	int l, r;
	long long w, ans;

	inline friend bool operator <(_node a, _node b)
	{
		return a.r < b.r;
	}
}node[nm];

long long s[mm];
int n, l, r;

void modify(int i, long long x)
{
	for (; i <= r; i += lb(i))
		s[i] = min(s[i], x);
}

long long query(int i)
{
	long long ans = infi;
	for (; i > 0; i -= lb(i))
		ans = min(ans, s[i]);
	return ans;
}

void pre()
{
	scanf("%d%d%d", &n, &l, &r);
	rep(i, 1, n)
	{
		scanf("%d%d%lld", &node[i].l, &node[i].r, &node[i].w);
		node[i].l = max(node[i].l, l);
		node[i].r = min(node[i].r, r);
	}
	sort(node + 1, node + 1 + n);
	rep(i, 1, r)
		s[i] = infi;
}

long long work()
{
	long long ans = infi;
	modify(r - l + 2, 0);
	rep(i, 1, n)
	{
		long long k = query(r - node[i].l + 2) + node[i].w;
		if (node[i].r == r)
			ans = min(ans, k);
		modify(r - node[i].r + 1, k);
	}
	return ans == infi ? -1 : ans;
}

int main()
{
	pre();
	printf("%lld\n", work());

	fclose(stdin);
	fclose(stdout);
	return 0;
}


