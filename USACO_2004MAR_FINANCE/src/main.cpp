/*
 * main.cpp
 *
 *  Created on: 2013-11-16
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
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))
#define infi 0x7FFFFFFF
#define mm 100010
using namespace std;

struct _node
{
	int c, q;
	inline friend bool operator <(_node a, _node b)
	{
		return a.c < b.c;
	}
}node[mm];
int n, f, c, a[mm], b[mm];

bool check(int k)
{
	rep(i, 1, k - 1)
		a[i] = node[i].q;
	rep(i, k + 1, c)
		b[i - k] = node[i].q;
	sort(a + 1, a + k);
	sort(b + 1, b + c - k + 1);
	int ans = node[k].q;
	rep(i, 1, n)
		ans += a[i] + b[i];
	return ans <= f;
}

int main()
{
	freopen("finance.in", "r", stdin);
	freopen("finance.out", "w", stdout);

	scanf("%d%d%d", &n, &c, &f);
	rep(i, 1, c)
		scanf("%d%d", &node[i].c, &node[i].q);
	sort(node + 1, node + c + 1);
	n /= 2;
	int l = n + 1;
	int r = c - n + 1;
	while (r - l > 1)
	{
		int m = (l + r) / 2;
		if (check(m))
			l = m;
		else
			r = m;
	}
	if (check(l))
		printf("%d\n", node[l].c);
	else
		printf("%d\n", -1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}



