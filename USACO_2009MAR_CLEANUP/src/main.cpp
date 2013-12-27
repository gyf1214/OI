/*
 * main.cpp
 *
 *  Created on: 2013-12-27
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
#define mm 50000
using namespace std;

int p[mm], n;
int s[mm], m;
int tag[mm], dp[mm];

void work()
{
	for (m = 1; m * m <= n; ++m);
	--m;
	dp[0] = 0;
	s[0] = 0;
	clr(s, 0);
	clr(tag, 0);
	rep(i, 1, n)
	{
		int k;
		for (k = 0; k <= m && s[k] != tag[p[i]]; ++k);
		for (; k >0 ; --k)
			s[k] = s[k - 1];
		s[0] = i;
		dp[i] = i;
		rep(j, 1, m)
			dp[i] = min(dp[i], dp[s[j]] + j * j);
		tag[p[i]] = i;
	}
}

int main()
{
	freopen("cleanup.in", "r", stdin);
	freopen("cleanup.out", "w", stdout);

	int t;
	scanf("%d%d", &n, &t);
	rep(i, 1, n)
		scanf("%d", p + i);
	work();
	printf("%d\n", dp[n]);

	fclose(stdin);
	fclose(stdout);
	return 0;
}


