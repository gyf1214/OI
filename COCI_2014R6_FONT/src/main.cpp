/*
 * main.cpp
 *
 *  Created on: Mar 26, 2014
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
#define mm 30
#define nm 26
using namespace std;

int n;
int a[mm], ans, s;
char str[200];

void dfs(int k)
{
	if (s == ((1 << nm) - 1))
	{
		ans += (1 << (n - k + 1));
		return;
	}
	if (k == n + 1)
		return;
	dfs(k + 1);
	int t = s;
	s = (s | a[k]);
	dfs(k + 1);
	s = t;
}

int main()
{
	freopen("font.in", "r", stdin);
	freopen("font.out", "w", stdout);

	scanf("%d", &n);
	s = 0;
	clr(a, 0);
	rep(i, 1, n)
	{
		scanf("%s", str);
		for (char* ch = str; *ch; ++ch)
			a[i] = (a[i] | (1 << (*ch - 'a')));
	}

	dfs(1);
	printf("%d\n", ans);

	fclose(stdin);
	fclose(stdout);
	return 0;
}

