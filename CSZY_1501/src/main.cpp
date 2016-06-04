//Created At: Sat Jun 4 16:16:27 CST 2016
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
#define mm 20000
using namespace std;

struct Node;

Node *null;

struct Node {
	int val, up, down;
    bool rev, neg, edge;
	Node *fa, *ch[2];

    void init(bool x, int w) {
        edge = x;
        val = w;
        rev = neg = false;
        fa = ch[0] = ch[1] = null;
        merge();
    }

    void merge() {
        up = edge ? val : -infi;
        down = edge ? val : infi;
        rep(i, 0, 1) {
            up = max(up, ch[i] -> up);
            down = min(down, ch[i] -> down);
        }
    }

    void flip() {
        if (this != null) {
            swap(ch[0], ch[1]);
            rev = !rev;
        }
    }

    void negate() {
        if (this != null) {
            val = -val;
            int t = up;
            up = -down;
            down = -t;
            neg = !neg;
        }
    }

    void push() {
        if (rev) {
            ch[0] -> flip();
            ch[1] -> flip();
            rev = false;
        }
        if (neg) {
            ch[0] -> negate();
            ch[1] -> negate();
            neg = false;
        }
    }

    int d() {
        return fa -> ch[0] == this ? 0 : 1;
    }

    bool isroot() {
        return fa == null || (fa -> ch[0] != this && fa -> ch[1] != this);
    }

    void go() {
        if (!isroot()) fa -> go();
        push();
    }

    void setc(int c, Node *x) {
        ch[c] = x;
        if (x != null) x -> fa = this;
        merge();
    }

    void rot() {
        Node *f = fa, *ff = fa -> fa;
        int c = d(), cc = fa -> d();
        f -> setc(c, ch[!c]);
        setc(!c, f);
        if (ff -> ch[cc] == f) {
            ff -> setc(cc, this);
        } else {
            fa = ff;
        }
    }

    void splay() {
        go();
        while (!isroot()) {
            if (!fa -> isroot()) {
                if (d() == fa -> d()) {
                    fa -> rot();
                } else rot();
            }
            rot();
        }
    }

    void access() {
        for (Node *p = this, *q = null; p != null; q = p, p = p -> fa) {
            p -> splay();
            p -> setc(1, q);
        }
        splay();
    }

    void makeroot() {
        access();
        flip();
    }

    void link(Node *x) {
        makeroot();
        fa = x;
    }
}pool[mm * 3], *node[mm], *edge[mm], *tail;

char str[30];

Node *new_node(bool x, int w) {
    tail -> init(x, w);
    return tail++;
}

int query(Node *u, Node *v) {
    u -> makeroot();
    v -> access();
    return v -> up;
}

void update(Node *u, int x) {
    u -> makeroot();
    u -> val = x;
    u -> merge();
}

void neg(Node *u, Node *v) {
    u -> makeroot();
    v -> access();
    v -> negate();
}

void pre() {
    tail = pool;
    null = tail++;
    null -> init(false, 0);
    int n;
    scanf("%d", &n);
    rep(i, 1, n) node[i] = new_node(false, 0);
    rep(i, 1, n - 1) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        edge[i] = new_node(true, w);
        edge[i] -> link(node[u]);
        edge[i] -> link(node[v]);
    }
}

void work() {
    for (;;) {
        scanf("%s", str);
        int u, v;
        if (str[0] == 'D') return;
        scanf("%d%d", &u, &v);
        if (str[0] == 'C') {
            update(edge[u], v);
        } else if (str[0] == 'N') {
            neg(node[u], node[v]);
        } else {
            printf("%d\n", query(node[u], node[v]));
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);
    rep(i, 1, t) {
        pre();
        work();
    }

	fclose(stdin);
	fclose(stdout);
	return 0;
}
