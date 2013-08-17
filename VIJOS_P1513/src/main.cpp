/*
 * main.cpp
 *
 *  Created on: 2013-8-17
 *      Author: gyf
 */

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#define rep(i, a, b)  for (int i = a; i <= b; ++i)
#define clr(i, a) memset(i, a, sizeof(i))
#define max(a, b) (a)>(b)?(a):(b)
#define min(a, b) (a)<(b)?(a):(b)
#define infi 0x7FFFFFFF
#define mm 50010
using namespace std;

struct _node
{
	int len, ed;
	friend bool operator <(_node a, _node b)
	{
		return a.ed < b.ed;
	}
}node[mm];

int s[mm];
int n;

void pre()
{
	scanf("%d", &n);
	rep(i, 1, n)
		scanf("%d%d", &node[i].ed, &node[i].len);
	sort(node + 1, node + n + 1);
}

int work()
{
	int ans = 0;
	int now = infi;
	priority_queue<int> q;
	for (int i = n; i > 0; --i)
	{
		while (!q.empty() && now > node[i].ed)
		{
			now += q.top();
			q.pop();
			++ans;
		}
		if (now > node[i].ed)
			now = node[i].ed;
		q.push(-node[i].len);
	}
	while (!q.empty() && now - q.top() >= 0)
	{
		++ans;
		now -= q.top();
		q.pop();
	}
	return ans;
}

int main()
{
	pre();
	printf("%d\n", work());

	fclose(stdin);
	fclose(stdout);
	return 0;
}
