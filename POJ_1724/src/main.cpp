//Created At: Fri Sep 11 18:33:24 CST 2015
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
#define mm 150
using namespace std;

struct Edge {
	int u, v, l, t;
	Edge *next;
}edge[mm * mm], *tail = edge, *head[mm];
bool vis[mm];
int now, k, n, ans;

Edge* ins(int u, int v, int l, int t) {
	tail -> u = u;
	tail -> v = v;
	tail -> l = l;
	tail -> t = t;
	tail -> next = head[u];
	head[u] = tail;
	return tail++;
}

void dfs(int u) {
	if (u == n) {
		ans = now;
		return;
	}
	for (Edge* e = head[u]; e;e = e -> next) {
		if (!vis[e -> v] && k >= e -> t && now + e -> l < ans) {
			vis[e -> v] = true;
			now += e -> l;
			k -= e -> t;
			dfs(e -> v);
			now -= e -> l;
			k += e -> t;
			vis[e -> v] = false;
		}
	}
}

void pre() {
	int m;
	scanf("%d%d%d", &k, &n, &m);
	rep(i, 1, m) {
		int x, y, l, t;
		scanf("%d%d", &x, &y);
		scanf("%d%d", &l, &t);
		ins(x, y, l, t);
	}
}

int main() {
	pre();
	now = 0;
	ans = infi;
	dfs(1);
	printf("%d\n", ans == infi ? -1 : ans);

	fclose(stdin);
	fclose(stdout);
	return 0;
}
