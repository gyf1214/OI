//Created At: Fri May 20 11:18:44 CST 2016
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
#define mm 110
using namespace std;

int c, n, m;

double f[mm], g[mm];

bool pre() {
	scanf("%d", &c);
	if (!c) return false;
	scanf("%d%d", &n, &m);
	clr(f, 0);
	f[0] = 1.0;
	n = min(n, 500 + n % 2);
	return true;
}

double work() {
	if (m > c || m % 2 != n % 2) return .0;
	rep(i, 1, n) {
		memcpy(g, f, sizeof(f));
		rep(j, 0, c) {
			f[j] = .0;
			if (j > 0) f[j] += g[j - 1] * (double)(c - j + 1) / (double)c;
			if (j < c) f[j] += g[j + 1] * (double)(j + 1) / (double)c;
		}
	}
	return f[m];
}

int main() {
	while (pre()) printf("%.3lf\n", work());

	fclose(stdin);
	fclose(stdout);
	return 0;
}
