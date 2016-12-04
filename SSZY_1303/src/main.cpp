//Created At: Sun Dec 4 15:27:06 CST 2016
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
#define mm 100010
using namespace std;

int p[mm], t[mm];
int m;

int find(int x) {
    if (p[x] == x) return x;
    find(p[x]);
    t[x] = (t[p[x]] ^ t[x]);
    p[x] = p[p[x]];
    return p[x];
}

void merge(int x, int y) {
    int xx = find(x);
    int yy = find(y);
    int tt = (t[x] ^ t[y] ^ 1);
    p[xx] = yy;
    t[xx] = tt;
}

void query(int x, int y) {
    int xx = find(x);
    int yy = find(y);
    if (xx != yy) {
        printf("Not sure yet.\n");
    } else {
        printf("%s\n", (t[x] ^ t[y]) ? "In different gangs." : "In the same gang.");
    }
}

void pre() {
    int n;
    scanf("%d%d", &n, &m);
    rep(i, 1, n) {
        p[i] = i;
        t[i] = 0;
    }
}

char buf[10];

void work() {
    rep(i, 1, m) {
        int x, y;
        scanf("%s%d%d", buf, &x, &y);
        if (buf[0] == 'D') {
            merge(x, y);
        } else {
            query(x, y);
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
