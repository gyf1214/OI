//Created At: Wed Sep 9 13:16:51 CST 2015
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
#define mm 80010
using namespace std;

int str[mm], n, k;
int sa[mm], rk[mm], tmp[mm], cnt[mm];
int height[mm];

bool cmp(int a, int b) {
	return str[a] < str[b];
}

void calc_sa() {
	rep(i, 1, n) {
		sa[i] = i;
	}
	sort(sa + 1, sa + 1 + n, cmp);
	clr(rk, 0);
	rep(i, 2, n) {
		if (str[sa[i]] == str[sa[i - 1]]) {
			rk[sa[i]] = rk[sa[i - 1]];
		} else {
			rk[sa[i]] = rk[sa[i - 1]] + 1;
		}
	}
	for (int k = 1; k <= n; k *= 2) {
		clr(cnt, 0);
		rep(i, 1, n) {
			++cnt[rk[i + k]];
		}
		rep(i, 1, n) {
			cnt[i] += cnt[i - 1];
		}
		rep(i, 1, n) {
			tmp[cnt[rk[i + k]]--] = i;
		}
		clr(cnt, 0);
		rep(i, 1, n) {
			++cnt[rk[i]];
		}
		rep(i, 1, n) {
			cnt[i] += cnt[i - 1];
		}
		for (int i = n; i >= 1; --i) {
			sa[cnt[rk[tmp[i]]]--] = tmp[i];
		}
		clr(tmp, 0);
		rep(i, 2, n) {
			if (rk[sa[i]] == rk[sa[i - 1]] && rk[sa[i] + k] == rk[sa[i - 1] + k]) {
				tmp[sa[i]] = tmp[sa[i - 1]];
			} else {
				tmp[sa[i]] = tmp[sa[i - 1]] + 1;
			}
		}
		rep(i, 1, n) {
			rk[i] = tmp[i];
		}
	}
	rep(i, 1, n) {
		rk[sa[i]] = i;
	}
}

void calc_height() {
	clr(height, 0);
	int h = 0;
	rep(i, 1, n) {
		int j = sa[rk[i] - 1];
		if (h > 0) {
			--h;
		}
		for (; j + h <= n && i + h <= n; ++h) {
			if (str[j + h] != str[i + h]) {
				break;
			}
		}
		height[rk[i] - 1] = h;
	}
}

int check(int k) {
	int t = 0;
	for (int now = 1; now < n; ++now) {
		int x = 1;
		for (; height[now] >= k; ++now) {
			++x;
		}
		t = max(t, x);
	}
	return t;
}

int calc() {
	int l = 1, r = n + 1;
	while (r - l > 1) {
		int m = (l + r) / 2;
		if (check(m) >= k) {
			l = m;
		} else {
			r = m;
		}
	}
	return l;
}

void pre() {
	scanf("%d%d", &n, &k);
	rep(i, 1, n) {
		scanf("%d", str + i);
	}
}

int main() {
	pre();
	calc_sa();
	calc_height();
	printf("%d\n", calc());

	fclose(stdin);
	fclose(stdout);
	return 0;
}
