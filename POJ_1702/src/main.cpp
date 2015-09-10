//Created At: Thu Sep 10 13:31:32 CST 2015
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
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define clr(i, a) memset(i, (a), sizeof(i))
#define infi 0x7FFFFFFF
#define mm 21
using namespace std;

int ans[mm];
vector<int> l, r;

void work(int m) {
	clr(ans, 0);
	int len = 0;
	for (; m; m = (m + 1) / 3) {
		ans[len++] = (m + 1) % 3 - 1;
	}
	l.clear(), r.clear();
	int p = 1;
	rep(i, 0, len - 1) {
		if (ans[i] == -1) {
			l.push_back(p);
		} else if (ans[i] == 1) {
			r.push_back(p);
		}
		p *= 3;
	}
	if (!l.size()) {
		printf("empty ");
	} else {
		rep(i, 0, l.size() - 1) {
			printf("%d%c", l[i], i == l.size() - 1 ? ' ' : ',');
		}
	}
	if (!r.size()) {
		printf("empty\n");
	} else {
		rep(i, 0, r.size() - 1) {
			printf("%d%c", r[i], i == r.size() - 1 ? '\n' : ',');
		}
	}
}

int main() {
	int t;
	scanf("%d", &t);

	rep(i, 1, t) {
		int x;
		scanf("%d", &x);
		work(x);
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
