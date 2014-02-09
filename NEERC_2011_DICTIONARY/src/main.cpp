/*
 * main.cpp
 *
 *  Created on: Feb 9, 2014
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
#define mm 400010
#define nm 30
using namespace std;

struct _node
{
	int next[nm];
}node1[mm], node2[mm];
int nn1, nn2, n, cnt1[nm], cnt2[nm];
bool one[nm];

void ins(char* str)
{
	if (!str[1])
		one[str[0] - 'a'] = true;
	int now = 1;
	char* ch;
	for (ch = str; *ch; ++ch)
	{
		int i = *ch - 'a';
		if (!node1[now].next[i])
		{
			++nn1;
			node1[now].next[i] = nn1;
			if (now != 1)
				++cnt1[i];
		}
		now = node1[now].next[i];
	}
	now = 1;
	for (--ch; ch >= str; --ch)
	{
		int i = *ch - 'a';
		if (!node2[now].next[i])
		{
			++nn2;
			node2[now].next[i] = nn2;
			if (now != 1)
				++cnt2[i];
		}
		now = node2[now].next[i];
	}
}

bool pre()
{
	if (scanf("%d", &n) == EOF)
		return false;
	char str[50];
	nn1 = 1;
	nn2 = 1;
	clr(node1, 0);
	clr(node2, 0);
	clr(cnt1, 0);
	clr(cnt2, 0);
	clr(one, 0);
	rep(i, 1, n)
	{
		scanf("%s", str);
		ins(str);
	}
	return true;
}

long long work()
{
	long long ans = ((long long)nn1 - 1) * ((long long)nn2 - 1);
	rep(i, 0, nm - 1)
	{
		if (one[i])
			++ans;
		ans -= ((long long) cnt1[i]) * ((long long) cnt2[i]);
	}
	return ans;
}

int main()
{
	//freopen("dictionary.in", "r", stdin);
	//freopen("dictionary.out", "w", stdout);

	pre();
	printf("%lld\n", work());

	fclose(stdin);
	fclose(stdout);
	return 0;
}


