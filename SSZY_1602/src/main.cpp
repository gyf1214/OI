//Created At: Mon Dec 26 21:42:12 CST 2016
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
#include <map>
#define rep(i, a, b) for (int _a = (a), _b = (b), i = _a; i <= _b; ++i)
#define clr(i, a) memset(i, (a), sizeof(i))
#define infi 0x7FFFFFFF
#define mm
using namespace std;

map<int, int> a;
typedef map<int, int>::iterator it;

bool work() {
    int x, y, z;
    scanf("%d", &x);
    if (!x) return false;
    switch(x) {
        case 1:
        scanf("%d%d", &y, &z);
        a.insert(make_pair(z, y));
        break;
        case 3:
        if (a.empty()) {
            printf("%d\n", 0);
        } else {
            it t = a.begin();
            printf("%d\n", t -> second);
            a.erase(t);
        }
        break;
        case 2:
        if (a.empty()) {
            printf("%d\n", 0);
        } else {
            it t = a.end();
            --t;
            printf("%d\n", t -> second);
            a.erase(t);
        }
        break;
    }
    return true;
}

int main() {
    while (work());

    fclose(stdin);
    fclose(stdout);
    return 0;
}
