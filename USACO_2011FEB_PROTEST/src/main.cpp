/*
 * main.cpp
 *
 *  Created on: 2013-11-24
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
#define mod 1000000009
#define lb(x) ((x) & (-(x)))
using namespace std;

struct _node
{
	int rk;
	int x;
	int next;
	inline friend bool operator <(_node a, _node b)
	{
		return a.x < b.x;
	}
}node[mm];

int a[mm], s[mm], f[mm], n;

void add(int i, int d)
{
	for (; i <= n; i += lb(i))
		s[i] = (s[i] + d) % mod;
}

int query(int i)
{
	int ans = 0;
	for (; i > 0; i -= lb(i))
		ans = (ans + s[i]) % mod;
	return ans;
}

int main()
{
	freopen("protest.in", "r", stdin);
	freopen("protest.out", "w", stdout);

	scanf("%d", &n);
	int sum = 0;
	rep(i, 1, n)
	{
		int x;
		scanf("%d", &x);
		sum += x;
		node[i].x = sum;
		node[i].rk = i;
	}
	++n;
	node[n].x = 0;
	node[n].rk = 0;
	sort(node + 1, node + 1 + n);
	int next = n + 1;
	for (int i = n; i >= 1; --i)
	{
		a[node[i].rk] = i;
		node[i].next = next;
		if (node[i].x != node[i - 1].x)
			next = i;
	}
	--n;
	f[0] = 1;
	add(a[0], f[0]);
	rep(i, 1, n)
	{
		f[i] = query(node[a[i]].next - 1);
		add(a[i], f[i]);
	}
	printf("%d\n", f[n]);

	fclose(stdin);
	fclose(stdout);
	return 0;
}
