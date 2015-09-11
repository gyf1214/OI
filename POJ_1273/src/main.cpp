//Created At: Thu Sep 10 13:49:08 CST 2015
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
#define mm 1010
using namespace std;

struct Edge {
	int u, v, f;
	Edge *next, *rev;
}edge[mm], *tail = edge, *head[mm], *cur[mm];

int d[mm], q[mm], n, delta;

bool bfs() {
	clr(d, 0);
	d[1] = 1;
	int l = 0, r = 0;
	q[r++] = 1;
	while (l != r) {
		int u = q[l++];
		for (Edge* e = head[u]; e; e = e -> next) {
			int v = e -> v;
			if (!d[v] && e -> f > 0) {
				d[v] = d[u] + 1;
				q[r++] = v;
			}
		}
	}
	return d[n] > 0;
}

bool dfs(int u, int x) {
	if (u == n) {
		delta = x;
		return true;
	}
	for (Edge* e = cur[u]; e; e = e -> next) {
		int v = e -> v;
		if (d[v] == d[u] + 1 && e -> f > 0) {
			if (dfs(v, min(x, e -> f))) {
				e -> f -= delta;
				e -> rev -> f += delta;
				cur[u] = e;
				return true;
			}
		}
	}
	return false;
}

int dinic() {
	int ans = 0;
	while (bfs()) {
		memcpy(cur, head, sizeof(head));
		while (dfs(1, infi)) {
			ans += delta;
		}
	}
	return ans;
}

Edge* _ins(int u, int v, int f) {
	tail -> u = u;
	tail -> v = v;
	tail -> f = f;
	tail -> next = head[u];
	head[u] = tail;
	return tail++;
}

void ins(int u, int v, int c) {
	Edge* x = _ins(u, v, c);
	x -> rev = _ins(v, u, 0);
	x -> rev -> rev = x;
}

bool pre() {
	int m;
	clr(head, 0);
	tail = edge;
	if (scanf("%d%d", &m, &n) == EOF) {
		return false;
	}
	rep(i, 1, m) {
		int x, y, c;
		scanf("%d%d%d", &x, &y, &c);
		ins(x, y, c);
		//ins(y, x, c);
	}
	return true;
}

int main() {
	while (pre()) {
		printf("%d\n", dinic());
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
