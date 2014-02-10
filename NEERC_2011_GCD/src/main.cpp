/*
 * main.cpp
 *
 *  Created on: Feb 10, 2014
 *      Author: gyf
 */

#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define clr(i, a) memset(i, (a), sizeof(i))
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))
#define infi 0x7FFFFFFF
#define mm 20000
using namespace std;

int p[mm];
int np, n;

void pre()
{
	scanf("%d", &n);
	np = 0;
	rep(i, 2, n)
	{
		bool flag = true;
		rep(j, 2, floor(sqrt(i)))
			if (i % j == 0)
			{
				flag = false;
				break;
			}
		if (flag)
			p[++np] = i;
	}
}

int work()
{
	int ans = 0;
	int l = 1, r = np;
	while (l <= r)
	{
		int t = p[r];
		if (l < r && t * p[l] <= n)
			++l;
		++ans;
		--r;
	}
	return ans;
}

int main()
{
	//freopen("gcd.in", "r", stdin);
	//freopen("gcd.out", "w", stdout);

	pre();
	printf("%d\n", work());

	fclose(stdin);
	fclose(stdout);
	return 0;
}


