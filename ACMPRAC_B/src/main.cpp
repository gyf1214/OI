//Created At: Wed Aug 19 09:44:56 CST 2015
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
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))
#define infi 0x7FFFFFFF
#define mp(x, y) make_pair(x, y)
#define mm 100005
#define nm 
using namespace std;

struct Node;

Node *null;

vector<int> pa[mm];
int ans[mm];

struct Node {
    pair<int, Node*> val, mini;
    int u, v;
    int rev;
    Node* fa, *ch[2];

    void init(int w) {
        fa = ch[0] = ch[1] = null;
        u = v = rev = 0;
        val = mini = mp(w, this);
    }

    void merge() {
        mini = val;
        mini = min(mini, ch[0] -> mini);
        mini = min(mini, ch[1] -> mini);   
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
            rev = 0;
        }
    }

    int d() {
        return fa -> ch[0] == this ?  0 : 1;
    }

    bool isroot() {
        return fa == null || (fa -> ch[0] != this && fa -> ch[1] != this);
    }

    void go() {
        if (!isroot()) fa -> go();
        push();
    }

    void setc(Node* x, int c) {
        if (x != null) x -> fa = this;
        ch[c] = x;
        merge();
    }

    void rot() {
        Node *f = fa, *ff = fa -> fa;
        int c = d(), cc = fa -> d();
        f -> setc(ch[!c], c);
        setc(f, !c);
        if (ff -> ch[cc] == f) {
            ff -> setc(this, cc);
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
                } else {
                    rot();
                }
            }
            rot();
        }
    }

    void access() {
        for (Node *p = this, *q = null; p != null; q = p, p = p -> fa) {
            p -> splay();
            p -> setc(q, 1);
        }
        splay();
    }

    void makeroot() {
        access();
        flip();
    }

    void link(Node* x) {
        makeroot();
        fa = x;
    }

    void cut() {
        access();
        ch[0] -> fa = null;
        setc(null, 0);
    }

    void cut(Node* x) {
        makeroot();
        x -> cut();
    }

    Node* find_root() {
        access();
        Node* x;
        for (x = this, x -> push(); x -> ch[0] != null; x = x -> ch[0]);
        return x;
    }
}*node[mm], pool[mm * 3], *tail = pool;

Node* new_node(int w) {
    Node* ret = tail++;
    ret -> init(w);
    return ret;
}

pair<int, Node*> query(Node* u, Node* v) {
    u -> makeroot();
    v -> access();
    return v -> mini;
}

int insert(int i, int j, int w) {
    Node *u = node[i], *v = node[j], *p;
    u -> makeroot();
    if (v -> find_root() != u) {
        p = new_node(w);
        p -> u = i;
        p -> v = j;
        p -> link(u);
        p -> link(v);
        return w;
    } else {
        pair<int, Node*> tp = query(u, v);
        if (tp.first < w) {
            p = tp.second;
            p -> cut(node[p -> u]);
            p -> cut(node[p -> v]);
            p -> init(w);
            p -> u = i;
            p -> v = j;
            p -> link(node[i]);
            p -> link(node[j]);
            return w - tp.first;
        } else {
            return 0;
        }
    }
}

void work() {
    null = new_node(infi);
    null -> init(infi);
    rep(i, 1, mm - 1) {
        node[i] = new_node(infi);
    }
    for (int i = mm - 1; i > 0; --i) {
        for (int j = i + i; j < mm; j += i) {
            pa[j].push_back(i);
        }
    }

    ans[1] = 0;

    rep(i, 2, mm - 1) {
        ans[i] = ans[i - 1];
        for(int j = 0; j < pa[i].size(); ++j) {
            int t = pa[i][j];
            ans[i] += insert(i, t, t);
        }
    }
}

int main() {
    work();
    int x;
    scanf("%d", &x);
    printf("%d\n", ans[x]);

	fclose(stdin);
	fclose(stdout);
	return 0;
}

