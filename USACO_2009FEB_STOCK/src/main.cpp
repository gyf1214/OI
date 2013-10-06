/*
 * main.cpp
 *
 *  Created on: 2013-10-6
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
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))
#define infi 0x7FFFFFFF
#define mm 500010
#define nm 60
using namespace std;

int m, s, d;
int p[nm][nm], f[mm];

int work()
{
	rep(i, 1, d - 1)
	{
		rep(x, 0, m)
			f[x] = x;
		rep(j, 1, s)
			rep(x, 0, m - p[i][j])
				f[x + p[i][j]] = max(f[x + p[i][j]], f[x] + p[i + 1][j]);
		m = f[m];
	}
	return m;
}

int main()
{
	freopen("stock.in", "r", stdin);
	freopen("stock.out", "w", stdout);

	scanf("%d%d%d", &s, &d, &m);
	rep(i, 1, s)
		rep(j, 1, d)
			scanf("%d", &p[j][i]);

	printf("%d\n", work());

	fclose(stdin);
	fclose(stdout);
	return 0;
}
