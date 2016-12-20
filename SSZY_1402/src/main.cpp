//Created At: Tue Dec 20 18:42:32 CST 2016
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
#define mm 1010
using namespace std;

vector<int> a[mm], x, y;
typedef vector<int>::iterator it;
int b[mm];
int n;

void work() {
    rep(i, 0, n - 1) scanf("%d", b + i);
    rep(i, 0, n - 1) if (b[i] == 1) {
        y = a[i];
        break;
    }
    rep(i, 0, n - 1) if (b[i]) {
        it last;
        x.resize(y.size());
        if (b[i] == 1) {
            last = set_intersection(y.begin(), y.end(), a[i].begin(), a[i].end(), x.begin());
        } else {
            last = set_difference(y.begin(), y.end(), a[i].begin(), a[i].end(), x.begin());
        }
        x.resize(last - x.begin());
        swap(x, y);
    }
    if (!y.size()) {
        printf("NOT FOUND\n");
    } else {
        for (it i = y.begin(); i != y.end(); ++i) {
            printf("%d ", *i);
        }
        printf("\n");
    }
}

void pre() {
    scanf("%d", &n);
    rep(i, 0, n - 1) {
        int k, x;
        scanf("%d", &k);
        rep(j, 1, k) {
            scanf("%d", &x);
            a[i].push_back(x);
        }
        sort(a[i].begin(), a[i].end());
        it last = unique(a[i].begin(), a[i].end());
        a[i].erase(last, a[i].end());
    }
}

int main() {
    pre();
    int m;
    scanf("%d", &m);
    rep(i, 1, m) work();

    fclose(stdin);
    fclose(stdout);
    return 0;
}
