/*
 * main.cpp
 *
 *  Created on: Mar 19, 2014
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
#define mm 100010
using namespace std;

struct _node
{
	int index, val;
	inline friend bool operator <(_node a, _node b)
	{
		return a.val < b.val;
	}
}node[mm];

int a[mm], pos[5][mm], b[mm];
int n;

void pre()
{
	scanf("%d", &n);
	rep(i, 1, 5 * n)
	{
		scanf("%d", &node[i].val);
		node[i].index = i;
	}
	sort(node + 1, node + 1 + 5 * n);
	int k = 0;
	rep(i, 1, 5 * n)
	{
		if (i == 1 || node[i].val != node[i - 1].val)
		{
			++k;
			b[k] = node[i].val;
		}
		a[node[i].index] = k;
	}
	rep(i, 0, 4)
		rep(j, 1, n)
		{
			int k = i * n + j;
			pos[i][a[k]] = j;
		}
}

bool cmp(int a, int b)
{
	int cnt = 0;
	rep(i, 0, 4)
		if (pos[i][a] < pos[i][b])
			++cnt;
	return cnt > 2;
}

int main()
{
	freopen("photo.in", "r", stdin);
	freopen("photo.out", "w", stdout);

	pre();
	sort(a + 1, a + 1 + n, cmp);
	rep(i, 1, n)
		printf("%d\n", b[a[i]]);

	fclose(stdin);
	fclose(stdout);
	return 0;
}
