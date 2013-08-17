/*
 * main.cpp
 *
 *  Created on: 2013-7-18
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
#define mix(a, b) (a)<(b)?(a):(b)
#define infi 0x7FFFFFFF
#define mm 200000
using namespace std;

struct node
{
	int l, s;
	inline friend bool operator <(node a, node b)
	{
		return a.l < b.l;
	}
}s[mm];

int n;

inline int dis(int i, int j)
{
	return s[j].l - s[i].l;
}

void pre()
{
	int m;
	scanf("%d%d", &m, &n);
	rep (i, 1, n)
		scanf("%d%d", &(s[i].l), &(s[i].s));
	sort(s + 1, s + 1 + n);
	s[0].l = 0;
	s[0].s = 1;
	n += 1;
	s[n].l = m;
	s[n].s = infi;
	rep (i, 1, n)
		s[i].s = min(s[i].s, s[i - 1].s + dis(i - 1, i));
	for (int i = n - 1; i >= 0; --i)
		s[i].s = min(s[i].s, s[i + 1].s + dis(i, i + 1));
}

int work()
{
	int ans = 1;
	rep (i, 1, n)
		ans = max(ans, (s[i].s + s[i - 1].s + dis(i - 1, i))/2);
	return ans;
}

int main()
{
	freopen("bobsled.in", "r", stdin);
	freopen("bobsled.out", "w", stdout);

	pre();
	printf("%d\n", work());

	fclose(stdin);
	fclose(stdout);
	return 0;
}

