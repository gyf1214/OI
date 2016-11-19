//Created At: Fri Nov 11 12:00:52 CST 2016
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
#define mm 1000010
using namespace std;

char str[mm];
int ne[mm];
int n;

void work() {
    ne[0] = -1;
    rep(i, 1, n) {
        int k = ne[i - 1];
        while (k >= 0 && str[i - 1] != str[k]) k = ne[k];
        ne[i] = ++k;
        if (k > 0 && i % (i - k) == 0) {
            printf("%d %d\n", i, i / (i - k));
        }
    }
}

bool pre() {
    scanf("%d", &n);
    if (!n) return false;
    scanf("%s", str);
    return true;
}

int main() {
    int t = 0;
    while (pre()) {
        printf("Test case #%d\n", ++t);
        work();
        printf("\n");
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
