//Created At: Mon Dec 26 21:24:49 CST 2016
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
#define mm 30010
using namespace std;

struct Node {
    int cnt;
    Node *ch[26];
}node[mm], *tail = node, *root;

char str[2000][30];
int n;

Node *new_node() {
    clr(tail -> ch, 0);
    tail -> cnt = 0;
    return tail++;
}

void ins(char *s) {
    Node *now = root;
    for (; *s; ++s) {
        ++now -> cnt;
        int t = *s - 'a';
        if (!now -> ch[t]) now -> ch[t] = new_node();
        now = now -> ch[t];
    }
    ++now -> cnt;
}

void find(char *s) {
    Node *now = root;
    for (char *x = s; *x; ++x) {
        if (now -> cnt == 1) {
            *x = 0;
            break;
        }
        now = now -> ch[*x - 'a'];
    }
    printf("%s\n", s);
}

int main() {
    root = new_node();
    n = 0;
    while (scanf("%s", str[n]) > 0) ins(str[n++]);
    rep(i, 0, n - 1) {
        printf("%s ", str[i]);
        find(str[i]);
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
