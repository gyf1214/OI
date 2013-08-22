/*
 * main.cpp
 *
 *  Created on: 2013-8-22
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
using namespace std;

int main()
{
	freopen("plank.in", "r", stdin);
	freopen("plank.out", "w", stdout);

	priority_queue<long long> pq;
	int n;
	long long ans = 0;
	scanf("%d", &n);
	rep(i, 1, n)
	{
		int x;
		scanf("%d", &x);
		pq.push(-x);
	}
	rep(i, 2, n)
	{
		long long t = pq.top();
		pq.pop();
		t += pq.top();
		pq.pop();
		ans -= t;
		pq.push(t);
	}
	printf("%lld\n", ans);

	fclose(stdin);
	fclose(stdout);
	return 0;
}




