/*
 * main.cpp
 *
 *  Created on: Feb 16, 2014
 *      Author: gyf
 */

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define clr(i, a) memset(i, a, sizeof(i))
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))
#define infi 0x7FFFFFFF
#define mm 1000010
using namespace std;

int main()
{
	int t, n, l, x, ans1, ans2;
	scanf("%d", &t);
	rep(i, 1, t)
	{
		ans1 = ans2 = 0;
		scanf("%d%d", &l, &n);
		rep(i, 1, n)
		{
			scanf("%d", &x);
			ans1 = max(ans1, max(x, l - x));
			ans2 = max(ans2, min(x, l - x));
		}
		printf("%d %d\n", ans2, ans1);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


