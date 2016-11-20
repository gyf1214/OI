//Created At: Mon Nov 21 00:05:29 CST 2016
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
#define mm 4000010
#define nm 100010
using namespace std;

struct Node {
    int l, r;
    int val;
    Node *ch[2];
}node[mm], *tail = node;

Node *new_node(Node *x) {
    *tail = *x;
    return tail++;
}

Node *new_node(int l, int r) {
    tail -> l = l;
    tail -> r = r;
    tail -> val = 0;
    tail -> ch[0] = tail -> ch[1] = NULL;
    return tail++;
}

Node *build(int l, int r) {
    Node *root = new_node(l, r);
    if (r > l) {
        int m = (l + r) / 2;
        root -> ch[0] = build(l, m);
        root -> ch[1] = build(m + 1, r);
    }
    return root;
}

Node *ins(Node *root, int x) {
    Node *ret = new_node(root);
    ++ret -> val;
    if (ret -> r > ret -> l) {
        int m = (ret -> l + ret -> r) / 2;
        int c = x <= m ? 0 : 1;
        ret -> ch[c] = ins(ret -> ch[c], x);
    }
    return ret;
}

Node *head[nm];
int m, n, k;
struct Line {
    int k, x;
    bool operator <(const Line &other) const {
        return x < other.x;
    }
}line[nm];
int a[nm], b[nm];

void pre() {
    scanf("%d%d", &n, &m);
    rep(i, 1, n) {
        scanf("%d", &line[i].x);
        line[i].k = i;
    }
    sort(line + 1, line + 1 + n);
    k = 1;
    rep(i, 1, n) {
        a[line[i].k] = k;
        b[k] = line[i].x;
        if (i < n && line[i].x != line[i + 1].x) ++k;
    }
}

int find(int l, int r, int x) {
    Node *ll = head[l - 1], *rr = head[r];
    while (ll -> ch[0]) {
        int t = rr -> ch[0] -> val - ll -> ch[0] -> val;
        int c = x > t ? 1 : 0;
        x -= c * t;
        ll = ll -> ch[c];
        rr = rr -> ch[c];
    }
    return ll -> l;
}

void work() {
    head[0] = build(1, k);
    rep(i, 1, n) {
        head[i] = ins(head[i - 1], a[i]);
    }
    rep(i, 1, m) {
        int l, r, x;
        scanf("%d%d%d", &l, &r, &x);
        int k = find(l, r, x);
        printf("%d\n", b[k]);
    }
 }

int main() {
    pre();
    work();

    fclose(stdin);
    fclose(stdout);
    return 0;
}
