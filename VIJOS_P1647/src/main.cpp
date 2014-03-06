/*
 * main.cpp
 *
 *  Created on: Mar 6, 2014
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
#define lb(x) ((x) & (-(x)))
#define nm 100010
#define mm 1000010
using namespace std;

int s[mm];
int cnt[mm];
int p[nm];
int price;

void ins(int i)
{
	for (; i < mm; i += lb(i))
		++s[i];
}

int search(int k)
{
	--k;
	int gap = 524288, c = 0;
	while (gap)
	{
		if (gap + c < mm && s[gap + c] <= k)
		{
			k -= s[gap + c];
			c += gap;
		}
		gap /= 2;
	}
	return c + 1;
}

int main()
{
	scanf("%d", &price);
	int c;
	scanf("%d", &c);
	int k = 0;
	clr(s, 0);
	clr(cnt, 0);
	clr(p, 0);
	while (c != 0)
	{
		int x;
		scanf("%d", &x);
		if (c == 1)
		{
			++k;
			ins(x);
			++cnt[x];
			p[k] = x;
		} else if (c == 2)
		{
			--cnt[p[x]];
		} else {
			int t = search(k - x + 1);
			if (t > price)
			{
				printf("Dui bu qi,Mei you.\n");
			} else if (cnt[t] <= 0)
			{
				printf("Mei you. Zhe ge ke yi you. Zhe ge zhen mei you!\n");
			} else {
				printf("You. %d Yuan.\n", t);
			}
		}
		scanf("%d", &c);
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
