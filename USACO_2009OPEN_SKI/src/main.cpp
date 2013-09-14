/*
 * main.cpp
 *
 *  Created on: 2013-9-14
 *      Author: gyf
 */

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#define rep(i, a, b) for (int i = a; i <= b ;++i)
#define clr(i, a) memset(i, a, sizeof(i))
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))
#define infi 0x7FFFFFFF
#define mm 11010
#define nm 110
#define tm 100010
using namespace std;

struct _line
{
	int time, a;
	friend bool operator < (_line a, _line b)
	{
		return a.a < b.a;
	}
}line[tm];

struct _course
{
	int s, l, a;
}course[nm];

int dp[mm][nm];
int tim[nm];
int t, s, n;

void pre()
{
	scanf("%d%d%d", &t, &s, &n);
	rep(i, 1, s)
		scanf("%d%d%d", &course[i].s, &course[i].l, &course[i].a);
	rep(i, 1, n)
		scanf("%d%d", &line[i].a, &line[i].time);
	clr(tim, 0);
	rep(i, 1, nm - 1)
		rep(j, 1, n)
			if (i >= line[j].a)
				if (tim[i] == 0 || tim[i] > line[j].time)
					tim[i] = line[j].time;
}

int work()
{
	rep(i, 0, t)
		rep(j, 1, nm - 1)
			dp[i][j] = -infi;
	dp[0][1] = 0;
	rep(i, 0, t)
		rep(j, 1, nm - 1)
		{
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
			if (tim[j] > 0)
				dp[i + tim[j]][j] = max(dp[i + tim[j]][j], dp[i][j] + 1);
			rep(k, 1, s)
				if (course[k].s == i)
					dp[i + course[k].l][course[k].a] = max(dp[i + course[k].l][course[k].a], dp[i][j]);
		}
	int ans = 0;
	rep(j, 1, nm - 1)
		ans = max(ans, dp[t][j]);
	return ans;
}

int main()
{
	freopen("ski.in", "r", stdin);
	freopen("ski.out", "w", stdout);

	pre();
	printf("%d\n", work());

	fclose(stdin);
	fclose(stdout);
	return 0;
}
