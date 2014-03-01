/*
 * main.cpp
 *
 *  Created on: Mar 1, 2014
 *      Author: gyf
 */

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define clr(i, a) memset(i, (a), sizeof(i))
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))
#define infi 0x7FFFFFFF
#define eps 1e-9
#define mm 40010
using namespace std;

struct _node
{
	int a;
	double x, y;
}node[mm];
int n, m, l[mm];
int height, size;
double pi;

void merge(int i)
{
	node[i].a = (node[2 * i].a + node[2 * i + 1].a) % 360;
	double a = (node[2 * i].a + .0) / 180.0 * pi;
	node[i].x = node[2 * i].x + cos(a) * node[2 * i + 1].x - sin(a) * node[2 * i + 1].y;
	node[i].y = node[2 * i].y + sin(a) * node[2 * i + 1].x + cos(a) * node[2 * i + 1].y;
}

void update(int i, int a)
{
	i += size;
	node[i].a = (a - 180) % 360;
	node[i].x = l[i - size] * cos((node[i].a + .0) / 180.0 * pi);
	node[i].y = l[i - size] * sin((node[i].a + .0) / 180.0 * pi);
	for (i /= 2; i; i /= 2)
		merge(i);
}

bool pre()
{
	if (scanf("%d%d", &n, &m) == EOF)
		return false;
	rep(i, 1, n)
		scanf("%d", &l[i]);
	height = 0;
	for (int i = n + 1; i; i /= 2)
		++height;
	size = 1 << height;
	rep(i, 1, n)
	{
		node[i + size].a = 0.0;
		node[i + size].x = l[i];
	}
	for (int i = size - 1; i; --i)
		merge(i);
	return true;
}

void work()
{
	rep(i, 1, m)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		update(x + 1, y);
		printf("%.2lf %.2lf\n", eps - node[1].y, eps + node[1].x);
	}
	printf("\n");
}

int main()
{
	pi = atan(1.0) * 4.0;
	while (pre())
		work();

	fclose(stdin);
	fclose(stdout);
	return 0;
}


