//Created At: Thu Dec 24 22:11:18 CST 2015
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
#define sqr(x) ((x)*(x))
#define infi 0x7FFFFFFF
#define mm 20
#define eps 1e-6
using namespace std;

struct Wall {
	double x;
	double y[4];
}wall[mm];

int cmp(double x) {
	return abs(x) <= eps ? 0 : (x > eps ? 1 : -1);
}

bool across(double x1, double y1, double x2, double y2, Wall w) {
	double yy = y1 + (y2 - y1) / (x2 - x1) * (w.x - x1);
	return (cmp(yy - w.y[0]) >= 0 && cmp(yy - w.y[1]) <= 0)
		|| (cmp(yy - w.y[2]) >= 0 && cmp(yy - w.y[3]) <= 0);
}

bool check(int i, int j, int k1, int k2) {
	rep(x, i + 1, j - 1) {
		if (!across(wall[i].x, wall[i].y[k1], wall[j].x, wall[j].y[k2], wall[x])) {
			return false;
		}
	}
	return true;
}

double dis(int i, int j, int k1, int k2) {
	return sqrt(sqr(wall[i].x - wall[j].x) + sqr(wall[i].y[k1] - wall[j].y[k2]));
}

double dp[mm][4];
int n;

double work() {
	wall[0].x = .0;
	rep(i, 0, 3) wall[0].y[i] = 5.0;
	wall[n + 1].x = 10.0;
	rep(i, 0, 3) wall[n + 1].y[i] = 5.0;
	rep(i, 0, 3) dp[0][i] = .0;
	rep(i, 1, n + 1) {
		rep(k1, 0, 3) {
			dp[i][k1] = infi;
			rep(j, 0, i - 1) {
				rep(k2, 0, 3) {
					if (check(j, i, k2, k1)) {
						dp[i][k1] = min(dp[i][k1], dp[j][k2] + dis(i, j, k1, k2));
					}
				}
			}
		}
	}
	return dp[n + 1][0];
}

bool pre() {
	scanf("%d", &n);
	if (n == -1) return false;
	rep(i, 1, n) {
		scanf("%lf", &wall[i].x);
		rep(j, 0, 3) scanf("%lf", &wall[i].y[j]);
	}
	return true;
}

int main() {
	while (pre()) printf("%.2lf\n", work());

	fclose(stdin);
	fclose(stdout);
	return 0;
}
