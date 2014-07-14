//Created At: Mon Jul 14 16:51:20 CST 2014
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
#define min(a, b) ((a)<(b)?(a):(b))
#define infi 0x7FFFFFFF
#define nm 10010
#define mm 6000
#define km 600
#define lb(x) ((x) & (-(x)))
using namespace std;

int s[km][mm];
int dp[nm][km];
int a[nm];

void update(int x, int y, int z)
{
	for (int i = x; i < km; i += lb(i))
		for (int j = y; j < mm; j += lb(j))
			s[i][j] = max(s[i][j], z);
}

int query(int x, int y)
{
	int ans = 0;
	for (int i = x; i > 0; i -= lb(i))
		for (int j = y; j > 0; j -= lb(j))
			ans = max(ans, s[i][j]);
	return ans;
}

void work()
{
	clr(s, 0);
	clr(dp, 0);
	int n, k;
	scanf("%d%d", &n, &k);
	rep(i, 1, n)
		scanf("%d", &a[i]);
	int ans = 0;
	rep(i, 1, n)
	{
		rep(j, 0, k)
		{
			dp[i][j] = query(j + 1, a[i] + j + 1) + 1;
			ans = max(ans, dp[i][j]);
		}
		rep(j, 0, k)
			update(j + 1, a[i] + j + 1, dp[i][j]);
	}
	printf("%d\n", ans);
}

int main()
{
	work();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

