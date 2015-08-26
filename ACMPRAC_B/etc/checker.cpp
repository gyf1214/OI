//Created At: Wed Aug 19 10:53:12 CST 2015
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
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))
#define infi 0x7FFFFFFF
#define mm 1001
using namespace std;

struct Edge {
    int u, v, w;

    friend bool operator <(Edge u, Edge v) {
        return u.w > v.w;
    }

} edge[mm * mm];

int ne, n;
int p[mm];

int gcd(int u, int v) {
    int r = u % v;
    if (r == 0) {
        return v;
    } else {
        return gcd(v, r);
    }
}

void addedge(int u, int v, int w) {
    edge[ne].u = u;
    edge[ne].v = v;
    edge[ne++].w = w;
}

int find(int u) {
    if (p[u] != u) {
        p[u] = find(p[u]);
    }
    return p[u];
}

int work()
{
    ne = 0;
    scanf("%d", &n);
    rep(i, 1, n - 1) {
        rep(j, i + 1, n) {
            addedge(i, j, gcd(i, j));
        }
    }
    sort(edge, edge + ne);
    rep(i, 1, n) {
        p[i] = i;
    }
    int ans = 0;
    rep(i, 0, ne - 1) {
        int u = find(edge[i].u);
        int v = find(edge[i].v);
        if (u != v) {
            ans += edge[i].w;
            p[u] = v;
        }
    }
    return ans;
}

int main() {
    printf("%d\n", work());

	fclose(stdin);
	fclose(stdout);
	return 0;
}

