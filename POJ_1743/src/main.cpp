/*
 * main.cpp
 *
 *  Created on: Mar 24, 2014
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
#define mm 200010
using namespace std;

int a[mm], rank[mm], sa[mm], cnt[mm], tmp[mm];
int lcp[mm];
int n;

void sorting(int k)
{
	int t;
	if (k != 0)
	{
		t = n;
		clr(cnt, 0);
		rep(i, 1, n)
			++cnt[rank[i + k]];
		rep(i, 1, n)
			cnt[i] += cnt[i - 1];
		rep(i, 1, n)
			tmp[cnt[rank[i + k]]--] = i;
	} else {
		t = 200;
		rep(i, 1, n)
			tmp[i] = i;
	}
	clr(cnt, 0);
	rep(i, 1, n)
		++cnt[rank[i]];
	rep(i, 1, t)
		cnt[i] += cnt[i - 1];
	for (int i = n; i >= 1; --i)
		sa[cnt[rank[tmp[i]]]--] = tmp[i];
	clr(tmp, 0);
	rep(i, 2, n)
		if (rank[sa[i]] == rank[sa[i - 1]] && rank[sa[i] + k] == rank[sa[i - 1] + k])
			tmp[sa[i]] = tmp[sa[i - 1]];
		else
			tmp[sa[i]] = tmp[sa[i - 1]] + 1;
	rep(i, 1, n)
		rank[i] = tmp[i];
}

void calc_sa()
{
	rep(i, 1, n)
		rank[i] = a[i];
	sorting(0);
	for (int i = 1; i <= n; i *= 2)
		sorting(i);
}

void calc_lcp()
{
	rep(i, 1, n)
		rank[sa[i]] = i;
	int h = 0;
	clr(lcp, 0);
	rep(i, 1, n)
	{
		int j = sa[rank[i] - 1];
		if (h > 0)
			--h;
		for (; j + h < n && i + h < n; ++h)
			if (a[j + h] != a[i + h])
				break;
		lcp[rank[i] - 1] = h;
	}
}

bool check(int k)
{
	int now = 1;
	while (now < n)
	{
		int max_sa = 0, min_sa = infi;
		for (; lcp[now] >= k; ++now)
		{
			max_sa = max(max_sa, sa[now]);
			min_sa = min(min_sa, sa[now]);
		}
		max_sa = max(max_sa, sa[now]);
		min_sa = min(min_sa, sa[now]);
		if (max_sa - min_sa >= k)
			return true;
		++now;
	}
	return false;
}

bool solve()
{
	clr(a, 0);
	scanf("%d", &n);
	if (n == 0)
		return false;
	int y;
	scanf("%d", &y);
	rep(i, 2, n)
	{
		int x;
		scanf("%d", &x);
		a[i - 1] = x - y + 89;
		y = x;
	}
	calc_sa();
	calc_lcp();
	int l = 0;
	int r = n + 1;
	while (r - l > 1)
	{
		int m = (l + r) / 2;
		if (check(m))
			l = m;
		else
			r = m;
	}
	printf("%d\n", l < 4 ? 0 : (l + 1));
	return true;
}

int main()
{
	while(solve());

	fclose(stdin);
	fclose(stdout);
	return 0;
}
