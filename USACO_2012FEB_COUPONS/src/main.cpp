/*
 * main.cpp
 *
 *  Created on: 2013-10-19
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
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))
#define infi 0x7FFFFFFF
#define mm 600000
using namespace std;

long long m;
int k, n;
priority_queue<int> pq2, pq3;

struct _node
{
	int p, c;
	friend bool operator <(_node a, _node b)
	{
		return a.c > b.c;
	}
};

priority_queue<_node> pq1;

int work()
{
	int ans = 0;
	for (;;)
	{
		while (k > 0 && !pq1.empty())
		{
			k--;
			_node x = pq1.top();
			pq1.pop();
			if (x.c > m)
				return ans;
			m -= x.c;
			ans++;
			pq2.push(x.c-x.p);
		}
		if (pq1.empty())
			return ans;
		if (!pq2.empty())
		{
			int x = -pq2.top();
			pq2.pop();
			if (x > m)
				return ans;
			m -= x;
			k++;
		}
	}
}

int main()
{
	freopen("coupons.in", "r", stdin);
	freopen("coupons.out", "w", stdout);

	scanf("%d%d%lld", &n, &k, &m);
	rep(i, 1, n)
	{
		_node x;
		scanf("%d%d", &x.p, &x.c);
		pq1.push(x);
	}
	int ans = work();
	while (!pq1.empty())
	{
		pq3.push(-pq1.top().p);
		pq1.pop();
	}
	while (!pq3.empty())
	{
		int x = -pq3.top();
		pq3.pop();
		if (x > m)
			break;
		ans++;
		m -= x;
	}
	printf("%d\n", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

