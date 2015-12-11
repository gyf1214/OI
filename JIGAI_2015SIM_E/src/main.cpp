//Created At: Fri Dec 11 16:20:31 CST 2015
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

int map[mm][mm];
int dis[mm], n;

int prim() {
	rep(i, 1, n - 1) {
		dis[i] = map[0][i];
	}
	int ans = 0;
	rep(i, 1, n - 1) {
		int best = infi, k;
		rep(j, 0, n - 1) {
			if (dis[j] > 0 && dis[j] < best) {
				best = dis[j], k = j;
			}
 		}
		ans += dis[k];
		rep(j, 0, n - 1) {
			dis[j] = min(dis[j], map[k][j]);
		}
	}
	return ans;
}

bool pre() {
	if (scanf("%d", &n) == EOF) return false;
	rep(i, 0, n - 1) {
		rep(j, 0, n - 1) {
			scanf("%d", &map[i][j]);
		}
	}
	return true;
}

int main() {
	while(pre()) printf("%d\n", prim());

	fclose(stdin);
	fclose(stdout);
	return 0;
}
