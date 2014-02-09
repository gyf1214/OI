/*
 * main.cpp
 *
 *  Created on: Feb 9, 2014
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
#define mm 50
using namespace std;

void printbin(int i, int k)
{
	int buffer[mm];
	clr(buffer, 0);
	int t = 0;
	for (; i; i /= 2)
		buffer[t++] = i % 2;
	for (--k; k >= 0; --k)
		printf("%d", buffer[k]);
	printf("\n");
}

int main()
{
	int m, n = 0;
	scanf("%d", &m);
	for (int i = m - 1; i; i /= 2)
		++n;
	int t = (1 << n) - m;
	rep(i, 0, t - 1)
		printbin(i, n - 1);
	rep(i, max(t, 0), (1 << (n - 1)) - 1)
	{
		printbin(2 * i, n);
		printbin(2 * i + 1, n);
	}
}


