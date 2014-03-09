/*
 * main.cpp
 *
 *  Created on: Mar 9, 2014
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
#define nm 20
#define mm 300000
using namespace std;

int w[nm], f[mm], g[mm];
int n, c;

void work()
{
	int m = (1 << n) - 1;
	clr(g, 0);
	rep(i, 1, m)
		f[i] = infi;
	f[0] = 1;
	g[0] = c;
	rep(i, 0, m)
		rep(j, 1, n)
			if (((1 << (j - 1)) & i) == 0)
			{
				int t = ((1 << (j - 1)) | i);
				if (g[i] >= w[j] && f[i] <= f[t])
				{
					f[t] = f[i];
					g[t] = max(g[t], g[i] - w[j]);
				}
				if (f[i] + 1 <= f[t])
				{
					f[t] = f[i] + 1;
					g[t] = max(g[t], c - w[j]);
				}
			}
}

int main()
{
	freopen("skyscaper.in", "r", stdin);
	freopen("skyscaper.out", "w", stdout);

	scanf("%d%d", &n, &c);
	rep(i, 1, n)
		scanf("%d", &w[i]);
	work();
	printf("%d\n", f[(1 << n) - 1]);

	fclose(stdin);
	fclose(stdout);
	return 0;
}


