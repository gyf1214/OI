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
#define lb(x) ((x) & (-(x)))
#define infi 0x7FFFFFFF
#define mm 2000
using namespace std;

int s[mm][mm];
int n;

void modify(int x, int y, int a)
{
	for (int i = x; i <= n; i += lb(i))
		for (int j = y; j <= n; j += lb(j))
			s[i][j] += a;
}

int query(int x, int y)
{
	int ans = 0;
	for (int i = x; i > 0; i -= lb(i))
		for (int j = y; j > 0; j -= lb(j))
			ans += s[i][j];
	return ans;
}

int main()
{
	int nothing, c;
	scanf("%d%d", &nothing, &n);
	clr(s, 0);
	scanf("%d", &c);
	while (c != 3)
	{
		if (c == 1)
		{
			int x, y, a;
			scanf("%d%d%d", &x, &y, &a);
			modify(x + 1, y + 1, a);
		} else if (c == 2)
		{
			int l, b, r, t;
			scanf("%d%d%d%d", &l, &b, &r, &t);
			printf("%d\n", query(r + 1, t + 1) -
					query(l, t + 1) - query(r + 1, b) + query(l, b));
		}
		scanf("%d", &c);
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}


