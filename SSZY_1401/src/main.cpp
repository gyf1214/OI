//Created At: Tue Dec 20 14:16:41 CST 2016
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
using namespace std;

map<string, vector<int> > a;
typedef vector<int>::iterator it;

int main() {
    int n, k;
    string x;
    cin >> n;
    rep(i, 1, n) {
        cin >> k;
        rep(j, 1, k) {
            cin >> x;
            a[x].push_back(i);
        }
    }
    cin >> n;
    rep(i, 1, n) {
        cin >> x;
        if (a[x].empty()) {
            cout << "NOT FOUND" << endl;
        } else {
            it ed = unique(a[x].begin(), a[x].end());
            a[x].erase(ed, a[x].end());
            for (it i = a[x].begin(); i != a[x].end(); ++i) {
                cout << *i << ' ';
            }
            cout << endl;
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
