/*
 * main.cpp
 *
 *  Created on: 2013-8-21
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
#define mm 2000
using namespace std;


int main()
{
	freopen("neg2.in", "r", stdin);
	freopen("neg2.out", "w", stdout);
	int n, t = 0, ans[mm];
	scanf("%d", &n);
	while (n != 0)
	{
		ans[t++] = ((n % 2) + 2) % 2;
		n -= ans[t - 1];
		n /= -2;
	}
	if (t == 0)
		printf("0");
	for (int i = t - 1; i >= 0; --i)
		printf("%d", ans[i]);
	printf("\n");

	fclose(stdin);
	fclose(stdout);
	return 0;
}


