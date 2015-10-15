//Created At: Thu Oct 15 23:13:51 CST 2015
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
#define nm 26
#define mm 150010
using namespace std;

struct Node {
	char ch;
	bool ed;
	Node *fa, *next[nm];

	Node* setc(Node *p, int ch) {
		p -> fa = this;
		p -> ch = ch + 'a';
		next[ch] = p;
		return p;
	}

	void print() {
		if (fa) fa -> print();
		if (fa) putchar(ch);
	}
}node[mm], *tail, *root;

void ins(char *str) {
	Node *p;
	for (p = root; *str; str++) {
		char ch = *str - 'a';
		if (p -> next[ch]) {
			p = p -> next[ch];
		} else {
			p = p -> setc(tail++, ch);
		}
	}
	p -> ed = true;
}

void pre() {
	tail = node;
	root = tail++;
	char str[20];
	for (scanf("%s", str); *str != '#'; scanf("%s", str)) {
		ins(str);
	}
}

bool match(Node *p, char *str, bool c, bool pr) {
	if (p == NULL) return false;
	if (! *str) {
		if (p -> ed) {
			if (pr) {
				putchar(' ');
				p -> print();
			}
			return true;
		} else if (c) {
			bool ans = false;
			rep(i, 0, 25) {
				bool x = match(p -> next[i], str, false, pr);
				ans = ans || x;
			}
			return ans;
		} else return false;
	}
	bool ans = match(p -> next[*str - 'a'], str + 1, c, pr);
	if (c) {
		c = false;
		bool x = match(p, str + 1, c, pr);
		ans = ans || x;
		rep(i, 0, 25) {
			x = match(p -> next[i], str, c, pr);
			ans = ans || x;
			x = match(p -> next[i], str + 1, c, pr);
			ans = ans || x;
		}
	}
	return ans;
}

void work() {
	char str[20], ori[20];
	for (scanf("%s", str); *str != '#'; scanf("%s", str)) {
		strcpy(ori, str);
		if (match(root, str, false, false)) {
			printf("%s is correct\n", ori);
		} else {
			printf("%s:", ori);
			match(root, str, true, true);
			putchar('\n');
		}
	}
}

int main() {
	pre();
	work();

	fclose(stdin);
	fclose(stdout);
	return 0;
}
