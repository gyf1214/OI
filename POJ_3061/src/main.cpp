/*
 * main.cpp
 *
 *  Created on: Feb 23, 2014
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
#define mm 100010
using namespace std;

int a[mm], n, s;

void pre()
{
	scanf("%d%d", &n, &s);
	rep(i, 1, n)
		scanf("%d", &a[i]);
}

int work()
{
	int ans = infi;
	int r = 0, sum = 0;
	rep(l, 1, n)
	{
		while (r < n && sum < s)
		{
			++r;
			sum += a[r];
		}
		if (sum >= s)
			ans = min(ans, max(1, r - l + 1));
		sum -= a[l];
	}
	return ans == infi ? 0 : ans;
}

int main()
{
	int t;
	scanf("%d", &t);
	rep(i, 1, t)
	{
		pre();
		printf("%d\n", work());
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}


