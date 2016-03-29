//Created At: Mon Mar 28 19:44:57 CST 2016
//orz zyx
//ntr czr
//Author: gyf

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <set>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define clr(i, a) memset(i, (a), sizeof(i))
#define infi 0x7FFFFFFF
#define mm
using namespace std;

multiset<int> a, b;

int main() {
	int n, x;
	scanf("%d", &n);
	rep(t, 1, n) {
		char str[10];
		scanf("%s%d", str, &x);
		switch (str[1]) {
			case 'd':
			a.insert(x);
			b.insert(x);
			printf("%d\n", a.count(x));
			break;
			case 'e':
			printf("%d\n", a.count(x));
			a.erase(x);
			break;
			case 's':
			printf("%d %d\n", b.find(x) == b.end() ? 0 : 1, a.count(x));
			break;
		}
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
