/*
 * main.cpp
 *
 *  Created on: Feb 16, 2014
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
#define mm 2010
using namespace std;

char str[mm];
int n, l, r, cnt;

bool compare(int l, int r)
{
	while (r >= l)
	{
		if (str[r] > str[l]) return true;
		if (str[l] > str[r]) return false;
		++l, --r;
	}
	return false;
}

void printc(char ch)
{
	printf("%c", ch);
	++cnt;
	if (cnt >= 80)
	{
		printf("\n");
		cnt = 0;
	}
}

int main()
{
	scanf("%d", &n);
	rep(i, 1, n)
		scanf("%s", &str[i]);
	l = 1, r = n, cnt = 0;
	while (r >= l)
	{
		if (compare(l, r))
		{
			printc(str[l]);
			++l;
		} else {
			printc(str[r]);
			--r;
		}
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}


