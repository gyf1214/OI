//Created At: Tue Jun 21 11:41:27 CST 2016
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
#define mm 300010
using namespace std;

struct Node;
Node *null;

struct Node {
	int u, v;
	pair<int, Node *> up, val;
	Node *ch[2], *fa;
	bool rev;

	void init(int x, int u, int v) {
		up = val = make_pair(x, this);
		ch[0] = ch[1] = fa = null;
		this -> u = u;
		this -> v = v;
		rev = false;
	}

	void merge() {
		up = max(val, max(ch[0] -> up, ch[1] -> up));
	}

	void flip() {
		if (this != null) {
			swap(ch[0], ch[1]);
			rev = !rev;
		}
	}

	void push() {
		if (rev) {
			ch[0] -> flip();
			ch[1] -> flip();
			rev = false;
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

	Node *findroot() {
		access();
		Node *p = this;
        p -> push();
        while (p -> ch[0] != null) {
            p = p -> ch[0];
            p -> push();
        }
        return p;
	}

    void link(Node *x) {
        makeroot();
        fa = x;
    }

    void cut() {
        access();
        ch[0] -> fa = null;
        setc(0, null);
    }

    void cut(Node *x) {
        makeroot();
        x -> cut();
    }
}pool[mm], *node[mm], *tail;

struct Edge {
    int u, v, a, b;
}edge[mm];

int n, m;

bool comp(const Edge &a, const Edge &b) {
    return a.a < b.a;
}

Node *new_node(int x, int u, int v) {
    tail -> init(x, u, v);
    return tail++;
}

void pre() {
    tail = pool;
    null = tail++;
    null -> init(0, 0, 0);
    scanf("%d%d", &n, &m);
    rep(i, 1, n) node[i] = new_node(0, 0, 0);
    rep(i, 0, m - 1) {
        scanf("%d%d%d%d", &edge[i].u, &edge[i].v, &edge[i].a, &edge[i].b);
    }
    sort(edge, edge + m, comp);
}

int work() {
    int ans = infi;
    rep(i, 0, m - 1) {
        Node *u = node[edge[i].u];
        Node *v = node[edge[i].v];
        u -> makeroot();
        v -> access();
        bool flag = false;
        if (v -> findroot() == u) {
            pair<int, Node *> t = v -> up;
            if (t.first > edge[i].b) {
                t.second -> cut(node[t.second -> u]);
                t.second -> cut(node[t.second -> v]);
                flag = true;
            }
        } else flag = true;
        if (flag) {
            Node *e = new_node(edge[i].b, edge[i].u, edge[i].v);
            e -> link(u);
            e -> link(v);
        }

        u = node[1];
        v = node[n];
        u -> makeroot();
        v -> access();
        if (v -> findroot() == u) {
            ans = min(ans, edge[i].a + v -> up.first);
        }
    }
    return ans == infi ? -1 : ans;
}

int main() {
    pre();
    printf("%d\n", work());

	fclose(stdin);
	fclose(stdout);
	return 0;
}
