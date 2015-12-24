//Created At: Thu Dec 24 21:50:02 CST 2015
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
#define mm 10010
using namespace std;

int f[mm], w[mm], p[mm];
int n;

int work(int m) {
	rep(i, 1, m) f[i] = infi;
	f[0] = 0;
	rep(i, 0, n - 1) {
		rep(j, 1, m) {
			if (j >= w[i] && f[j] - p[i] > f[j - w[i]]) {
				f[j] = f[j - w[i]] + p[i];
			}
		}
	}
	return f[m];
}

void pre() {
	int e, f;
	scanf("%d%d%d", &e, &f, &n);
	rep(i, 0, n - 1) {
		scanf("%d%d", p + i, w + i);
	}
	int ans = work(f - e);
	if (ans == infi) {
		printf("This is impossible.\n");
	} else {
		printf("The minimum amount of money in the piggy-bank is %d.\n", ans);
	}
}

int main() {
	int t;
	scanf("%d", &t);
	rep(i, 1, t) pre();

	fclose(stdin);
	fclose(stdout);
	return 0;
}
