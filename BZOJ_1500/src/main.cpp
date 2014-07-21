//Created At: Mon Jul 21 13:42:11 CST 2014
//orz zyx
//ntr czr
//Author: gyf

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
#define infi 0x7FFFFFF
#define mm 500010
using namespace std;

struct Node
{
	int val, sum, size;
	int b, lb, rb;
	int tag;
	bool rev;
	Node* ch[2];

	void push();
	void update(int);
	void merge();
	void swap();
	int which(int&);
}node[mm], *garbage[mm], *next = node, Tnull, *null = &Tnull;

int top;
int a[mm];

Node* new_node(int v)
{
	Node* ret;
	if (top > 0)
		ret = garbage[--top];
	else
		ret = next++;
	ret -> val = ret -> sum = v;
	ret -> size = 1;
	ret -> b = ret -> lb = ret -> rb = v;
	ret -> tag = -2000;
	ret -> ch[0] = ret -> ch[1] = null;
	ret -> rev = false;
	return ret;
}

void gc(Node* x)
{
	if (x != null)
	{
		garbage[top++] = x;
		gc(x -> ch[0]);
		gc(x -> ch[1]);
	}
}

void Node::update(int x)
{
	if (this == null) return;
	sum = size * x;
	tag = val = x;
	lb = rb = b = max(val, sum);
}

void Node::swap()
{
	if (this == null) return;
	std::swap(ch[0], ch[1]);
	std::swap(lb, rb);
	rev ^= 1;
}

void Node::push()
{
	if (this == null) return;
	if (tag != -2000)
	{
		ch[0] -> update(tag);
		ch[1] -> update(tag);
		tag = -2000;
	}
	if (rev)
	{
		ch[0] -> swap();
		ch[1] -> swap();
		rev = false;
	}
}

void Node::merge()
{
	if (this == null) return;
	size = ch[0] -> size + ch[1] -> size + 1;
	sum = ch[0] -> sum + ch[1] -> sum + val;
	lb = max(ch[0] -> lb, ch[0] -> sum + val + max(ch[1] -> lb, 0));
	rb = max(ch[1] -> rb, ch[1] -> sum + val + max(ch[0] -> rb, 0));
	b = max(max(ch[0] -> b, ch[1] -> b), val + max(ch[0] -> rb, 0) + max(ch[1] -> lb, 0));
}

int Node::which(int& k)
{
	int ret = 0;
	if (ch[0] -> size <= k)
	{
		k -= ch[0] -> size + 1;
		ret = 1;
	}
	return ret;
}

Node* rot(Node* x, int k)
{
	Node* y = x -> ch[k];
	x -> ch[k] = y -> ch[1 ^ k];
	y -> ch[1 ^ k] = x;
	x -> merge();
	y -> merge();
	return y;
}

Node* splay(Node* x, int k)
{
	x -> push();
	int t1 = x -> which(k);
	if (k < 0) return x;
	Node* y = x -> ch[t1];
	int t2 = y -> which(k);
	y -> push();
	if (k < 0)
	{
		x = rot(x, t1);
		return x;
	}
	y -> ch[t2] = splay(y -> ch[t2], k);
	if (t1 ^ t2)
	{
		x -> ch[t1] = rot(y, t2);
		x = rot(x, t1);
	} else {
		x = rot(x, t1);
		x = rot(x, t1);
	}
	return x;
}

Node* query(Node*& x, int l, int r)
{
	x = splay(x, r + 1);
	x -> ch[0] = splay(x -> ch[0], l - 1);
	return x -> ch[0] -> ch[1];
}

Node* build(int* a, int l, int r)
{
	int m = (l + r) / 2;
	Node* ret = new_node(a[m]);
	if (l < m) ret -> ch[0] = build(a, l, m - 1);
	if (m < r) ret -> ch[1] = build(a, m + 1, r);
	ret -> merge();
	return ret;
}

Node* ins(Node* x, int k, int n, int* a)
{
	Node* y = build(a, 1, n);
	x = splay(x, k);
	x -> ch[1] = splay(x -> ch[1], 0);
	x -> ch[1] -> ch[0] = y;
	x -> ch[1] -> merge();
	x -> merge();
	return x;
}

void work()
{
	null -> b = null -> lb = null -> rb = -infi;
	null -> ch[0] = null -> ch[1] = null;
	char buffer[20];
	int x, y, z;
	int n, m;
	scanf("%d%d", &n, &m);
	rep(i, 1, n)
		scanf("%d", &a[i]);
	a[0] = a[n + 1] = 0;
	Node* root = build(a, 0, n + 1);
	rep(i, 1, m)
	{
		scanf("%s", buffer);
		if (buffer[2] != 'X')
			scanf("%d%d", &x, &y);
		else
			x = 1, y = root -> size - 2;
		if (buffer[0] == 'I')
		{
			rep(j, 1, y)
				scanf("%d", &a[j]);
			root = ins(root, x, y, a);
		} else {
			Node* inter = query(root, x, x + y - 1);
			root -> push();
			root -> ch[0] -> push();
			if (buffer[0] == 'D')
			{
				root -> ch[0] -> ch[1] = null;
				gc(inter);
			} else if (buffer[2] == 'K')
			{
				scanf("%d", &z);
				inter -> update(z);
			} else if (buffer[0] == 'R')
			{
				inter -> swap();
			} else if (buffer[0] == 'G')
			{
				printf("%d\n", inter -> sum);
			} else {
				printf("%d\n", inter -> b);
			}
			root -> ch[0] -> merge();
			root -> merge();
		}
	}
}

int main()
{
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);

	work();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

