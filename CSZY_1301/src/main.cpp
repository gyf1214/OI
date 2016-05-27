//Created At: Thu May 26 16:24:53 CST 2016
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
#define mm 200010
#define mp(x, y) make_pair(x, y)
using namespace std;

struct Node {
    Node *fa;
    int rank, size;
}node[mm];

struct Trace {
    Node *u;
    int dr;
}s[mm];

int top;
int n, m, k;
long long ans;

vector<pair<int, int> > g[mm];

void init() {
    rep(i, 1, n) {
        node[i].fa = node + i;
        node[i].rank = 0;
        node[i].size = 1;
    }
    top = 0;
}

Node *find(Node *u) {
    while (u -> fa != u) u = u -> fa;
    return u;
}

long long merge(Node *u, Node *v) {
    u = find(u);
    v = find(v);
    if (u == v) return 0;
    long long ret = (long long)u -> size * (long long)v -> size;
    if (u -> rank > v -> rank) swap(u, v);
    if (u -> rank == v -> rank) {
        ++v -> rank;
        s[top].dr = 1;
    } else s[top].dr = 0;
    s[top++].u = u;
    u -> fa = v;
    v -> size += u -> size;
    return ret;
}

long long rollback(int b) {
    long long ret = 0;
    while (top > b) {
        --top;
        Node *u = s[top].u;
        Node *v = u -> fa;
        v -> size -= u -> size;
        v -> rank -= s[top].dr;
        u -> fa = u;
        ret += (long long)v -> size * (long long) u -> size;
    }
    return ret;
}

void solve(int l, int r) {
    if (l == r) {
        if (r <= k) printf("%lld\n", ans);
        return;
    }
    int m = (l + r) / 2;
    int base = top;
    rep(i, m + 1, r) {
        int t = g[i].size() - 1;
        rep(j, 0, t) {
            ans += merge(node + g[i][j].first, node + g[i][j].second);
        }
    }
    solve(l, m);
    ans -= rollback(base);
    rep(i, l, m) {
        int t = g[i].size() - 1;
        rep(j, 0, t) {
            ans += merge(node + g[i][j].first, node + g[i][j].second);
        }
    }
    solve(m + 1, r);
    ans -= rollback(base);
}

bool pre() {
    if (scanf("%d%d%d", &n, &m, &k) == EOF) return false;
    rep(i, 1, k + 1) g[i].clear();
    rep(i, 1, m) {
        int x, y, c;
        scanf("%d%d%d", &x, &y, &c);
        c = min(c, k + 1);
        g[c].push_back(mp(x, y));
    }
    init();
    ans = 0;
    return true;
}

int main() {
    while(pre()) solve(1, k + 1);

	fclose(stdin);
	fclose(stdout);
	return 0;
}
