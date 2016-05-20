//Created At: Fri May 20 10:30:10 CST 2016
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
#define mm 2010
#define mod 1000000007
using namespace std;

int n, m;

struct Poly {
	long long a[mm * 2];

	Poly mul(const Poly &o) const {
		Poly ret;
		clr(ret.a, 0);
		rep(i, 0, n - 1) {
			rep(j, 0, n - 1) {
				ret.a[i + j] = (ret.a[i + j] + a[i] * o.a[j]) % mod;
			}
		}
		return ret;
	}

	Poly &mol(const Poly &o) {
		for (int i = 2 * n - 1; i >= n; --i) {
			rep(j, 0, n - 1) {
				a[i + j - n] = (a[i + j - n] + o.a[j] * a[i]) % mod;
			}
		}
		return *this;
	}
}f, g, t;

long long h[mm];

void pre() {
	scanf("%d%d", &m, &n);
	rep(i, 1, n) scanf("%lld", &f.a[n - i]);
	rep(i, 0, n - 1) scanf("%lld", h + i);
}

long long work() {
	clr(g.a, 0);
	g.a[0] = 1;
	clr(t.a, 0);
	t.a[1] = 1;
	for (; m; m /= 2) {
		if (m & 1) g = g.mul(t).mol(f);
		t = t.mul(t).mol(f);
	}
	long long ans = 0;
	rep(i, 0, n - 1) ans = (ans + g.a[i] * h[i]) % mod;
	return (ans + mod) % mod;
}

int main() {
	pre();
	printf("%lld\n", work());

	fclose(stdin);
	fclose(stdout);
	return 0;
}
