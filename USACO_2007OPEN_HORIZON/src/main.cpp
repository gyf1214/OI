/*
 * main.cpp
 *
 *  Created on: 2013-10-26
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
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))
#define infi 0x7FFFFFFF
#define mm 110000
using namespace std;

struct _line
{
	int x;
	int h;
	friend bool operator <(_line a, _line b)
	{
		return a.x < b.x;
	}
}line[mm];
int h[mm], die[mm];
int heap[mm];
int hn, n;

void up(int i)
{
	int j = i / 2;
	if (j > 0 && h[heap[i]] > h[heap[j]])
	{
		int t = heap[i];
		heap[i] = heap[j];
		heap[j] = t;
		up(j);
	}
}

void down(int i)
{
	int j = i * 2;
	if (j + 1 <= hn && h[heap[j + 1]] > h[heap[j]])
		++j;
	if (j <= hn && h[heap[i]] < h[heap[j]])
	{
		int t = heap[i];
		heap[i] = heap[j];
		heap[j] = t;
		down(j);
	}
}

void push(int x)
{
	heap[++hn] = x;
	up(hn);
}

void pop()
{
	heap[1] = heap[hn--];
	down(1);
}

int top()
{
	while (hn > 0 && die[heap[1]])
		pop();
	return hn > 0 ? heap[1] : 0;
}

void pre()
{
	scanf("%d", &n);
	rep(i, 1, n)
	{
		scanf("%d%d%d", &line[i].x, &line[i + n].x, h + i);
		line[i].h = i;
		line[i + n].h = i + n;
	}
	sort(line + 1, line + 1 + n + n);
	clr(heap, 0);
	clr(die, 0);
	hn = 0;
}

long long work()
{
	long long ans = 0;
	long long last = line[1].x;
	push(line[1].h);
	rep(i, 2, 2 * n)
	{
		int t = top();
		long long x = line[i].x;
		if (t > 0)
			ans += (x - last) * (long long)h[t];
		if (line[i].h <= n)
			push(line[i].h);
		else
			die[line[i].h - n] = true;
		last = x;
	}
	return ans;
}

int main()
{
	freopen("horizon.in", "r", stdin);
	freopen("horizon.out", "w", stdout);

	pre();
	printf("%lld\n", work());

	fclose(stdin);
	fclose(stdout);
	return 0;
}
