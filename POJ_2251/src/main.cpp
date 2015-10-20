//Created At: Fri Oct 16 16:07:07 CST 2015
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
#define mm 40
using namespace std;

int d[][3] = {
	{-1, 0, 0}, {1, 0, 0},
	{0, -1, 0}, {0, 1, 0},
	{0, 0, -1}, {0, 0, 1}
};


bool map[mm][mm][mm];
int dis[mm][mm][mm];
int q[mm * mm * mm][3], st[3], ed[3];
int l, r;

void work() {
	clr(dis, 0);
	dis[st[0]][st[1]][st[2]] = 1;
	l = r = 0;
	rep(i, 0, 2) q[r][i] = st[i];
	r++;
	while (r > l) {
		rep(k, 0, 5) {
			int v[3];
			rep(i, 0, 2) v[i] = q[l][i] + d[k][i];
			if (map[v[0]][v[1]][v[2]] && ! dis[v[0]][v[1]][v[2]]) {
				dis[v[0]][v[1]][v[2]] = dis[q[l][0]][q[l][1]][q[l][2]] + 1;
				rep(i, 0, 2) q[r][i] = v[i];
				r++;
			}
		}
		l++;
	}
	if (!dis[ed[0]][ed[1]][ed[2]]) {
		printf("Trapped!\n");
	} else {
		printf("Escaped in %d minute(s).\n", dis[ed[0]][ed[1]][ed[2]] - 1);
	}
}

bool pre() {
	clr(map, 0);
	int n, m, l;
	scanf("%d%d%d", &n, &m, &l);
	if (n == 0) return false;
	rep(i, 1, n) {
		char str[mm];
		rep(j, 1, m) {
			scanf("%s", str + 1);
			rep(k, 1, l) {
				if (str[k] != '#') {
					map[i][j][k] = true;
					if (str[k] == 'S') {
						st[0] = i, st[1] = j, st[2] = k;
					}
					if (str[k] == 'E') {
						ed[0] = i, ed[1] = j, ed[2] = k;
					}
				}
			}
		}
	}
	return true;
}

int main() {
	while (pre()) work();

	fclose(stdin);
	fclose(stdout);
	return 0;
}
