//Created At: Sun Jun 12 13:42:41 CST 2016
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
#define mm 1010
#define eps 1e-6
using namespace std;

struct Point {
    double x, y;
}p[mm];

int n;
int s[mm], top;

int cmp(double x) {
    return abs(x) <= eps ? 0 : (x > eps ? 1 : -1);
}

double det(const Point &a, const Point &b, const Point &c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

double dot(const Point &a, const Point &b, const Point &c) {
    return (b.x - a.x) * (c.x - a.x) + (b.y - a.y) * (c.y - a.y);
}

double dis(const Point &a, const Point &b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool comp(const Point &x, const Point &y) {
    return cmp(det(p[0], x, y)) > 0
        || (cmp(det(p[0], x, y)) == 0 && cmp(dis(p[0], x) - dis(p[0], y)) < 0);
}

bool comp2(const Point &x, const Point &y) {
    return cmp(x.y - y.y) < 0 || (cmp(x.y - y.y) == 0 && cmp(x.x - y.x) < 0);
}

void pre() {
    scanf("%d", &n);
    rep(i, 0, n - 1) scanf("%lf%lf", &p[i].x, &p[i].y);
    rep(i, 1, n - 1) if (comp2(p[i], p[0])) swap(p[i], p[0]);
    sort(p + 1, p + n, comp);
}

void push(int x) {
    while (top >= 2 && cmp(det(p[s[top - 2]], p[s[top - 1]], p[x])) <= 0) --top;
    s[top++] = x;
}

void graham() {
    s[0] = 0, s[1] = 1;
    top = 2;
    rep(i, 2, n - 1) push(i);
    s[top] = 0;
}

bool on(const Point &a, const Point &b, const Point &c) {
    return cmp(det(c, a, b)) == 0 && cmp(dot(c, a, b)) < 0;
}

bool check(const Point &a, const Point &b) {
    rep(i, 0, n - 1) if (on(a, b, p[i])) return true;
    return false;
}

bool work() {
    if (n < 6) return false;
    graham();
    rep(i, 0, top - 1) {
        if (!check(p[s[i]], p[s[i + 1]])) return false;
    }
    return true;
}

int main() {
    int t;
    scanf("%d", &t);
    rep(i, 1, t) {
        pre();
        printf("%s\n", work() ? "YES" : "NO");
    }

	fclose(stdin);
	fclose(stdout);
	return 0;
}
