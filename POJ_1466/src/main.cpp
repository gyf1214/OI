//Created At: Wed Sep 9 22:57:41 CST 2015
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
#define mm 1000
using namespace std;

vector<int> edge[mm];
int match[mm], n;
bool vis[mm], boy[mm];
int q[mm];

bool find(int x) {
	rep(i, 0, edge[x].size() - 1) {
		int y = edge[x][i];
		if (!vis[y]) {
			vis[y] = true;
			if (!match[y] || find(match[y])) {
				match[y] = x;
				return true;
			}
		}
	}
	return false;
}

int hungary() {
	int ans = 0;
	clr(match, 0);
	rep(i, 1, n) {
		if (boy[i]) {
			clr(vis, 0);
			if (find(i)) {
				++ans;
			}
		}
	}
	return ans;
}

void bfs(int st) {
	clr(vis, 0);
	clr(boy, 0);
	int l = 0, r = 1;
	q[l] = st;
	while (l < r) {
		int u = q[l++];
		rep(i, 0, edge[u].size() - 1) {
			int v = edge[u][i];
			if (!vis[v]) {
				boy[v] = !boy[u];
				vis[v] = true;
				q[r++] = v;
			}
		}
	}
}

int getint() {
	char ch = getchar();
	if (ch == -1) {
		return -1;
	}
	int ans = 0;
	while (ch < '0' || ch > '9') {
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		ans = ans * 10 + ch - '0';
		ch = getchar();
	}
	return ans;
}

bool pre() {
	if ((n = getint()) == -1) {
		return false;
	}
	rep(i, 1, n) {
		int sth, k;
		getint();
		k = getint();
		edge[i].clear();
		rep(j, 1, k) {
			edge[i].push_back(getint() + 1);
		}
	}
	bfs(1);
	return true;
}

int main() {
	while (pre()) {
		printf("%d\n", n - hungary());
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
