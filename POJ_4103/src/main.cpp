//Created At: Wed Sep 16 13:45:49 CST 2015
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
#define mm 100
using namespace std;

int map[mm][mm];
const int dx[] = {-1, 1, 0};
const int dy[] = {0, 0, 1};
int n, ans;

void dfs(int x, int y) {
	if (n == 0) {
		++ans;
		return;
	}
	rep(i, 0, 2) {
		int sx = x + dx[i];
		int sy = y + dy[i];
		if (!map[sx][sy]) {
			map[sx][sy] = true;
			--n;
			dfs(sx, sy);
			++n;
			map[sx][sy] = false;
		}
	}
}

int main() {
	scanf("%d", &n);
	clr(map, 0);
	ans = 0;
	map[50][0] = true;
	dfs(50, 0);
	printf("%d\n", ans);

	fclose(stdin);
	fclose(stdout);
	return 0;
}
