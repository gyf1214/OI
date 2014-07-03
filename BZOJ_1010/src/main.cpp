//Created At: Thu Jul 3 19:07:00 CST 2014
//orz zyx
//ntr czr
//Author: gyf

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define clr(i, a) memset(i, (a), sizeof(i))
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)>(b)?(a):(b))
#define infi 0x7FFFFFFF
#define mm 50010
using namespace std;

long long s[mm], t[mm], y[mm], dp[mm];
int q[mm], l, r;
int n;

long long calc(int i, int j)
{
	return y[j] + t[i] * t[i] - 2 * t[i] * s[j];
}

void push(int j)
{
	while (l < r - 1 && 
			(y[j] - y[q[r - 1]]) * (s[q[r - 1]] - s[q[r - 2]]) <
			(y[q[r - 1]] - y[q[r - 2]]) * (s[j] - s[q[r - 1]]))
		--r;
	q[r++] = j;
}

long long pop(int i)
{
	while (l < r - 1 &&
			(calc(i, q[l]) > calc(i, q[l + 1])))
		++l;
	return q[l];
}

void pre()
{
	int l;
	scanf("%d%d", &n, &l);
	s[0] = 0;
	rep(i, 1, n)
	{
		scanf("%lld", &s[i]);
		s[i] += s[i - 1];
	}
	rep(i, 0, n)
	{
		s[i] += i;
		t[i] = s[i] - l - 1;
	}
}

long long work()
{
	dp[0] = 0;
	y[0] = dp[0] + s[0] * s[0];
	l = 0, r = 1;
	q[l] = 0;
	rep(i, 1, n)
	{
		int j = pop(i);
		dp[i] = calc(i, j);
		//printf("%lld %d\n", dp[i], j);
		y[i] = dp[i] + s[i] * s[i];
		push(i);
	}
	return dp[n];
}

int main()
{
	pre();
	printf("%lld\n", work());

	fclose(stdin);
	fclose(stdout);
	return 0;
}

