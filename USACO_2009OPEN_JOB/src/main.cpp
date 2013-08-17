/*
 * main.cpp
 *
 *  Created on: 2013-8-1
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
#define lb(x) ((x)&(-(x)))
#define infi 0x7FFFFFFF
#define mm 400010
using namespace std;

struct _node
{
	long long weight, time, rank;
	_node()
	{
		weight = time = rank = 0;
	}
	friend bool operator <(_node a, _node b)
	{
		return a.time < b.time;
	}
}node[mm];

int n, hn;
long long heap[mm];

void pre()
{
	scanf("%d", &n);
	rep(i, 1, n)
		scanf("%lld%lld", &node[i].time, &node[i].weight);
	sort(node, node + 1, node + 1 + n);
}

int work()
{
	int k = infi;
	hn = 0;
	for (int i = n; i >= 0; --i)
	{
		while (k > node[i].weight && hn > 0)
		{
			--k;
			pop_heap(node, node + hn + 1);
			--hn;
		}
	}
}


