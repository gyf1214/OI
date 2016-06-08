//Created At: Wed Jun 8 11:57:22 CST 2016
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
#define mm 500
#define eps 1e-6
using namespace std;

struct Point {
	double x, y;
	Point(double x = 0, double y = 0) : x(x), y(y) {}
};

struct Line {
	double a, b, c;
	Line(double a = 0, double b = 0, double c = 0) : a(a), b(b), c(c) {}
	Line(const Point &x, const Point &y)
	: a(x.y - y.y), b(y.x - x.x), c(x.x * y.y - x.y * y.x) {}
	Line shift(double r) const {
		return Line(a, b, c - r * sqrt(a * a + b * b));
	}
	double f(const Point &x) const {
		return x.x * a + x.y * b + c;
	}
	Point inter(const Point &x, const Point &y) const {
		double u = abs(f(x));
		double v = abs(f(y));
		return Point((x.x * v + y.x * u) / (u + v), (x.y * v + y.y * u) / (u + v));
	}
};

int cmp(double x) {
	return abs(x) <= eps ? 0 : (x > eps ? 1 : -1);
}

Point p[mm], q[mm];
Line l[mm];
int n, m;

void init() {
	m = 0;
	p[++m] = Point(infi, infi);
	p[++m] = Point(-infi, infi);
	p[++m] = Point(-infi, -infi);
	p[++m] = Point(infi, -infi);
	p[0] = p[m];
	p[m + 1] = p[1];
}

void cut(const Line &l) {
	int k = 0;
	rep(i, 1, m) {
		if (cmp(l.f(p[i])) >= 0) {
			q[++k] = p[i];
		} else {
			if (cmp(l.f(p[i - 1])) > 0) q[++k] = l.inter(p[i - 1], p[i]);
			if (cmp(l.f(p[i + 1])) > 0) q[++k] = l.inter(p[i], p[i + 1]);
		}
	}
	m = k;
	rep(i, 1, k) p[i] = q[i];
	p[0] = p[m];
	p[m + 1] = p[1];
}

bool solve(double r) {
	init();
	rep(i, 1, n) cut(l[i].shift(r));
	return m > 0;
}

bool pre() {
	scanf("%d", &n);
	if (!n) return false;
	rep(i, 1, n) scanf("%lf%lf", &p[i].x, &p[i].y);
	p[n + 1] = p[1];
	rep(i, 1, n) l[i] = Line(p[i], p[i + 1]);
	return true;
}

void work() {
	double st = .0, ed = infi;
	while (ed - st > 1e-7) {
		double m = (st + ed) / 2;
		if (solve(m)) st = m; else ed = m;
	}
	printf("%.6lf\n", st);
}

int main() {
	while (pre()) work();

	fclose(stdin);
	fclose(stdout);
	return 0;
}
