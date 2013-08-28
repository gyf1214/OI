/*
 * main.cpp
 *
 *  Created on: 2013-8-28
 *      Author: gyf
 */

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define clr(i, a) memset(i, a, sizeof(i))
#define max(a, b) (a)>(b)?(a):(b)
#define min(a, b) (a)<(b)?(a):(b)
#define infi 0x7FFFFFFF
#define mm 20010
using namespace std;

struct _node
{
	int x, s;
	friend bool operator <(_node a, _node b)
	{
		return a.x < b.x;
	}
}node[mm];

int n;

priority_queue<int> pq;

int work(int l, int p)
{
	int now = 1;
	int ans = 0;
	while (l < p && now <= n)
	{
		while (now <= n && node[now].x <= l)
			pq.push(node[now++].s);
		if (!pq.empty())
		{
			l += pq.top();
			pq.pop();
			++ans;
		} else {
			break;
		}
	}
	return l >= p ? ans : -1;
}

int main()
{
	freopen("exp.in", "r", stdin);
	freopen("exp.out", "w", stdout);

	scanf("%d", &n);
	rep(i, 1, n)
		scanf("%d%d", &node[i].x, &node[i].s);
	int l, p;
	scanf("%d%d", &p, &l);
	rep(i, 1, n)
		 node[i].x = p - node[i].x;
	sort(node + 1, node + n + 1);
	printf("%d\n", work(l, p));

	fclose(stdin);
	fclose(stdout);
	return 0;
}
