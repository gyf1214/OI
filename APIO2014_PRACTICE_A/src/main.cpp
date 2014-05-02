/*
 * main.cpp
 *
 *  Created on: May 1, 2014
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
#define infi 0x7FFFFFFFFFFFFFFFLL
#define mm 200010
#define lb(x) ((x) & (-(x)))
using namespace std;

struct _node
{
	long long a, b, c;
	inline friend bool operator <(_node a, _node b)
	{
		return a.a < b.a;
	}
}node[mm], temp[mm];

long long s[mm];
int k, n;

void modify(int i, long long d)
{
	for (; i <= k; i += lb(i))
		s[i] = min(s[i], d);
}

long long query(int i)
{
	long long ans = infi;
	for (; i; i -= lb(i))
		ans = min(ans, s[i]);
	return ans;
}

void pre()
{
	scanf("%d", &n);
	clr(node, 0);
	clr(temp, 0);
	rep(i, 1, n)
		scanf("%lld%lld%lld", &node[i].a, &node[i].c, &node[i].b);
	sort(node + 1, node + 1 + n);
	rep(i, 1, n)
	{
		node[i].b += node[i - 1].b;
		node[i].c += node[i - 1].c;
	}
	rep(i, 1, n)
	{
		temp[i].a = node[i].b - node[i].a;
		temp[i].b = i;
		temp[i + n].a = node[i].b - node[i + 1].a;
		temp[i + n].b = i + n;
	}
	temp[n + n].a = -node[1].a;
	temp[n + n].b = 0;
	sort(temp + 1, temp + n + n + 1);
	k = 1;
	rep(i, 1, n + n)
	{
		if (i != 1 && temp[i].a != temp[i - 1].a)
			++k;
		if (temp[i].b > n)
			node[temp[i].b - n].b = k;
		else
			node[temp[i].b].a = k;
	}
}

long long work()
{
	rep(i, 1, k)
		s[i] = infi;
	modify(node[0].a, 0);
	long long ans = 0;
	rep(i, 1, n)
	{
		long long t = node[i].c - query(node[i].a);
		ans = max(ans, t);
		if (i < n)
			modify(node[i].b, node[i].c);
	}
	return ans;
}

int main()
{
	freopen("divide.in", "r", stdin);
	freopen("divide.out", "w", stdout);

	pre();
	printf("%lld\n", work());

	fclose(stdin);
	fclose(stdout);
	return 0;
}


