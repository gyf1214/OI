/*
 * main.cpp
 *
 *  Created on: 2013-8-29
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
#define mm 50000
#define nm 500
using namespace std;

struct _node
{
	int h, c, a;
	friend bool operator <(_node a, _node b)
	{
		return a.a < b.a;
	}
}node[nm];

int n;
bool dp[mm];

int work()
{
	clr(dp, 0);
	dp[0] = true;
	rep(i, 1, n)
		for (int j = node[i].a; j >= 0; --j)
			rep(k, 1, node[i].c)
				if (j - k * node[i].h >= 0)
					dp[j] =dp[j] || dp[j - k * node[i].h];
	int ans = 0;
	rep(j, 0, node[n].a + node[n].c * node[n].h)
		if (dp[j])
			ans = max(ans, j);
	return ans;
}

int main()
{
	freopen("elevator.in", "r", stdin);
	freopen("elevator.out", "w", stdout);

	scanf("%d", &n);
	rep(i, 1, n)
		scanf("%d%d%d", &node[i].h, &node[i].a, &node[i].c);
	sort(node + 1, node + 1 + n);
	printf("%d\n", work());

	fclose(stdin);
	fclose(stdout);
	return 0;
}


