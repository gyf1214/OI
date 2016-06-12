//Created At: Sat Jun 4 18:03:53 CST 2016
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
#define mm
#define eps 1e-6
using namespace std;

double r, h, v;

double f(double x) {
	double a = r - x;
	double b = sqrt(r * r - a * a);
	double f1 = 1.0 / 3.0 * h * r * r * acos(a / r);
	double f2 = -2.0 / 3.0 * a * h * b;
	double f3 = h * a * a * a / 3.0 / r * log((r + b) / a);
	return f1 + f2 + f3;
}

double work() {
	double s = 0.0, t = r;
	while (t - s > eps) {
		double m = (t + s) / 2.0;
		if (f(m) > v) t = m; else s = m;
	}
	return 2 * r - s;
}

int main() {
	int t;
	scanf("%d", &t);
	rep(i, 1, t) {
		scanf("%lf%lf%lf", &h, &r, &v);
		r /= 2.0;
		printf("%.5lf\n", work());
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
