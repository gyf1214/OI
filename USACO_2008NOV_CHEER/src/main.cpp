/*
 * main.cpp
 *
 *  Created on: 2013-8-2
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
#define max(a, b) (a)>(b)?(a):(b)
#define min(a, b) (a)<(b)?(a):(b)
#define infi 0x7FFFFFFF
#define mm 100010
using namespace std;

struct _edeg
{
	int start, tail, weight;
	friend bool operator < (_edeg a, _edeg b)
	{
		return a.weight < b.weight;
	}
}edeg[mm];

int a[mm], p[mm];
int n, m;

int find(int u)
{
	if (p[u] != u)
		p[u] = find(p[u]);
	return p[u];
}

void merge(int u, int v)
{
	u = find(u);
	v = find(v);
	p[u] = v;
}

void pre()
{
	scanf("%d%d", &n, &m);
	rep(i, 1, n)
		scanf("%d", a + i);
	rep(i, 1, m)
	{
		scanf("%d%d%d", &(edeg[i].start), &(edeg[i].tail), &(edeg[i].weight));
		edeg[i].weight *= 2;
		edeg[i].weight += a[edeg[i].start] + a[edeg[i].tail];
	}
}

int work()
{
	int ans = 0;
	sort(edeg + 1, edeg + m + 1);
	rep(i, 1, n)
		p[i] = i;
	rep(i, 1, m)
	{
		int u = edeg[i].start;
		int v = edeg[i].tail;
		if (find(u) != find(v))
		{
			ans += edeg[i].weight;
			merge(u, v);
		}
	}
	int mini = infi;
	rep(i, 1, n)
		mini = min(mini, a[i]);
	return mini + ans;
}

int main()
{
	freopen("cheer.in", "r", stdin);
	freopen("cheer.out", "w", stdout);

	pre();
	printf("%d\n", work());

	fclose(stdin);
	fclose(stdout);
	return 0;
}

