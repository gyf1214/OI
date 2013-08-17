/*
 * main.cpp
 *
 *  Created on: 2013-7-17
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
#define lb(x) ((x)&(-(x)))
#define infi 0x7FFFFFFF
#define nn 200
#define mm 2000
#define full 16384
using namespace std;

int head[mm], next[mm], tail[mm], weight[mm], food[mm];
bool vis[nn][full];
int n, m, k, ne;

struct state
{
	int now, f;
	int count()
	{
		int ret = 0;
		for (int i = f; i > 0; i -= lb(i))
			++ret;
		return ret;
	}
	inline void eat(int i)
	{
		f = (f | (1 << (i - 1)));
	}
	inline bool visit()
	{
		return vis[now][f];
	}
	inline void setv()
	{
		vis[now][f] = true;
	}
};

struct _queue
{
	static const int round = nn * full;
	state q[nn * full];
	int l, r;
	inline state top()
	{
		return q[l];
	}
	inline bool empty()
	{
		return l == r;
	}
	inline void push(state s)
	{
		q[r] = s;
		r = (r + 1) % round;
	}
	inline void pop()
	{
		l = (l + 1) % round;
	}
}queue;

inline void push(state v)
{
	if (!v.visit())
	{
		queue.push(v);
		v.setv();
	}
}

inline void ins(int i, int j, int w)
{
	next[++ne] = head[i];
	head[i] = ne;
	tail[ne] = j;
	weight[ne] = w;
	next[++ne] = head[j];
	head[j] = ne;
	tail[ne] = i;
	weight[ne] = w;
}

int work()
{
	int ans = 0;
	clr(&queue, 0);
	clr(vis, 0);
	state start = {1, 0};
	queue.push(start);
	vis[1][0] = true;
	while (!queue.empty())
	{
		state s = queue.top();
		if (s.now == 1)
			ans = max(ans, s.count());
		for (int e = head[s.now]; e != 0; e = next[e])
		{
			if (s.count() > weight[e])
				continue;
			state v = {tail[e], s.f};
			push(v);
			if (food[tail[e]] > 0)
			{
				v.eat(food[tail[e]]);
				push(v);
			}
		}
		queue.pop();
	}
	return ans;
}

int main()
{
	freopen("cavecow1.in", "r", stdin);
	freopen("cavecow1.out", "w", stdout);

	clr(head, 0);
	clr(next, 0);
	clr(tail, 0);
	clr(weight, 0);
	clr(food, 0);
	scanf("%d%d%d", &n, &m, &k);
	rep(i, 1, k)
	{
		int x;
		scanf("%d", &x);
		food[x] = i;
	}
	ne = 0;
	rep(i, 1, m)
	{
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		ins(x, y, w);
	}
	printf("%d\n", work());

	fclose(stdin);
	fclose(stdout);
	return 0;
}
