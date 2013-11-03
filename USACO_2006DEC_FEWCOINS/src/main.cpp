/*
 * main.cpp
 *
 *  Created on: 2013-11-3
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
#define nm 110
#define mm 20010
#define offset 10000
using namespace std;

int c[nm], v[nm], dp[mm], dp0[mm];
int n, t;

int work()
{
	rep(i, -t, t)
		dp0[i + offset] = infi;
	dp0[offset] = 0;
	rep(i, 1, n)
}



