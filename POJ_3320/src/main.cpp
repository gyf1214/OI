/*
 * main.cpp
 *
 *  Created on: Feb 23, 2014
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
#define mm 1000010
#define magic
using namespace std;

struct _node
{
	int index, val;
	inline friend bool operator <(_node a, _node b)
	{
		return a.val < b.val;
	}
}node[mm];

int a[mm], n, t;
int v[mm];

void pre()
{
	scanf("%d", &n);
	rep(i, 1, n)
	{
		scanf("%d", &node[i].val);
		node[i].index = i;
	}
	sort(node + 1, node + 1 + n);
	t = 1;
	rep(i, 1, n)
	{
		a[node[i].index] = t;
		if (i < n && node[i].val != node[i + 1].val)
			++t;
	}
}

int work()
{
	int r = 0, sum = 0, ans = infi;
	rep(l, 1, n)
	{
		while (r < n && sum < t)
		{
			++r;
			if (!v[a[r]])
				++sum;
			++v[a[r]];
		}
		if (sum >= t)
			ans = min(ans, r - l + 1);
		--v[a[l]];
		if (!v[a[l]])
			--sum;
	}
	return ans;
}

int main()
{
	pre();
	printf("%d\n", work());

	fclose(stdin);
	fclose(stdout);
	return 0;
}
