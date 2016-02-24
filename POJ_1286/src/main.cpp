//Created At: Wed Feb 24 18:04:56 CST 2016
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
#define mm
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}

ll power(ll a, ll b) {
	ll ans = 1;
	rep(i, 1, b) {
		ans *= a;
	}
	return ans;
}

ll calc(ll x, ll c) {
	ll ans = 0;
	rep(i, 1, x) {
		ans += power(c, gcd(i, x));
	}
	if (x % 2) {
		ans += x * power(c, x / 2 + 1);
	} else {
		ans += x / 2 * (power(c, x / 2) + power(c, x / 2 + 1));
	}
	return ans / x / 2;
}

int main() {
	int x;
	for (;;) {
		scanf("%d", &x);
		if (x == -1) break;
		printf("%lld\n", calc(x, 3));
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
