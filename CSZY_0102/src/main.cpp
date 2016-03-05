//Created At: Wed Mar 2 14:17:55 CST 2016
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

int now, ans;
int minv[25];
int n, m;

void dfs(int v, int d, int r, int h) {
	if (d == 0) {
		if (v == 0 && now < ans) {
			ans = now;
		}
		return;
	}
	if (v - minv[d] < 0 || now + 2 * v / r >= ans) return;
	for (int i = r; i >= d; --i) {
		int maxh = min(h, (v - minv[d - 1]) / i / i);
		for (int j = maxh; j >= d; --j) {
			if (v - i * i * j >= 0) {
				if (d == m) now = i * i;
				now += 2 * i * j;
				dfs(v - i * i * j, d - 1, i - 1, j - 1);
				now -= 2 * i * j;
				if (d == m) now = 0;
			}
		}
	}
}

int main() {
	clr(minv, 0);
	rep(i, 1, 20) minv[i] = minv[i - 1] + i * i * i;
	while (scanf("%d%d", &n, &m) != EOF) {
		ans = infi;
		dfs(n, m, n, n);
		printf("%d\n", ans == infi ? 0 : ans);
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
