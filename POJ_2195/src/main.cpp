//Created At: Sun Nov 1 19:21:44 CST 2015
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
#define mm 200
using namespace std;

int w[mm][mm], lx[mm], ly[mm], match[mm], n;
bool vx[mm], vy[mm];
int xm[mm], ym[mm], xh[mm], yh[mm];
char str[mm];

bool find(int x) {
	vx[x] = true;
	rep(y, 1, n) {
		if (!vy[y] && lx[x] + ly[y] == w[x][y]) {
			vy[y] = true;
			if (!match[y] || find(match[y])) {
				match[y] = x;
				return true;
			}
		}
	}
	return false;
}

void relax() {
	int d = infi;
	rep(x, 1, n) {
		if (vx[x]) {
			rep(y, 1, n) {
				if (!vy[y]) {
					d = min(d, lx[x] + ly[y] - w[x][y]);
				}
			}
		}
	}
	rep(i, 1, n) {
		if (vx[i]) lx[i] -= d;
		if (vy[i]) ly[i] += d;
	}
}

int km() {
	clr(match, 0);
	clr(lx, 0), clr(ly, 0);
	rep(x, 1, n) {
		rep(y, 1, n) lx[x] = max(lx[x], w[x][y]);
	}
	rep(x, 1, n) {
		for (;;) {
			clr(vx, 0), clr(vy, 0);
			if (find(x)) break;
			relax();
		}
	}
	int ans = 0;
	rep(y, 1, n) ans += w[match[y]][y];
	return ans;
}

bool pre() {
	int m, k, t = 0;
	n = 0;
	scanf("%d%d", &m, &k);
	if (m == 0) return false;
	rep(i, 1, m) {
		scanf("%s", str);
		rep(j, 0, k - 1) {
			if (str[j] == 'H') {
				xh[++n] = i;
				yh[n] = j;
			} else if (str[j] == 'm') {
				xm[++t] = i;
				ym[t] = j;
			}
		}
	}
	rep(i, 1, n) {
		rep(j, 1, n) {
			w[i][j] = - abs(xh[i] - xm[j]) - abs(yh[i] - ym[j]);
		}
	}
	return true;
}

int main() {
	while(pre()) printf("%d\n", -km());

	fclose(stdin);
	fclose(stdout);
	return 0;
}
