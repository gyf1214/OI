/*
 * main.cpp
 *
 *  Created on: 2013-9-12
 *      Author: gyf
 */

#include <cstdlib>
#include <cstdio>
#include <cstring>
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define clr(i, a) memset(i, a, sizeof(i))
#define max(a, b) (a)>(b)?(a):(b)
#define min(a, b) (a)<(b)?(a):(b)
#define mm 5010
using namespace std;

double dp[mm];
int n;

int main()
{
	scanf("%d", &n);
	rep(i, 0, mm - 1)
		dp[i] = 101.0;
	dp[0] = .0;
	rep(i, 1, n)
	{
		double w;
		int v;
		scanf("%lf%d", &w, &v);
		for (int j = mm - 1; j >= v; --j)
			dp[j] = min(dp[j], dp[j - v] + w);
	}
	for (int j = mm - 1; j >= 0; --j)
		if (dp[j] <= 100.0)
		{
			printf("%d\n", j);
			break;
		}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
