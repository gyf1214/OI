/*
 * main.cpp
 *
 *  Created on: 2013-7-26
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
#define mm 200000
using namespace std;

int main()
{
	freopen("profits.in", "r", stdin);
	freopen("profits.out", "w", stdout);

	int n;
	int sum = 0;
	int ans = 0;
	bool flag = false;
	int mini = -infi;
	scanf("%d", &n);
	rep(i, 1, n)
	{
		int x;
		scanf("%d", &x);
		mini = max(mini, x);
		if (x > 0)
			flag = true;
		sum += x;
		if (sum > 0)
			ans = max(ans, sum);
		else
			sum = 0;
	}
	if (flag)
		printf("%d\n", ans);
	else
		printf("%d\n", mini);

	fclose(stdin);
	fclose(stdout);
	return 0;
}


