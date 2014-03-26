/*
 * main.cpp
 *
 *  Created on: Mar 26, 2014
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
#define mm 300010
using namespace std;

struct _node
{
	int l, r, flag;
	inline friend bool operator <(_node a, _node b)
	{
		return (a.l < b.l) || ((a.l == b.l) && (a.r > b.r));
	}
}node[mm];

_node* s[mm];
int top, n;

int solve()
{
	int ans = n + 1;
	top = 0;
	rep(i, 1, n)
	{
		if (top != 0)
		{
			if (s[top] -> r >= node[i].r)
			{
				if (s[top] -> l != node[i].l)
					s[top] -> flag = true;
			} else {
				while (top > 1 && s[top] -> r < node[i].r)
					--top;
				if (s[top + 1] -> r != node[i].l)
					s[top] -> flag = true;
				if (top > 0 && s[top] -> r == node[i].r && !s[top] -> flag)
					++ans;
			}
		}
		s[++top] = node + i;
	}
	return ans;
}

int main()
{
	freopen("kruznice.in", "r", stdin);
	freopen("kruznice.out", "w", stdout);

	scanf("%d", &n);
	rep(i, 1, n)
	{
		int x, r;
		scanf("%d%d", &x, &r);
		node[i].l = x - r;
		node[i].r = x + r;
		node[i].flag = false;
	}
	sort(node + 1, node + 1 + n);
	printf("%d\n", solve());

	fclose(stdin);
	fclose(stdout);
	return 0;
}


