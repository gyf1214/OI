//Created At: Fri Nov 11 13:17:28 CST 2016
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
#define mm 500
using namespace std;

struct Node {
    char val;
    int d;
    Node *ch[2];
}node[mm], *tail = node, *s[mm];

int top, l[3];
char str[mm], out[3][mm];

Node *newNode(char val, int d) {
    tail -> val = val;
    tail -> d = d;
    tail -> ch[0] = tail -> ch[1] = NULL;
    return tail++;
}

void pc(int t, char c) {
    if (c != '*') out[t][l[t]++] = c;
}

void print(Node *x) {
    if (!x) return;
    pc(0, x -> val);
    print(x -> ch[0]);
    pc(2, x -> val);
    print(x -> ch[1]);
    pc(1, x -> val);
}

void work() {
    tail = node;
    top = 0;
    scanf("%s", str);
    while (str[0] != '0') {
        int i = strlen(str) - 1;
        Node *now = newNode(str[i], i);
        if (top <= 0 || i > s[top - 1] -> d) {
            if (top > 0) s[top - 1] -> ch[0] = now;
        } else {
            while (top > 0 && i <= s[top - 1] -> d) --top;
            if (top > 0) s[top - 1] -> ch[1] = now;
        }
        s[top++] = now;
        scanf("%s", str);
    }
    l[0] = l[1] = l[2] = 0;
    print(node);
    rep(i, 0, 2) {
        out[i][l[i]] = 0;
        printf("%s\n", out[i]);
    }
    printf("\n");
}

int main() {
    int t;
    scanf("%d", &t);
    rep(i, 1, t) work();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
