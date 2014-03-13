/*
 * main.cpp
 *
 *  Created on: Mar 13, 2014
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
#define mm 500010
#define infi 0x7FFFFFFF
using namespace std;

struct _node
{
	_node* child[2];
	int end;
	int cnt;
}node[mm];
int m, n, nn;

void build()
{
	clr(node, 0);
	nn = 0;
	rep(i, 1, m)
	{
		int b;
		_node* now = node;
		scanf("%d", &b);
		rep(i, 1, b)
		{
			++now -> cnt;
			int x;
			scanf("%d", &x);
			if (!now -> child[x])
			{
				++nn;
				now -> child[x] = &node[nn];
			}
			now = now -> child[x];
		}
		++now -> cnt;
		++now -> end;
	}
}

void work()
{
	rep(i, 1, n)
	{
		int b, ans = 0;
		_node* now = node;
		scanf("%d", &b);
		rep(i, 1, b)
		{
			int x;
			scanf("%d", &x);
			if (now)
			{
				ans += now -> end;
				now = now -> child[x];
			}
		}
		if (now)
			ans += now -> cnt;
		printf("%d\n", ans);
	}
}

int main()
{
	freopen("sec.in", "r", stdin);
	freopen("sec.out", "w", stdout);

	scanf("%d%d", &m, &n);
	build();
	work();

	fclose(stdin);
	fclose(stdout);
	return 0;
}


