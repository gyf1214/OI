/*
 * main.cpp
 *
 *  Created on: Jan 28, 2014
 *      Author: gyf
 */

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <assert.h>
#define rep(i, a ,b) for (int i = (a); i <= (b); ++i)
#define clr(i, a) memset(i, a, sizeof(i))
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))
#define infi 0x7FFFFFFF
#define mm 200010
using namespace std;

typedef pair<int, int> pii;

int t[mm];
int n1, n2, a1, a2, d, p;
struct _queue
{
	int l, r;
	pii q[mm];
	void clear()
	{
		l = 0;
		r = 0;
		clr(q, 0);
	}
	_queue()
	{
		clear();
	}
	void push(pii p)
	{
		q[r] = p;
		++r;
		assert(r < mm);
	}
	void push(int t, int d)
	{
		push(make_pair(t, d));
	}
	pii top()
	{
		return q[l];
	}
	void pop()
	{
		++l;
	}
	bool empty()
	{
		return r <= l;
	}
	pii& right()
	{
		return q[r - 1];
	}
	void shift()
	{
		--r;
	}
}qn, qm, qo;

int calc(int x)
{
	qn.clear();
	qm.clear();
	qo.clear();
	int ans = (p - a2) * x;
	qo.push(-infi / 3, x);
	rep(i, 1, d)
	{
		while (!qn.empty() && i - qn.top().first >= n1)
		{
			qm.push(qn.top());
			qn.pop();
		}
		while (!qm.empty() && i - qm.top().first >= n2)
		{
			qo.push(qm.top());
			qm.pop();
		}
		int now = t[i];
		while (now > 0)
		{
			if (!qo.empty())
			{
				if (qo.right().second > now)
				{
					ans += a2 * now;
					qo.right().second -= now;
					break;
				} else {
					ans += a2 * qo.right().second;
					now -= qo.right().second;
					qo.shift();
				}
			} else if (!qm.empty())
			{
				if (qm.right().second > now)
				{
					ans += a1 * now;
					qm.right().second -= now;
					break;
				} else {
					ans += a1 * qm.right().second;
					now -= qm.right().second;
					qm.shift();
				}
			} else {
				return infi;
			}
		}
		qn.push(i, t[i]);
	}
	return ans;
}

int work(int l, int r)
{
	while (r - l > 2)
	{
		int x = l + (r - l) / 3;
		int y = x + (r - l) / 3;
		if (calc(x) < calc(y))
			r = y;
		else
			l = x;
	}
	int b;
	int ans = infi;
	rep(i, l, r)
	{
		int t = calc(i);
		if (t < ans)
		{
			ans = t;
			b = i;
		}
	}
	//printf("%d\n", b);
	return ans;
}

int main()
{
	freopen("toy.in", "r", stdin);
	freopen("toy.out", "w", stdout);

	scanf("%d%d%d%d%d%d", &d, &n1, &n2, &a1, &a2, &p);
	if (n1 > n2)
	{
		int t = n1;
		n1 = n2;
		n2 = t;
		t = a1;
		a1 = a2;
		a2 = t;
	}
	a2 = min(a1, a2);
	int sum = 0;
	rep(i, 1, d)
	{
		scanf("%d", &t[i]);
		sum += t[i];
	}
	printf("%d\n", work(0, sum + 1));

	fclose(stdin);
	fclose(stdout);
	return 0;
}



