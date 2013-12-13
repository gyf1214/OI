/*
 * main.cpp
 *
 *  Created on: 2013-12-13
 *      Author: gyf
 */

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define clr(i, a) memset(i, a, sizeof(i))
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))
#define infi 0x7FFFFFFF
#define mm 200
using namespace std;

int f[mm][mm], cnt[mm];
int s[mm], b[mm], n, p, root;
bool vis[mm];

void pre()
{
	clr(s, 0);
	clr(b, 0);
	clr(cnt, 0);
	clr(f, 0);
	scanf("%d%d", &n, &p);
	clr(vis, 0);
	rep(i, 1, n - 1)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		if (vis[y])
		{
			int t = x;
			x = y;
			y = t;
		}
		vis[y] = true;
		b[y] = s[x];
		s[x] = y;
	}
	for (root = 1; vis[root]; ++root);
}

void dfs(int u)
{
	if (s[u] != 0)
		dfs(s[u]);
	if (b[u] != 0)
		dfs(b[u]);
	cnt[u] = 1 + cnt[s[u]] + cnt[b[u]];
	rep(i, 0, p)
	{
		f[u][i] = cnt[u] - i;
		if (i - cnt[b[u]] <= 0)
			f[u][i] = min(f[u][i], 1 + f[b[u]][i]);
		rep(j, max(1, i - cnt[b[u]]), min(i, cnt[s[u]] + 1))
			f[u][i] = min(f[u][i], f[s[u]][j - 1] + f[b[u]][i - j]);
	}
}

int main()
{
	freopen("roads.in", "r", stdin);
	freopen("roads.out", "w", stdout);

	pre();
	dfs(root);
	int ans = f[root][p];
	rep(i, 1, n)
		if (cnt[i] - cnt[b[i]] == p)
			ans = min(ans, 1);
	printf("%d\n", ans);

	fclose(stdin);
	fclose(stdout);
	return 0;
}


