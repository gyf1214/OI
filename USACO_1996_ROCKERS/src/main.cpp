/*
 * main.cpp
 *
 *  Created on: 2013-10-6
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
#define mm 1010
using namespace std;

struct _f
{
	int t, k;
}f[mm], f0[mm];

int a[mm];
int n, c, m;

int work()
{
	rep(i, 0, n)
		f[i].k = f[i].t = infi / 3;
	f[0].k = 0;
	f[0].t = 0;
	rep(i, 1, n)
	{
		rep(j, 0, n)
			f0[j] = f[j];
		f[0] = f0[0];
		rep(j, 1, n)
			if (f0[j - 1].t + a[i] <= c)
			{
				if (f0[j].k > f0[j - 1].k)
				{
					f[j].k = f0[j - 1].k;
					f[j].t = f0[j - 1].t + a[i];
				}
			} else {
				if (f0[j].k > f0[j - 1].k + 1)
				{
					f[j].k = f0[j - 1].k + 1;
					f[j].t = a[i];
				}
			}
	}
	int ans;
	for (ans = n; ans >= 0; --ans)
		if (f[ans].k < m)
			break;
	return ans;
}

int main()
{
	//freopen("rockers.in", "r", stdin);
	//freopen("rockers.out", "w", stdout);

	scanf("%d%d%d", &n, &c, &m);
	rep(i, 1, n)
		scanf("%d", &a[i]);
	printf("%d\n", work());

	fclose(stdin);
	fclose(stdout);
	return 0;
}



