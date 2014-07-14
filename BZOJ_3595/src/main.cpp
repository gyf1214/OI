//Created At: Mon Jul 14 16:10:25 CST 2014
//orz zyx
//ntr czr
//Author: gyf

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define clr(i, a) memset(i, (a), sizeof(i))
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))
#define infi 0x7FFFFFFF
#define mm 5000000
using namespace std;

struct Node
{
	int val, tag;
	int l, r;
	Node* ch[2];

	void extend();
	void push();
	void merge();
	void update(int);
	void modify(int, int, int);
	int rank(int);
	int select(int);
}node[mm], *next = node, *root;

int ans;

Node* new_node(int l, int r)
{
	next -> l = l;
	next -> r = r;
	next -> val = next -> tag = 0;
	next -> ch[0] = next -> ch[1] = NULL;
	return next++;
}

void Node::extend()
{
	if (!ch[0] && l != r)
	{
		int m = (l + r) / 2;
		ch[0] = new_node(l, m);
		ch[1] = new_node(m + 1, r);
	}
}

void Node::push()
{
	extend();
	if (tag && ch[0])
	{
		ch[0] -> update(tag);
		ch[1] -> update(tag);
	}
	tag = 0;
}

void Node::update(int x)
{
	val += x * (r - l + 1);
	tag += x;
}

void Node::merge()
{
	extend();
	if (ch[0]) val = ch[0] -> val + ch[1] -> val;
}

void Node::modify(int l, int r, int x)
{
	push();
	if (this -> l >= l && this -> r <= r)
		update(x);
	else {
		int m = (this -> l + this -> r) / 2;
		if (l <= m) ch[0] -> modify(l, r, x);
		if (r >= m + 1) ch[1] -> modify(l, r, x);
		merge();
	}
}

int Node::rank(int k)
{
	push();
	if (l == r) return val;
	int m = (l + r) / 2;
	if (k <= m)
		return ch[0] -> rank(k);
	else
		return ch[0] -> val + ch[1] -> rank(k);
}

int Node::select(int k)
{
	push();
	if (l == r) return l;
	if (k <= ch[0] -> val)
		return ch[0] -> select(k);
	else
		return ch[1] -> select(k - ch[0] -> val);
}

int decode()
{
	int x;
	scanf("%d", &x);
	return x - ans;
}

struct Dmap
{
	map<int, int> m[2];
	int find(int k, int i)
	{
		map<int, int>::iterator iter = m[k].find(i);
		if (iter == m[k].end())
			return i;
		else
			return iter -> second;
	}

	void link(int i, int j)
	{
		m[0].erase(i);
		m[1].erase(j);
		m[0].insert(make_pair(i, j));
		m[1].insert(make_pair(j, i));
	}
}dmap;

void work()
{
	int n, m;
	scanf("%d%d", &n, &m);
	root = new_node(1, n + m + m);
	root -> modify(1 + m, n + m, 1);
	ans = 0;
	int l = 1, r = n;
	rep(i, 1, m)
	{
		int ch, x, y, i;
		scanf("%d", &ch);
		x = decode();
		if (ch == 1)
		{
			y = decode();
			i = dmap.find(0, x);
			ans = root -> rank(i + m);
			dmap.link(y, i);
		} else if (ch == 2) {
			--l;
			i = dmap.find(0, x);
			ans = root -> rank(i + m);
			root -> modify(i + m, i + m, -1);
			root -> modify(l + m, l + m, 1);
			dmap.link(x, l);
		} else if (ch == 3) {
			++r;
			i = dmap.find(0, x);
			ans = root -> rank(i + m);
			root -> modify(i + m, i + m, - 1);
			root -> modify(r + m, r + m, 1);
			dmap.link(x, r);
		} else {
			ans = root -> select(x);
			ans = dmap.find(1, ans - m);
		}
		printf("%d\n", ans);
	}
}

int main()
{
	work();

	fclose(stdin);
	fclose(stdout);
	return 0;
}

