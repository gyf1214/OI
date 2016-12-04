//Created At: Sun Dec 4 14:42:13 CST 2016
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
#define mm 1000100
using namespace std;

struct Node {
    Node *ch[26];
    const char *str;
}node[mm], *tail = node, *root;

char b[mm][20];

Node *new_node() {
    clr(tail -> ch, 0);
    tail -> str = NULL;
    return tail++;
}

void ins(const char *a, const char *b) {
    char ch;
    Node *p;
    for (p = root; (ch = *a++); p = p -> ch[ch - 'a']) {
        if (!p -> ch[ch - 'a']) {
            p -> ch[ch - 'a'] = new_node();
        }
    }
    p -> str = b;
}

const char *find(const char *a) {
    char ch;
    Node *p;
    for (p = root; (ch = *a++); p = p -> ch[ch - 'a']) {
        if (!p -> ch[ch - 'a']) return NULL;
    }
    return p -> str;
}

char buf[100], buf1[100], buf2[100];

void pre() {
    root = new_node();
    fgets(buf, 100, stdin);
    int i = 0;
    while (sscanf(buf, "%s%s", b[i], buf2) == 2) {
        ins(buf2, b[i++]);
        fgets(buf, 100, stdin);
    }
}

void work() {
    while (scanf("%s", buf1) > 0) {
        const char *ans = find(buf1);
        printf("%s\n", ans ? ans : "eh");
    }
}

int main() {
    pre();
    work();

    fclose(stdin);
    fclose(stdout);
    return 0;
}
