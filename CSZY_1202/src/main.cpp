//Created At: Sat May 21 20:49:07 CST 2016
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
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define clr(i, a) memset(i, (a), sizeof(i))
#define infi 0x7FFFFFFF
#define mm
#define eps 1e-6
using namespace std;

struct Point {
	double x, y;
};

vector<Point> p, q;

int cmp(double x) {
	return abs(x) <= eps ? 0 : (x > eps ? 1 : -1);
}

bool operator <(Point a, Point b) {
	return cmp(a.x - b.x) < 0 || (cmp(a.x - b.x) == 0 && cmp(a.y - b.y) < 0);
}

bool operator ==(Point a, Point b) {
	return cmp(a.x - b.x) == 0 && cmp(a.y - b.y) == 0;
}

double det(Point p0, Point p1, Point p2) {
	return (p1.x - p0.x) * (p2.y - p0.y) - (p1.y - p0.y) * (p2.x - p0.x);
}

double dot(Point p0, Point p1, Point p2) {
	return (p1.x - p0.x) * (p2.x - p0.x) + (p1.y - p0.y) * (p2.y - p0.y);
}

bool isCross(Point s1, Point t1, Point s2, Point t2) {
	return cmp(det(s1, s2, t2)) * cmp(det(t1, s2, t2)) < 0
		&& cmp(det(s2, s1, t1)) * cmp(det(t2, s1, t1)) < 0;
}

int onSeg(Point p, Point s, Point t) {
	return cmp(det(p, s, t)) == 0 && cmp(dot(p, s, t)) < 0;
}

Point cross(Point s1, Point t1, Point s2, Point t2) {
	Point ret;
	double r1 = det(s2, t2, s1);
	double r2 = det(s2, t2, t1);
	ret.x = (r1 * t1.x - r2 * s1.x) / (r1 - r2);
	ret.y = (r1 * t1.y - r2 * s1.y) / (r1 - r2);
	return ret;
}

bool pre() {
	int n;
	scanf("%d", &n);
	if (n == 0)	return false;
	p.clear();
	rep(i, 1, n) {
		Point x;
		scanf("%lf%lf", &x.x, &x.y);
		p.push_back(x);
	}
	return true;
}

int work() {
	q.clear();
	for (int i = 0; i < p.size() - 1; ++i) q.push_back(p[i]);
	for (int i = 0; i < p.size() - 1; ++i) {
		for (int j = i + 1; j < p.size() - 1; ++j) {
			if (isCross(p[i], p[i + 1], p[j], p[j + 1])) {
				q.push_back(cross(p[i], p[i + 1], p[j], p[j + 1]));
			}
		}
	}
	int l = p.size() - 1;
	sort(q.begin(), q.end());
	q.resize(unique(q.begin(), q.end()) - q.begin());
	for (int i = 0; i < q.size(); ++i) {
		for (int j = 0; j < p.size() - 1; ++j) {
			if (onSeg(q[i], p[j], p[j + 1])) ++l;
		}
	}
	return l + 2 - q.size();
}

int main() {
	int t = 0;
	while(pre()) printf("Case %d: There are %d pieces.\n", ++t, work());

	fclose(stdin);
	fclose(stdout);
	return 0;
}
