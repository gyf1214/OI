/*
 * main.cpp
 *
 *  Created on: 2013-7-23
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
#define mm 100010

int dp[mm], s[mm], q[mm];
int n, m, l, r, k, st, ed;

inline void push(int i)
{
	while (r > l && dp[i] < dp[q[r]])
		r--;
	q[r++] = i;
}

inline int pop(int i)
{
	while (r > l && s[i] - s[q[l]] > k)
		l++;
	return q[l];
}

void pre()
{
	scanf("%d%d", &n, &m);
	clr(s, 0);
	st = 0;
	rep(i, 1, n)
	{
		int x;
		scanf("%d", &x);
		st = max(st, x);
		s[i] = s[i - 1] + x;
	}
}

bool work()
{
	clr(q, 0);
	l = 0;
	r = 0;
	dp[0] = 0;
	push(0);
	rep(i, 1, n)
	{
		int t = pop(i);
		dp[i] = dp[t] + 1;
		push(i);
	}
	return dp[n] <= m;
}

int main()
{
	freopen("expense.in", "r", stdin);
	freopen("expense.out", "w", stdout);

	pre();
	ed = s[n];
	while (ed - st > 1)
	{
		k = (st + ed + 1) / 2;
		if (work())
			ed = k;
		else
			st = k;
	}
	k = st;
	if (work())
		printf("%d\n", st);
	else
		printf("%d\n", ed);

	fclose(stdin);
	fclose(stdout);
	return 0;
}





