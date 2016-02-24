//Created At: Wed Feb 24 17:51:00 CST 2016
//orz zyx
//ntr czr
//Author: gyf

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define clr(i, a) memset(i, (a), sizeof(i))
#define infi 0x7FFFFFFF
#define mm 2000
using namespace std;

int n;
int a[mm];

bool work() {
	scanf("%d", &n);
	rep(i, 1, n) {
		scanf("%d", a + i);
	}
	sort(a, a + n + 1);
	int ans = 0;
	for (int i = n; i > 0; i -= 2) {
		ans ^= (a[i] - a[i - 1] - 1);
	}
	return ans;
}

int main() {
	int t;
	scanf("%d", &t);
	a[0] = 0;
	rep(i, 1, t) {
		printf("%s\n", work() ? "Georgia will win" : "Bob will win");
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
