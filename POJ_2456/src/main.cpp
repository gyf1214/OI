/*
 * main.cpp
 *
 *  Created on: Feb 19, 2014
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

int a[mm], n, k;

int work()
{
	int l = 0, r = infi / 2;
	while (r - l > 1)
	{
		int m = (l + r) / 2;
		int now = 1, t = 1;
		rep(i, 2, n)
			if (a[i] - a[now] >= m)
			{
				++t;
				now = i;
			}
		if (t >= k)
			l = m;
		else
			r = m;
	}
	return l;
}

int main()
{
	scanf("%d%d", &n, &k);
	rep(i, 1, n)
		scanf("%d", &a[i]);
	sort(a + 1, a + 1 + n);
	printf("%d\n", work());

	fclose(stdin);
	fclose(stdout);
	return 0;
}


