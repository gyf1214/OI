//Created At: Fri Jun 3 19:35:07 CST 2016
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
#define nm 100010
#define mm 4000010
using namespace std;

struct Node {
	int val, l, r;
    Node *ch[2];
}node[mm], *tail = node, *head[nm];

pair<int, int> temp[nm];
int a[nm], b[nm], n, m;

Node *update(Node *u, int i) {
    Node *v = tail++;
    *v = *u;
    ++v -> val;
    if (v -> l < v -> r) {
        int m = (v -> l + v -> r) / 2;
        int k = i <= m ? 0 : 1;
        v -> ch[k] = update(u -> ch[k], i);
    }
    return v;
}

Node *build(int l, int r) {
    Node *v = tail++;
    v -> l = l;
    v -> r = r;
    v -> val = 0;
    if (l < r) {
        int m = (l + r) / 2;
        v -> ch[0] = build(l, m);
        v -> ch[1] = build(m + 1, r);
    }
    return v;
}

int query(int l, int r, int k) {
    Node *u = head[l - 1], *v = head[r];
    while (u -> ch[0]) {
        int t = v -> ch[0] -> val - u -> ch[0] -> val;
        if (t >= k) {
            u = u -> ch[0];
            v = v -> ch[0];
        } else {
            k -= t;
            u = u -> ch[1];
            v = v -> ch[1];
        }
    }
    return u -> l;
}

void pre() {
    scanf("%d%d", &n, &m);
    rep(i, 1, n) {
        scanf("%d", &temp[i].first);
        temp[i].second = i;
    }
    sort(temp + 1, temp + 1 + n);
    int k = 1;
    rep(i, 1, n) {
        a[temp[i].second] = k;
        if (i == n || temp[i].first < temp[i + 1].first) {
            b[k++] = temp[i].first;
        }
    }
    head[0] = build(1, k - 1);
    rep(i, 1, n) {
        head[i] = update(head[i - 1], a[i]);
    }
}

void work() {
    rep(i, 1, m) {
        int l, r, k;
        scanf("%d%d%d", &l, &r, &k);
        printf("%d\n", b[query(l, r, k)]);
    }
}

int main() {
    pre();
    work();

	fclose(stdin);
	fclose(stdout);
	return 0;
}
