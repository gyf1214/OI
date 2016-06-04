//Created At: Fri Jun 3 22:57:40 CST 2016
//orz zyx
//ntr czr
//Author: gyf

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i, a, b) for (int _a = (a), _b = (b), i = _a; i <= _b; ++i)
#define clr(i, a) memset(i, (a), sizeof(i))
#define infi 0x7FFFFFFF
#define mm 200000
using namespace std;

const double pi = acos(-1);

struct Complex {
	double x, y;
	Complex(double x = .0, double y = .0) : x(x), y(y) {}

	Complex operator +(const Complex &b) const {
		return Complex(x + b.x, y + b.y);
	}

	Complex operator -(const Complex &b) const {
		return Complex(x - b.x, y - b.y);
	}

	Complex operator *(const Complex &b) const {
		return Complex(x * b.x - y * b.y, x * b.y + b.x * y);
	}
};

void revbit(Complex *p, int n) {
	for (int i = 1, j = n / 2; i < n - 1; ++i) {
		if (i < j) swap(p[i], p[j]);
		int k = n / 2;
		while (j >= k) {
			j -= k;
			k /= 2;
		}
		j += k;
	}
}

void fft(Complex *p, int n, int op) {
	revbit(p, n);
	for (int m = 2; m <= n; m *= 2) {
		Complex wn(cos(2 * pi / m * op), sin(2 * pi / m * op));
		for (int i = 0; i < n; i += m) {
			Complex w(1);
			rep(j, 0, m / 2 - 1) {
				Complex t = w * p[i + j + m / 2];
				Complex u = p[i + j];
				p[i + j] = u + t;
				p[i + j + m / 2] = u - t;
				w = w * wn;
			}
		}
	}
	if (op == -1) rep(i, 0, n - 1) {
		p[i].x /= n;
		p[i].y /= n;
	}
}

char str[mm];
Complex a[mm], b[mm];
int c[mm];
int n;

int input(Complex *p) {
	scanf("%s", str);
	int n = strlen(str);
	rep(i, 0, n - 1) p[n - i - 1] = str[i] - '0';
	return n;
}

void pre() {
	clr(a, 0);
	clr(b, 0);
	int t = input(a) + input(b);
	for (n = 1; n <= t; n *= 2);
}

void work() {
	fft(a, n, 1);
	fft(b, n, 1);
	rep(i, 0, n - 1) a[i] = a[i] * b[i];
	fft(a, n, -1);
	rep(i, 0, n - 1) c[i] = round(a[i].x);
	rep(i, 0, n - 1) {
		c[i + 1] += c[i] / 10;
		c[i] %= 10;
	}
	int k;
	for (k = n - 1; !c[k]; --k);
	for (; k >= 0; --k) printf("%d%s", c[k], k ? "" : "\n");
}

int main() {
	int t;
	scanf("%d", &t);
	rep(i, 1, t) {
		pre();
		work();
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
