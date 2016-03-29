//Created At: Mon Mar 28 18:47:31 CST 2016
//orz zyx
//ntr czr
//Author: gyf

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <list>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define clr(i, a) memset(i, (a), sizeof(i))
#define infi 0x7FFFFFFF
#define mm 10010
using namespace std;

list<int> l[mm];

int main() {
	int n;
	scanf("%d", &n);
	rep(t, 1, n) {
		char str[10];
		int x, y;
		scanf("%s%d", str, &x);
		list<int>::iterator i;
		switch (str[0]) {
			case 'n':
			l[x].clear();
			break;
			case 'a':
			scanf("%d", &y);
			for (i = l[x].begin(); i != l[x].end(); ++i) {
				if (*i >= y) break;
			}
			l[x].insert(i, y);
			break;
			case 'm':
			scanf("%d", &y);
			l[x].merge(l[y]);
			break;
			case 'u':
			l[x].unique();
			break;
			case 'o':
			for (i = l[x].begin(); i != l[x].end(); ++i) {
				printf("%d ", *i);
			}
			printf("\n");
			break;
		}
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
