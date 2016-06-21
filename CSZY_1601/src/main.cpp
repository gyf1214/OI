//Created At: Mon Jun 20 19:53:44 CST 2016
//orz zyx
//ntr czr
//Author: gyf

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i, a, b) for (int _a = (a), _b = (b), i = _a; i <= _b; ++i)
#define clr(i, a) memset(i, (a), sizeof(i))
#define infi 0x7FFFFFFF
#define nm 30
#define mm 5000010
#define km 2510
#define tm 1110
using namespace std;

struct Node {
	Node *ch[nm];
	Node *fail;
	int end, key;

	void init() {
		clr(ch, 0);
		fail = NULL;
		end = key = 0;
	}
}node[mm], *root, *tail, *null;

Node *q[mm];

char str[mm], pat[km][tm];
bool vis[km];
int n;

char getNumber(int &ret) {
	ret = 0;
	char ch;
	for (ch = getchar(); ch >= '0' && ch <= '9'; ch = getchar()) {
		ret = ret * 10 + ch - '0';
	}
	return ch;
}

void getString(char *x) {
	for (char ch = getchar(); ch != '\n' && ch != -1 ; ch = getchar()) {
		if (ch == '[') {
			int y;
			ch = getNumber(y);
			rep(i, 1, y) *x++ = ch;
			getchar();
		} else {
			*x++ = ch;
		}
	}
	*x = 0;
}

Node *new_node() {
	Node *ret = tail++;
	ret -> init();
	return ret;
}

void ins(char *s, int end) {
	Node *p = root;
	for (; *s; ++s) {
		int k = *s - 'A';
		if (!p -> ch[k]) p -> ch[k] = new_node();
		p = p -> ch[k];
	}
	p -> end = end;
	p -> key = 1;
}

void bfs() {
	int l = 0, r = 1;
	q[l] = root;
	root -> fail = null;
	rep(i, 0, nm - 1) null -> ch[i] = root;
	while (l < r) {
		Node *p = q[l++];
		rep(i, 0, nm - 1) if (p -> ch[i]) {
			q[r++] = p -> ch[i];
			Node *q = p -> fail;
			while (!q -> ch[i]) q = q -> fail;
			p -> ch[i] -> fail = q -> ch[i];
		}
	}
}

void del(char *s) {
	Node *p = root;
	for (; *s; ++s) {
		int k = *s - 'A';
		while (!p -> ch[k]) p = p -> fail;
		p = p -> ch[k];
		for (Node *q = p; q != null && q -> key != -3; q = q -> fail) {
			if (abs(q -> key) == 1 && vis[q -> end]) {
				vis[q -> end] = false;
			}
			q -> key = -3;
		}
	}
}

void match(char *s) {
	Node *p = root;
	for (; *s; ++s) {
		int k = *s - 'A';
		while (!p -> ch[k]) p = p -> fail;
		p = p -> ch[k];
		for (Node *q = p; q != null && q -> key >= 0; q = q -> fail) {
			if (q -> key == 1) {
				vis[q -> end] = true;
				q -> key = -1;
			} else q -> key = -2;
		}
	}
}

int match2(char *s) {
	int ans = 0;
	Node *p = root;
	for (; *s; ++s) {
		int k = *s - 'A';
		while (!p -> ch[k]) p = p -> fail;
		p = p -> ch[k];
		for (Node *q = p; q != null && q -> key != -4; q = q -> fail) {
			if (abs(q -> key) == 1) ++ans;
			q -> key = -4;
		}
	}
	return ans;
}

void pre() {
	tail = node;
	null = new_node();
	root = new_node();
	getNumber(n);
	rep(i, 1, n) {
		getString(pat[i]);
		ins(pat[i], i);
	}
	bfs();
	clr(vis, 0);
}

int work() {
	getString(str);
	match(str);
	rep(i, 1, n) if (vis[i]) {
		del(pat[i]);
		ins(pat[i], i);
	}
	return match2(str);
}

int main() {
	int t;
	getNumber(t);
	rep(i, 1, t) {
		pre();
		printf("%d\n", work());
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
