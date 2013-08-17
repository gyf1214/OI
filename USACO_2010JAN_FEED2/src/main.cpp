/*
 * main.cpp
 *
 *  Created on: 2013-7-31
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
#define mm 410
using namespace std;

struct _node
{
	int x, f, c;
	friend bool operator <(_node a, _node b)
	{
		return a.x < b.x;
	}
}node[mm];

int n, k;
int dp[mm];

void pre()
{
	int e;
	scanf("%d%d%d", &k, &e, &n);
	rep(i, 1, n)
		scanf("%d%d%d", &(node[i].x), &(node[i].f), &(node[i].c));
	++n;
	node[n].x = e;
	node[n].f = node[n].c = 0;
	sort(node + 1, node + 1 + n);
	node[0].x = node[0].f = node[0].c = 0;
}

int work()
{
	rep(i, 1, k)
		dp[i] = infi / 2;
	dp[0] = 0;
	rep(i, 1, n)
		for (int j = k; j >= 0; --j)
		{
			int t = min(node[i].f, j);
			int calc = infi;
			rep(x, 0, t)
				calc = min(calc, dp[j - x] +
						(j - x) * (node[i].x - node[i - 1].x) +
						node[i].c * x);
			dp[j] = calc;
		}
	return dp[k];
}

int main()
{
	freopen("feed2.in", "r", stdin);
	freopen("feed2.out", "w", stdout);

	pre();
	printf("%d", work());

	fclose(stdin);
	fclose(stdout);
	return 0;
}



