//Created At: Sun Jun 12 13:28:48 CST 2016
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
#define mm 10010
using namespace std;

int sg[mm];
int s[mm], n;
int vis[mm];

void calc() {
	clr(sg, 0);
	clr(vis, 0);
	rep(i, 1, mm - 1) {
		rep(j, 1, n) if (i >= s[j]) vis[sg[i - s[j]]] = i;
		sg[i] = 0;
		while (vis[sg[i]] == i) ++sg[i];
	}
}

bool pre() {
	scanf("%d", &n);
	if (!n) return false;
	rep(i, 1, n) scanf("%d", s + i);
	calc();
	return true;
}

void work() {
	int m;
	scanf("%d", &m);
	rep(i, 1, m) {
		int k;
		scanf("%d", &k);
		int ans = 0;
		rep(i, 1, k) {
			int x;
			scanf("%d", &x);
			ans = ans ^ sg[x];
		}
		printf("%c%s", ans ? 'W' : 'L', i == m ? "\n" : "");
	}
}

int main() {
	while (pre()) work();

	fclose(stdin);
	fclose(stdout);
	return 0;
}
