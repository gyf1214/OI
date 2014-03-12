/*
 * main.cpp
 *
 *  Created on: Mar 12, 2014
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
#define mm 200
using namespace std;

struct _node
{
	int j, index;
	inline friend bool operator <(_node a, _node b)
	{
		return a.j > b.j;
	}
}a[mm];
int n;

void swap(_node& a, _node& b)
{
	_node t = a;
	a = b;
	b = t;
}

void work()
{
	sort(a + 1, a + 1 + 3 * n);
	int sum1 = 0, sum2 = 0;
	rep(i, 1, n)
		sum1 += a[i].j;
	rep(i, n + 1, 2 * n)
		sum2 += a[i].j;
	while (sum1 <= 0 || sum2 <= 0)
	{
		int i = rand() % n + 1;
		int j = rand() % n + n + 1;
		sum1 += a[j].j - a[i].j;
		sum2 += a[i].j - a[j].j;
		swap(a[i], a[j]);
	}
}

int main()
{
	freopen("jpol.in", "r", stdin);
	freopen("jpol.out", "w", stdout);
	srand(35);
	scanf("%d", &n);
	rep(i, 1, 3 * n)
	{
		scanf("%d", &a[i].j);
		a[i].j -= 500;
		a[i].index = i;
	}
	work();
	rep(i, 1, 3 * n)
		printf("%d\n", a[i].index);

	fclose(stdin);
	fclose(stdout);
	return 0;
}


