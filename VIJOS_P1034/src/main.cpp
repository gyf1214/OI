/*
 * main.cpp
 *
 *  Created on: 2014-3-28
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
#define mm 6000
using namespace std;

int p[mm];
int n;

int find(int i)
{
	if (p[i] != i)
		p[i] = find(p[i]);
	return p[i];
}

void merge(int i, int j)
{
	i = find(i);
	j = find(j);
	p[i] = j;
}

int main()
{
	int m, k;
	scanf("%d%d%d", &n, &m, &k);
	rep(i, 1, n)
		p[i] = i;
	rep(i, 1, m)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		merge(x, y);
	}
	rep(i, 1, k)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		x = find(x);
		y = find(y);
		printf("%s\n", x == y ? "Yes" : "No");
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}



