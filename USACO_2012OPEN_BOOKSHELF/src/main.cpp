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
#define mm 100100
using namespace std;

typedef pair<long long, int > pii;

long long a[mm], b[mm];
int n, hn;
int q[mm], l, r;
bool die[mm];
pii h[mm];
long long dp[mm];
long long k;

void swap(pii& a, pii& b)
{
	pii t = a;
	a = b;
	b = t;
}

void up(int i)
{
	int j = i / 2;
	if (j > 0 && h[i] < h[j])
	{
		swap(h[i], h[j]);
		up(j);
	}
}

void down(int i)
{
	int j = 2 * i;
	if (j < hn && h[j + 1] < h[j])
		++j;
	if (j <= hn && h[j] < h[i])
	{
		swap(h[i], h[j]);
		down(j);
	}
}

void push(int i, long long x)
{
	++hn;
	h[hn] = make_pair(x, i);
	up(hn);
}

void pop()
{
	swap(h[1], h[hn]);
	--hn;
	down(1);
}

pii top()
{
	while (hn > 0 && die[h[1].second])
		pop();
	return h[1];
}

void work()
{
	l = 1;
	r = 1;
	clr(dp, 0);
	clr(die, 0);
	q[0] = 0;
	int left = 0;
	rep(i, 1, n)
	{
		while (a[i] - a[left] > k)
		{
			++left;
			if (l < r && left > q[l - 1])
			{
				die[q[l]] = true;
				++l;
			}
		}
		while (l < r && b[i] >= b[q[r - 1]])
		{
			die[q[r - 1]] = true;
			--r;
		}
		if (l == r && b[i] >= b[q[r - 1]])
			q[l - 1] = i;
		else
			q[r] = i;
		dp[i] = dp[left] + b[q[l - 1]];
		if (q[r] == i)
			dp[i] = min(dp[i], dp[q[r - 1]] + b[i]);
		top();
		if (hn > 0)
		{
			pii best = top();
			dp[i] = min(dp[i], best.first);
		}
		if (i == q[r])
		{
			push(i, dp[q[r - 1]] + b[i]);
			++r;
		}
	}
}

int main()
{
	freopen("bookshelf.in", "r", stdin);
	freopen("bookshelf.out", "w", stdout);

	scanf("%d%lld", &n, &k);
	a[0] = 0;
	b[0] = 0;
	rep(i, 1, n)
	{
		long long x;
		scanf("%lld%lld", &b[i], &x);
		a[i] = a[i - 1] + x;
	}
	work();
	printf("%lld\n", dp[n]);

	fclose(stdin);
	fclose(stdout);
	return 0;
}


