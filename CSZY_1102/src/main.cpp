//Created At: Mon May 23 13:54:52 CST 2016
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
#define mm 20010
using namespace std;

struct Edge {
	int u, v, w;
	Edge *next;

	Edge() {}
	Edge(int u, int v, int w, Edge *n) : u(u), v(v), w(w), next(n) {}
}edge[mm], *tail, *head[mm];

int n, k, root, best, ans;
int size[mm], maxSize[mm];
bool vis[mm];
vector<int> dis;

void ins(int u, int v, int w) {
	*tail = Edge(u, v, w, head[u]);
	head[u] = tail++;
}

bool pre() {
	tail = edge;
	clr(head, 0);
	scanf("%d", &n);
	if (!n) return false;
	rep(i, 1, n) {
		for (;;) {
			int j, w;
			scanf("%d", &j);
			if (!j) break;
			scanf("%d", &w);
			ins(i, j, w);
			ins(j, i, w);
		}
	}
	return true;
}

void dfsSize(int u, int p) {
	size[u] = 1;
	maxSize[u] = 0;
	for (Edge *e = head[u]; e; e = e -> next) {
		int v = e -> v;
		if (v != p && !vis[v]) {
			dfsSize(v, u);
			size[u] += size[v];
			maxSize[u] = max(maxSize[u], size[v]);
		}
	}
}

void dfsRoot(int r, int u, int p) {
	maxSize[u] = max(maxSize[u], size[r] - size[u]);
	if (maxSize[u] < best) {
		best = maxSize[u];
		root = u;
	}
	for (Edge *e = head[u]; e; e = e -> next) {
		int v = e -> v;
		if (v != p && !vis[v]) dfsRoot(r, v, u);
	}
}

void dfsDis(int u, int d, int p) {
	dis.push_back(d);
	for (Edge *e = head[u]; e; e = e -> next) {
		int v = e -> v;
		if (v != p && !vis[v]) dfsDis(v, d + e -> w, u);
	}
}

int calc(int u, int d) {
	int ret = 0;
	dis.clear();
	dfsDis(u, d, 0);
	sort(dis.begin(), dis.end());
	int i = 0, j = dis.size() - 1;
	while (i < j) {
		if (dis[i] + dis[j] < k) ++i;
		else if (dis[i] + dis[j] > k) --j;
		else {
			if (dis[i] == dis[j]) return ret + (j - i) * (j - i + 1) / 2;
			int l = i, r = j;
			while (dis[l] == dis[i]) ++i;
			while (dis[r] == dis[j]) --j;
			ret += (i - l) * (r - j);
		}
	}
	return ret;
}

void dfs(int u) {
	best = infi;
	dfsSize(u, 0);
	dfsRoot(u, u, 0);
	u = root;
	ans += calc(u, 0);
	vis[u] = true;
	for (Edge *e = head[u]; e; e = e -> next) {
		int v = e -> v;
		if (!vis[v]) {
			ans -= calc(v, e -> w);
			dfs(v);
		}
	}
}

bool solve() {
	clr(vis, 0);
	scanf("%d", &k);
	if (!k) {
		printf(".\n");
		return false;
	}
	ans = 0;
	dfs(1);
	printf("%s\n", ans > 0 ? "AYE" : "NAY");
	return true;
}

int main() {
	while (pre()) while(solve());

	fclose(stdin);
	fclose(stdout);
	return 0;
}
