/*
 * main.cpp
 *
 *  Created on: Jun 1, 2014
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
#define mm 1000010
#define mod 1073741824
using namespace std;

int p[mm], d[mm];

void pre(int n)
{
	clr(p, 0);
	p[1] = 1;
	rep(i, 2, n)
		if (!p[i])
		{
			p[i] = 1;
			rep(j, 2, n / i)
				if (!p[i * j])
					p[i * j] = i;
		}
	d[1] = 1;
	rep(i, 2, n)
		if (p[i] == 1)
			d[i] = 2;
		else
		{
			int j = 1, k = i;
			for (; k % p[i] == 0; k /= p[i])
				++j;
			d[i] = (j * d[k]) % mod;
		}
}

int main()
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	pre(a * b * c);
	int ans = 0;
	rep(i, 1, a)
		rep(j, 1, b)
			rep(k, 1, c)
				ans = (ans + d[i * j * k]) % mod;
	printf("%d\n", ans);

	fclose(stdin);
	fclose(stdout);
	return 0;
}
