/*
 * main.cpp
 *
 *  Created on: May 17, 2014
 *      Author: gyf
 */

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <bitset>
#define rep(i, a, b) for (int i =(a); i <= (b); ++i)
#define clr(i, a) memset(i, (a), sizeof(i))
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))
#define infi 0x7FFFFFFF
#define nm 1010
#define mm 1000010
using namespace std;

bitset<mm> bs;
int n;

int main()
{
	scanf("%d", &n);
	bs ^= 1;
	rep(i, 1, n)
	{
		int x;
		scanf("%d", &x);
		bs = bs ^ (bs << x);
	}
	int ans = 0;
	rep(i, 1, mm - 1)
		if (bs.test(i))
			ans = ans ^ i;
	printf("%d\n", ans);

	fclose(stdin);
	fclose(stdout);
	return 0;
}
