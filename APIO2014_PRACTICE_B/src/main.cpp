/*
 * main.cpp
 *
 *  Created on: May 1, 2014
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
#define mm 1010
using namespace std;

int a[mm][mm], len[mm][mm];
int s[mm];
int n, m;

int check(int k)
{
	clr(len, 0);
	int ans = 0;
	rep(i, 1, n)
	{
		rep(j, 1, m)
			if (a[i][j] >= k)
				len[i][j] = len[i - 1][j] + 1;
		int top = 0;
		clr(s, 0);
		rep(j, 1, m + 1)
		{
			while (top > 0 && len[i][s[top]] >= len[i][j])
			{
				ans = max(ans, len[i][s[top]] * (j - 1 - s[top - 1]));
				--top;
			}
			s[++top] = j;
		}
	}
	return ans;
}

void work(int k)
{
	int l = 0, r = 1000000010;
	while (r - l > 1)
	{
		int m = (l + r) / 2;
		if (check(m) >= k)
			l = m;
		else
			r = m;
	}
	printf("%d %d\n", l, check(l));
}

int main()
{
	freopen("burrow.in", "r", stdin);
	freopen("burrow.out", "w", stdout);

	int k;
	scanf("%d%d%d", &n, &m, &k);
	rep(i, 1, n)
		rep(j, 1, m)
			scanf("%d", &a[i][j]);
	work(k);

	fclose(stdin);
	fclose(stdout);
	return 0;
}



