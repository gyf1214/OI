//Created At: Wed Apr 27 09:34:01 CST 2016
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
#define mm 1000010
using namespace std;

int f[mm], n, a, b, v[mm], q[mm], l, r;

inline bool valid(int i) {
	return i >= a && !v[i] && !(i % 2);
}

void push(int i) {
	if (f[i] == -1) return;
	while (r > l && f[q[r - 1]] >= f[i]) --r;
	q[r++] = i;
}

int pop(int i) {
	while (r > l && q[l] < i) ++l;
	return r > l ? q[l] : -1;
}

void pre() {
	int m;
	scanf("%d%d", &m, &n);
	scanf("%d%d", &a, &b);
	a *= 2, b *= 2;
	clr(v, 0);
	rep(i, 1, m) {
		int x, y;
		scanf("%d%d", &x, &y);
		v[x + 1] += 1, v[y] -= 1;
	}
	rep(i, 1, n) v[i] += v[i - 1];
	clr(f, -1);
	f[0] = 0;
	l = r = 0;
}

int work() {
	rep(i, a, n) {
		push(i - a);
		if (!valid(i)) continue;
		int j = pop(i - b);
		if (j != -1) f[i] = f[j] + 1;
	}
	return f[n];
}

int main() {
	pre();
	printf("%d\n", work());

	fclose(stdin);
	fclose(stdout);
	return 0;
}
