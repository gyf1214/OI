/*
 * main.cpp
 *
 *  Created on: 2013-9-11
 *      Author: gyf
 */

#include <cstdlib>
#include <cstdio>
#include <queue>
#define rep(i, a, b) for (int i = a; i <= b; ++i)
using namespace std;

int main()
{
	freopen("disease.in", "r", stdin);
	freopen("disease.out", "w", stdout);

	int n;
	priority_queue<long long> pq;
	scanf("%d", &n);
	rep(i, 1, n)
	{
		int x;
		scanf("%d", &x);
		pq.push(-x);
	}
	long long ans = 0;
	rep(i, 1, n - 1)
	{
		long long x = -pq.top();
		pq.pop();
		x -= pq.top();
		pq.pop();
		ans += x;
		pq.push(-x);
	}
	printf("%lld\n", ans);

	fclose(stdin);
	fclose(stdout);
	return 0;
}


