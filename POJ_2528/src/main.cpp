//Created At: Wed Feb 24 18:37:26 CST 2016
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
#define infi 0x7FFFFFFF
#define mm 400010
#define nn 10000000
using namespace std;

bool a[mm];
int n;

struct Node {
	int tag;
	int l, r;
	Node *ch[2];

	void update(int, int, int);
	void push();
}node[mm], *tail, *root;

Node *new_node(int l, int r) {
	tail -> tag = 0;
	tail -> l = l;
	tail -> r = r;
	tail -> ch[0] = tail -> ch[1] = NULL;
	return tail++;
}

void Node::update(int l, int r, int x) {
	if (this -> l >= l && this -> r <= r) {
		this -> tag = x;
	} else {
		int m = (this -> l + this -> r) / 2;
		if (!ch[0]) ch[0] = new_node(this -> l, m);
		if (!ch[1]) ch[1] = new_node(m + 1, this -> r);
		if (l <= m) ch[0] -> update(l, r, x);
		if (r > m) ch[1] -> update(l, r, x);
	}
}

void Node::push() {
	if (!ch[0] && !ch[1]) a[tag] = true;
	rep(i, 0, 1) {
		if (ch[i]) {
			ch[i] -> tag = max(ch[i] -> tag, tag);
			ch[i] -> push();
		}
	}
}

void pre() {
	tail = node;
	root = new_node(1, nn);
	int l, r;
	scanf("%d", &n);
	rep(i, 1, n) {
		scanf("%d%d", &l, &r);
		root -> update(l, r, i);
	}
}

int work() {
	clr(a, 0);
	root -> push();
	int ans = 0;
	rep(i, 1, n) {
		if (a[i]) ++ans;
	}
	return ans;
}

int main() {
	int c;
	scanf("%d", &c);
	rep(i, 1, c) {
		pre();
		printf("%d\n", work());
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
