//Created At: Sun Nov 20 21:16:28 CST 2016
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
#define mm 40010
using namespace std;

struct Node;

Node *null;

struct Node {
    int val, sum, cnt;
    Node *ch[2], *fa;

    void merge() {
        sum = ch[0] -> sum + ch[1] -> sum + cnt;
    }

    void setc(int c, Node *x) {
        ch[c] = x;
        if (x != null) x -> fa = this;
        merge();
    }

    int d() {
        return fa -> ch[0] == this ? 0 : 1;
    }

    void rot() {
        int c = d(), cc = fa -> d();
        Node *f = fa, *ff = fa -> fa;
        f -> setc(c, ch[1 - c]);
        setc(1 - c, f);
        if (ff != null) {
            ff -> setc(cc, this);
        } else {
            fa = null;
        }
    }

    Node *splay() {
        while (fa != null) {
            if (fa -> fa != null) {
                if (d() == fa -> d()) {
                    fa -> rot();
                } else {
                    rot();
                }
            }
            rot();
        }
        return this;
    }
}node[mm], *tail = node;

Node *new_node(int val) {
    tail -> val = val;
    tail -> sum = tail -> cnt = 1;
    tail -> ch[0] = tail -> ch[1] = tail -> fa = null;
    return tail++;
}

Node *ins(Node *root, int val) {
    if (root == null) return new_node(val);
    Node *p, *q;
    int c;
    for (p = root, q = null; p != null && p -> val != val; q = p, p = p -> ch[c]) {
        c = p -> val > val ? 0 : 1;
    }
    if (p != null) {
        ++p -> cnt;
        ++p -> sum;
    } else {
        p = new_node(val);
        q -> setc(c, p);
    }
    for (; q != null; q = q -> fa) {
        q -> merge();
    }
    return p -> splay();
}

Node *find(Node *root, int k) {
    while (root != null) {
        if (root -> ch[0] -> sum > k) {
            root = root -> ch[0];
        } else {
            k -= root -> ch[0] -> sum;
            if (root -> cnt > k) break;
            k -= root -> cnt;
            root = root -> ch[1];
        }
    }
    return root -> splay();
}

int a[mm], n, m;

void pre() {
    null = tail;
    null = new_node(0);
    null -> cnt = null -> sum = 0;
    scanf("%d%d", &n, &m);
    rep(i, 0, n - 1) scanf("%d", a + i);
}

void work() {
    int k = 0;
    Node *root = null;
    rep(i, 0, m - 1) {
        int x;
        scanf("%d", &x);
        for (; k < x; ++k) root = ins(root, a[k]);
        root = find(root, i);
        printf("%d\n", root -> val);
    }
}

int main() {
    pre();
    work();

    fclose(stdin);
    fclose(stdout);
    return 0;
}
