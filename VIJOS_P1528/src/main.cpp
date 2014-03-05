/*
 * main.cpp
 *
 *  Created on: Mar 5, 2014
 *      Author: gyf
 */

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <iostream>
#include <algorithm>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define clr(i, a) memset(i, (a), sizeof(i))
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))
#define infi 0x7FFFFFFF
#define lb(x) ((x) & (-(x)))
#define mm 30010
#define nm 1010
using namespace std;

struct _node
{
	int x, y, r, w;
}node[nm];

int n, m, k;
int l[mm], r[mm];

typedef pair<int, int> pii;

pii work(int y)
{
	clr(l, 0);
	clr(r, 0);
	rep(i, 1, k)
	{
		int len = node[i].r * node[i].r - (node[i].y - y) * (node[i].y - y);
		if (len >= 0)
		{
			len = floor(sqrt(len + .0));
			int ll = max(node[i].x - len, 0);
			int rr = min(node[i].x + len, m + 1);
			l[ll] += node[i].w;
			r[rr] += node[i].w;
		}
	}
	int st = 0, ed = 0, ans = -1, cnt = 0;
	rep(i, 0, m + 1)
	{
		st += l[i];
		if (st - ed > ans)
		{
			ans = st - ed;
			cnt = 1;
		} else if (st - ed == ans)
			++cnt;
		ed += r[i];
	}
	return make_pair(ans, cnt);
}

int main()
{
	scanf("%d%d%d", &m, &n, &k);
	rep(i, 1, k)
		scanf("%d%d%d%d", &node[i].y, &node[i].x, &node[i].r, &node[i].w);
	int ans = -1, cnt = 0;
	rep(i, 1, n)
	{
		pii ret = work(i);
		if (ret.first > ans)
		{
			ans = ret.first;
			cnt = ret.second;
		} else if (ret.first == ans)
			cnt += ret.second;
	}
	printf("%d\n%d\n", ans, cnt);

	fclose(stdin);
	fclose(stdout);
	return 0;
}





