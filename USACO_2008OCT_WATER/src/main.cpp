/*
 * main.cpp
 *
 *  Created on: Jan 24, 2014
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
#define min(a, b) ((a)<(b)?(a):(b))
#define infi 0x7FFFFFFF
#define mm 500
using namespace std;

int map[mm][mm], n;
int dist[mm];

int work()
{
	int ans = 0;
	dist[1] = 0;
	rep(i, 2, n)
		dist[i] = map[i][1];
	rep(i, 2, n)
	{
		int t = infi;
		int k;
		rep(j, 1, n)
			if (dist[j] > 0 && dist[j] < t)
			{
				t = dist[j];
				k = j;
			}
		ans += dist[k];
		dist[k] = 0;
		rep(j, 1, n)
			if (dist[j] > 0 && dist[j] > map[j][k])
				dist[j] = map[j][k];
	}
	return ans;
}

int main()
{
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);

	scanf("%d", &n);
	rep(i, 1, n)
	{
		int k;
		scanf("%d", &k);
		map[i][n + 1] = map[n + 1][i] = k;
	}
	rep(i, 1, n)
		rep(j, 1, n)
			scanf("%d", &map[i][j]);
	++n;
	printf("%d\n", work());

	fclose(stdin);
	fclose(stdout);
	return 0;
}


