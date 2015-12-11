//Created At: Fri Dec 11 15:47:58 CST 2015
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
#define mm 500
using namespace std;

typedef pair<int, int> pii;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
pii q[mm];
bool vis[mm][mm], map[mm][mm];
int m, n, sx, sy;

int bfs() {
	int l = 0, r = 1;
	q[l] = make_pair(sx, sy);
	clr(vis, 0);
	vis[sx][sy] = true;
	int ans = 1;
	while (l < r) {
		pii now = q[l++];
		rep(i, 0, 3) {
			int x = now.first + dx[i];
			int y = now.second + dy[i];
			if (map[x][y] && !vis[x][y]) {
				++ans;
				vis[x][y] = true;
				q[r++] = make_pair(x, y);
			}
		}
	}
	return ans;
}

bool pre() {
	scanf("%d%d", &m, &n);
	if (!n && !m) return false;
	clr(map, 0);
	rep(i, 1, n) {
		char ch[mm];
		scanf("%s", ch);
		rep(j, 1, m) {
			map[i][j] = ch[j - 1] != '#';
			if (ch[j - 1] == '@') sx = i, sy = j;
		}
	}
	return true;
}

int main() {
	while(pre()) printf("%d\n", bfs());

	fclose(stdin);
	fclose(stdout);
	return 0;
}
