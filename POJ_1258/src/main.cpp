//Created At: Fri Sep 11 16:28:05 CST 2015
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
#define mm 210
using namespace std;

int map[mm][mm], dis[mm], n;

int prim(int u) {
	int ans = 0;
	rep(i, 1, n) {
		dis[i] = map[u][i];
	}
	dis[u] = 0;
	rep(i, 1, n - 1) {
		int k, best = infi;
		rep(j, 1, n) {
			if (dis[j] && dis[j] < best) {
				best = dis[j];
				k = j;
			}
		}
		ans += dis[k];
		dis[k] = 0;
		rep(j, 1, n) {
			dis[j] = min(dis[j], map[k][j]);
		}
	}
	return ans;
}

bool pre() {
	if (scanf("%d", &n) == EOF) {
		return false;
	}
	rep(i, 1, n) {
		rep(j, 1, n) {
			scanf("%d", &map[i][j]);
		}
	}
	return true;
}

int main() {
	while (pre()) {
		printf("%d\n", prim(1));
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
