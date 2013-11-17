/*
 * main.cpp
 *
 *  Created on: 2013-11-17
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
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))
#define infi 0x7FFFFFFF
#define mm 1000010
using namespace std;

int s[mm], t;
int a[mm], ans[mm];

int main()
{
	freopen("lookup.in", "r", stdin);
	freopen("lookup.out", "w", stdout);

	int n;
	scanf("%d", &n);
	rep(i, 1, n)
		scanf("%d", a + i);
	t = 0;
	for (int i = n; i > 0; --i)
	{
		while (t > 0 && a[s[t - 1]] <= a[i])
			--t;
		ans[i] = t > 0 ? s[t - 1] : 0;
		s[t] = i;
		++t;
	}
	rep(i, 1, n)
		printf("%d\n", ans[i]);

	fclose(stdin);
	fclose(stdout);
	return 0;
}



