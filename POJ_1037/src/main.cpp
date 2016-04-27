//Created At: Wed Apr 27 10:11:12 CST 2016
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
#define mm 21
using namespace std;

typedef long long ll;

ll f[mm][mm][2];
bool v[mm];

int get(int i) {
	int ret = 0;
	while (i--) {
		++ret;
		while (v[ret]) ++ret;
	}
	v[ret] = true;
	return ret;
}

void pre() {
	clr(f, 0);
	f[1][1][0] = f[1][1][1] = 1;
	rep(i, 2, mm - 1) {
		rep(j, 1, i) {
			rep(k, 1, j - 1) f[i][j][0] += f[i - 1][k][1];
			rep(k, j, i - 1) f[i][j][1] += f[i - 1][k][0];
		}
	}
}

void work(int n, ll c) {
	clr(v, 0);
	int x;
	int t;
	for (x = 1;; ++x) {
		if (c <= f[n][x][t = 0]) break;
		c -= f[n][x][0];
		if (c <= f[n][x][t = 1]) break;
		c -= f[n][x][1];
	}
	printf("%d%c", get(x), n == 1 ? '\n' : ' ');
	for (--n; n > 0; --n) {
		t ^= 1;
		x = t ? 1 : x;
		for(;; ++x)  {
			if (c <= f[n][x][t]) break;
			c -= f[n][x][t];
		}
		printf("%d%c", get(x), n == 1 ? '\n' : ' ');
	}
}

int main() {
	pre();
	int t;
	scanf("%d", &t);
	rep(i, 1, t) {
		int n;
		ll c;
		scanf("%d%lld", &n, &c);
		work(n, c);
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
