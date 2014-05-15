/*
 * main.cpp
 *
 *  Created on: May 16, 2014
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
#define mm 21000
#define nm 500
using namespace std;

char str[mm];
int rank[mm], sa[mm], sum[mm], temp[mm], height[mm];
int n, m;


void sorting(int j)
{
	clr(sum, 0);
	clr(temp, 0);
	rep(i, 1, n)
		++sum[rank[i + j]];
	rep(i, 1, n)
		sum[i] += sum[i - 1];
	for (int i = n; i > 0; --i)
		temp[sum[rank[i + j]]--] = i;
	clr(sum, 0);
	rep(i, 1, n)
		++sum[rank[i]];
	rep(i, 1, n)
		sum[i] += sum[i - 1];
	for (int i = n; i > 0; --i)
		sa[sum[rank[temp[i]]]--] = temp[i];
	temp[sa[1]] = 1;
	int p = 1;
	rep(i, 2, n)
	{
		if ((rank[sa[i]] != rank[sa[i - 1]]) ||
				(rank[sa[i] + j] != rank[sa[i - 1] + j]))
			++p;
		temp[sa[i]] = p;
	}
	rep(i, 1, n)
		rank[i] = temp[i];
}

void calc_sa()
{
	clr(sum, 0);
	rep(i, 1, n)
		temp[i] = str[i - 1];
	rep(i, 1, n)
		++sum[temp[i]];
	rep(i, 1, nm)
		sum[i] += sum[i - 1];
	for (int i = n; i > 0; --i)
		sa[sum[temp[i]]--] = i;
	rank[sa[1]] = 1;
	int p = 1;
	rep(i, 2, n)
	{
		if (temp[sa[i]] != temp[sa[i - 1]])
			++p;
		rank[sa[i]] = p;
	}
	for (int j = 1; j <= n; j *= 2)
		sorting(j);
}

void calc_height()
{
	int h = 0;
	rep(i, 1, n)
	{
		if (rank[i] < 1)
			continue;
		int j = sa[rank[i] - 1];
		--h;
		for (; i + h <= n && j + h <= n; ++h)
			if (str[i + h] != str[j + h])
				break;
		height[rank[i]] = h + 1;
		if (h < 0)
			h = 0;
	}
	height[1] = 0;
}

int main()
{
	scanf("%s", str);
	n = strlen(str);
	str[n] = '#';
	scanf("%s", str + n + 1);
	m = strlen(str + n + 1);
	n += m + 2;
	m = n - m - 2;
	calc_sa();
	calc_height();
	int ans = infi;
	rep(i, 2, n)
		if ((sa[i] > m) ^ (sa[i - 1] > m))
			if (height[i] > height[i - 1] && height[i] > height[i + 1])
				ans = min(ans, max(height[i - 1] + 1, height[i + 1] + 1));
	printf("%d\n", ans == infi ? -1 : ans);

	fclose(stdin);
	fclose(stdout);
}

