/*
 * main.cpp
 *
 *  Created on: 2013-11-30
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
#define nm 40
using namespace std;

typedef pair<int, int> pii;

struct _queue
{
	pii q[nm * nm];
	int l, r;
	_queue()
	{
		l = r = 0;
	}
	inline bool empty()
	{
		return l >= r;
	}
	inline void push(int x, int y)
	{
		q[r] = make_pair(x, y);
		++r;
	}
	inline void pop(int& x, int& y)
	{
		x = q[l].first;
		y = q[l].second;
		++l;
	}
}q1, q2;
struct _state
{
	int dis1, dis2;
	long long cnt;
	int map;
	bool vis;
}state[nm][nm];
int n, m;

int dx[8] = {2, -2, 2, -2, 1, -1, 1, -1};
int dy[8] = {1, 1, -1, -1, 2, 2, -2, -2};

inline bool in(int x, int y)
{
	return x >= 1 && x <= n && y >= 1 && y <= m &&
			state[x][y].map != 2;
}

void work(int sx, int sy)
{
	_queue* q = &q1;
	_queue* nq = &q2;
	q->push(sx, sy);
	state[sx][sy].vis = true;
	state[sx][sy].dis1 = state[sx][sy].dis2 = 0;
	state[sx][sy].cnt = 1;
	do
	{
		while (!q->empty())
		{
			int cx, cy;
			q->pop(cx, cy);
			int dis1 = state[cx][cy].dis1;
			int dis2 = state[cx][cy].dis2;
			long long cnt = state[cx][cy].cnt;
			rep(i, 0, 7)
			{
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				if (in(nx, ny))
				{
					if (state[nx][ny].vis)
					{
						int t;
						if (state[nx][ny].map == 1)
							t = dis1;
						else t = dis1 + 1;
						if (state[nx][ny].dis1 == t && state[nx][ny].dis2 == dis2 + 1)
							state[nx][ny].cnt += cnt;
						continue;
					}
					state[nx][ny].dis2 = dis2 + 1;
					state[nx][ny].cnt += cnt;
					state[nx][ny].vis = true;
					if (state[nx][ny].map == 1)
					{
						state[nx][ny].dis1 = dis1;
						q->push(nx, ny);
					} else {
						state[nx][ny].dis1 = dis1 + 1;
						nq->push(nx, ny);
					}
				}
			}
		}
		_queue* t = q;
		q = nq;
		nq = t;
	} while (!q->empty());
}


int main()
{
	freopen("silvlily.in", "r", stdin);
	freopen("silvlily.out", "w", stdout);

	scanf("%d%d", &n, &m);
	int sx, sy, ex, ey;
	clr(state, 0);
	rep(i, 1, n)
		rep(j, 1, m)
		{
			scanf("%d", &state[i][j].map);
			if (state[i][j].map == 3)
			{
				sx = i;
				sy = j;
				state[i][j].map = 1;
			}
			if (state[i][j].map == 4)
			{
				ex = i;
				ey = j;
				state[i][j].map = 1;
			}
		}
	work(sx, sy);
	if (!state[ex][ey].vis)
	{
		printf("%d\n", -1);
	} else {
		printf("%d\n", state[ex][ey].dis1);
		printf("%d\n", state[ex][ey].dis2);
		printf("%lld\n", state[ex][ey].cnt);
	}
}
