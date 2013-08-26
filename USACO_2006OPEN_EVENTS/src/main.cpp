/*
 * main.cpp
 *
 *  Created on: 2013-8-26
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
#define mm 40010
#define lb(x) ((x) & (-(x)))
using namespace std;

struct _inter
{
	int val, num;
	bool st;
	friend bool operator <(_inter a, _inter b)
	{
		return (a.val == b.val && a.st < b.st) || (a.val < b.val);
	}
}inter[mm];

struct _event
{
	int st, ed;
	int ans;
	_event()
	{
		st = 0;
		ed = 0;
		ans = 0;
	}
	friend bool operator < (_event a, _event b)
	{
		return a.st < b.st;
	}
}event[mm];

int s[mm], n;

void set(int i, int x)
{
	for (; i < mm; i += lb(i))
		s[i] = max(s[i], x);
}

int query(int i)
{
	int ans = 0;
	for (; i > 0; i -= lb(i))
		ans = max(ans, s[i]);
	return ans;
}

void pre()
{
	scanf("%d", &n);
	clr(s, 0);
	rep(i, 1, n)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		inter[i].val = x;
		inter[i].num = i;
		inter[i].st = true;
		inter[i + n].val = x + y;
		inter[i + n].num = i;
		inter[i + n].st = false;
	}
	sort(inter + 1, inter + n + n + 1);
	rep(i, 1, n + n)
		if (inter[i].st)
			event[inter[i].num].st = i;
		else
			event[inter[i].num].ed = i;
	sort(event + 1, event + 1 + n);
}

int work()
{
	rep(i, 1, n)
	{
		event[i].ans = query(event[i].st) + 1;
		set(event[i].ed, event[i].ans);
	}
	int ans = 0;
	rep(i, 1, n)
		ans = max(ans, event[i].ans);
	return ans;
}

int main()
{
	freopen("events.in", "r", stdin);
	freopen("events.out", "w", stdout);

	pre();
	printf("%d\n", work());

	fclose(stdin);
	fclose(stdout);
	return 0;
}
