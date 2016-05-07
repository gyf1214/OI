//Created At: Wed Apr 27 12:45:39 CST 2016
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
#define mm 5010
using namespace std;

int map[mm][mm];
int n, m, r;

struct P{
	int x, y;
}s[mm];

bool cmp(const P &a, const P &b) {
	return a.x < b.x || (a.x == b.x && a.y < b.y);
}

inline bool check(const P &p) {
	return p.x > 0 && p.x <= n && p.y > 0 && p.y <= m;
}

void pre() {
	scanf("%d%d%d", &n, &m, &r);
	rep(i, 1, r) {
		scanf("%d%d", &s[i].x, &s[i].y);
	}
	sort(s + 1, s + r + 1, cmp);
	rep(i, 1, r) {
		map[s[i].x][s[i].y] = i;
	}
}

int step(P p, int dx, int dy) {
	int ans = 1;
	while (check(p)) {
		if (!map[p.x][p.y]) return 0;
		++ans;
		p.x += dx;
		p.y += dy;
	}
	return ans;
}

int work() {
	int best = 2;
	rep(i, 1, r) rep(j, i + 1, r) {
		int dx = s[j].x - s[i].x;
		int dy = s[j].y - s[i].y;
		P p;
		p.x = s[i].x - dx;
		p.y = s[i].y - dy;
		if (check(p)) continue;
		p.x = s[i].x + best * dx;
		p.y = s[i].y + best * dy;
		if (!check(p)) continue;
		best = max(best, step(s[j], dx, dy));
	}
	return best >= 3 ? best : 0;
}

int main() {
	pre();
	printf("%d\n", work());

	fclose(stdin);
	fclose(stdout);
	return 0;
}
