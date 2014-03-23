/*
 * main.cpp
 *
 *  Created on: Mar 22, 2014
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
#define nm 300
#define mm 2000
using namespace std;

int rank[nm];
char str[mm][nm];
char* a[mm];
char dic[nm];
struct _node
{
	char* now;
	_node* next;
}node[mm];
_node* head[nm];
int n, m, nh;

void ins(char* ch, char key)
{
	node[nh].now = ch;
	node[nh].next = head[(int)key];
	head[(int)key] = &node[nh];
	++nh;
}

void merge()
{
	int cnt = 0;
	rep(i, 0, nm - 1)
	{
		for (_node* k = head[i]; k; k = k -> next)
		{
			a[cnt] = k -> now;
			++cnt;
		}
	}
}

void sort(int k)
{
	clr(head, 0);
	nh = 0;
	for (int i = n - 1; i >= 0; --i)
		ins(a[i], rank[(int)a[i][k]]);
	merge();
}

int main()
{
	scanf("%s", dic);
	clr(rank, 0);
	rep(i, 0, 25)
		rank[(int)dic[i]] = i + 1;
	scanf("%d", &n);
	m = 0;
	rep(i, 0, n - 1)
	{
		scanf("%s", str[i]);
		a[i] = str[i];
		m = max(m, strlen(str[i]));
	}
	int k;
	scanf("%d", &k);
	if (k == 0)
		rep(i, 0, nm - 1)
			rank[i] = 26 - rank[i];
	for (; m >= 0; --m)
		sort(m);
	rep(i, 0, n - 1)
		printf("%s\n", a[i]);

	fclose(stdin);
	fclose(stdout);
	return 0;
}
