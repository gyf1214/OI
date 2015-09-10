//Created At: Thu Sep 10 12:50:37 CST 2015
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
#define mm 100010
#define nm 20
using namespace std;

bool f[mm], g[mm];
int n, m, d[nm], k[nm];

int work() {
	clr(g, 0);
	g[0] = true;
	rep(i, 1, n) {
		clr(f, 0);
		rep(r, 0, d[i] - 1) {
			f[r] = g[r];
			int ts = g[r], l = 0;
			rep(b, 1, (m - r) / d[i]) {
				int j = d[i] * b + r;
				ts += g[j];
				while (l < max(0, b - k[i])) {
					ts -= g[r + (l++) * d[i]];
				}
				f[j] = ts > 0;
			}
		}
		memcpy(g, f, sizeof(f));
	}
	int ans;
	for (ans = m; !g[ans]; --ans);
	return ans;
}

bool pre() {
	if (scanf("%d", &m) == EOF) {
		return false;
	}
	scanf("%d", &n);
	rep(i, 1, n) {
		scanf("%d%d", k + i, d + i);
	}
	return true;
}

int main() {
	while (pre()) {
		printf("%d\n", work());
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
