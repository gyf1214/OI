/*
 * main.cpp
 *
 *  Created on: Mar 4, 2014
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
#define lb(x) ((x) & (-(x)))
#define mm 400010
using namespace std;

int n;
int s1[mm], s2[mm];

void modify(int* s, int i)
{
	for (; i <= n; i += lb(i))
		++s[i];
}

int query(int* s, int i)
{
	int ans = 0;
	for (; i > 0; i -= lb(i))
		ans += s[i];
	return ans;
}

int main()
{
	int m;
	scanf("%d%d", &n, &m);
	rep(i, 1, m)
	{
		int k, l, r;
		scanf("%d%d%d", &k, &l, &r);
		if (k == 1)
		{
			modify(s1, l);
			modify(s2, r);
		}
		else
			printf("%d\n", query(s1, r) - query(s2, l - 1));
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}






