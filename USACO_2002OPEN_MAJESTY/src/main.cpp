/*
 * main.cpp
 *
 *  Created on: Mar 11, 2014
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
#define mm 100010
#define sqr(x) ((x) * (x))
using namespace std;

struct _node
{
	long long l, r;
	inline friend bool operator <(_node a, _node b)
	{
		return a.l < b.l;
	}
}node[mm];
int n;

long long work()
{
	sort(node + 1, node + 1 + n);
	long long ans = 0;
	int now = 1;
	while (now <= n)
	{
		int i;
		for (i = now + 1;i <= n && node[i].r <= node[now].r; ++i);
		ans += sqr(node[now].r - node[now].l);
		if (node[i].r > node[now].r && node[i].l < node[now].r)
				ans -= sqr(node[now].r - node[i].l);
		now = i;
	}
	return ans;
}

int main()
{
	freopen("majesty.in", "r", stdin);
	freopen("majesty.out", "w", stdout);

	scanf("%d", &n);
	rep(i, 1, n)
		scanf("%d%d", &node[i].l, &node[i].r);
	printf("%lld\n", work());

	fclose(stdin);
	fclose(stdout);
	return 0;
}

