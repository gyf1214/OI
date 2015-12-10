//Created At: Thu Dec 10 17:42:50 CST 2015
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
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define clr(i, a) memset(i, (a), sizeof(i))
#define infi 0x7FFFFFFF
#define eps 1e-6
#define mm 2000
using namespace std;

struct Line {
	double x1, x2, y;
	double l, r;
}thing[mm], house, line;

int n;

int cmp(double x) {
	return abs(x) <= eps ? 0 : (x > eps ? 1 : -1);
}

double project(double x1, double y1, double x2, double y2, double y0) {
	return x2 - (x1 - x2) * (y2 - y0) / (y1 - y2);
}

bool pre() {
	scanf("%lf%lf%lf", &house.x1, &house.x2, &house.y);
	if (!house.x1 && !house.x2 && !house.y) return false;
	scanf("%lf%lf%lf", &line.x1, &line.x2, &line.y);
	scanf("%d", &n);
	rep(i, 0, n - 1) {
		scanf("%lf%lf%lf", &thing[i].x1, &thing[i].x2, &thing[i].y);
	}
	return true;
}

void calc(Line &l) {
	if (cmp(l.y - line.y) > 0 && cmp(house.y - l.y) > 0) {
		l.l = project(house.x2, house.y, l.x1, l.y, line.y);
		l.r = project(house.x1, house.y, l.x2, l.y, line.y);
	} else {
		l.l = l.r = line.x2 + 1;
	}
}

bool comp(Line l1, Line l2) {
	return l1.l < l2.l;
}

void work() {
	rep(i, 0, n - 1) calc(thing[i]);
	sort(thing, thing + n, comp);
	double ans = .0;
	double last = line.x1;
	rep(i, 0, n - 1) {
		if (cmp(last - line.x2) > 0 || cmp(thing[i].l - line.x2) > 0) break;
		if (cmp(thing[i].l - last) > 0) {
			ans = max(ans, thing[i].l - last);
			last = thing[i].r;
		} else if (cmp(thing[i].r - last) > 0) {
			last = thing[i].r;
		}
	}
	ans = max(ans, line.x2 - last);
	if (cmp(ans) > 0) {
		printf("%.2lf\n", ans);
	} else {
		printf("No View\n");
	}
}

int main() {
	while (pre()) work();

	fclose(stdin);
	fclose(stdout);
	return 0;
}
