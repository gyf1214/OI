//Created At: Thu Sep 10 12:38:47 CST 2015
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

bool map[mm][mm];
int ans[mm][mm], n, m, k;

void work() {
	clr(ans, 0);
	rep(i, 1, n) {
		rep(j, 1, n) {
			rep(k, 1, n) {
				if (map[i][k] && map[j][k]) {
					++ans[i][j];
				}
			}
		}
	}
}

void pre() {
	clr(map, 0);
	scanf("%d%d%d", &n, &m, &k);
	rep(i, 1, m) {
		int x, y;
		scanf("%d%d", &x, &y);
		map[x][y] = map[y][x] = true;
	}
	work();
	rep(i, 1, k) {
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%d\n", ans[x][y]);
	}
}

int main() {
	int t;
	scanf("%d", &t);
	rep(i, 1, t) {
		printf("Case %d:\n", i);
		pre();
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
