//Created At: Thu Sep 10 10:56:09 CST 2015
//orz zyx
//ntr czr
//Author: gyf

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define clr(i, a) memset(i, (a), sizeof(i))
#define infi 0x7FFFFFFF
#define mm (210)
#define km (1 << 5)
#define nm (mm * mm * km)
using namespace std;

struct State {
	int x, y, b;
}q[nm];

char map[mm][mm];
int dis[mm][mm][km];
vector<pair<int, int> > door;
int n, m, k, sx, sy, l, r;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int cnt(int bits) {
	int ans = 0;
	for (; bits; bits /= 2) {
		ans += bits % 2;
	}
	return ans;
}

State make_state(int x, int y, int b) {
	State ans;
	ans.x = x;
	ans.y = y;
	ans.b = b;
	return ans;
}

void push_back(State v) {
	q[r++] = v;
}

State pop() {
	return q[l++];
}

void update(State u, State v) {
	if (!dis[v.x][v.y][v.b]) {
		dis[v.x][v.y][v.b] = dis[u.x][u.y][u.b] + 1;
		push_back(v);
		//printf("{%d, %d, %d} -> {%d, %d, %d}\n", u.x, u.y, u.b, v.x, v.y, v.b);
	}
}

void walk(State u) {
	rep(i, 0, 3) {
		State v = make_state(u.x + dx[i], u.y + dy[i], u.b);
		if (map[v.x][v.y] != '#') {
			update(u, v);
		}
	}
}

int bfs() {
	clr(dis, 0);
	dis[sx][sy][0] = 1;
	l = r = 0;
	q[r++] = make_state(sx, sy, 0);
	map[sx][sy] = '.';
	while (l != r) {
		State u = pop();
		if (map[u.x][u.y] == 'E' && cnt(u.b) >= k) {
			return dis[u.x][u.y][u.b];
		} else if (map[u.x][u.y] == '$') {
			rep(i, 0, door.size() - 1) {
				State v = make_state(door[i].first, door[i].second, u.b);
				if (!dis[v.x][v.y][v.b]) {
					dis[v.x][v.y][v.b] = dis[u.x][u.y][u.b];
					walk(v);
				}
			}
		} else if (map[u.x][u.y] >= '0' && map[u.x][u.y] <= '4') {
			int nb = map[u.x][u.y] - '0';
			State v = make_state(u.x, u.y, u.b | (1 << nb));
			if (!dis[v.x][v.y][v.b]) {
				dis[v.x][v.y][v.b] = dis[u.x][u.y][u.b];
				walk(v);
			}
		} else if (map[u.x][u.y] == '.') {
			walk(u);
		}
	}
	return 0;
}

void pre() {
	scanf("%d%d%d", &n, &m, &k);
	rep(i, 0, n + 1) {
		rep(j, 0, m + 1) {
			map[i][j] = '#';
		}
	}
	door.clear();
	char str[mm];
	rep(i, 1, n) {
		scanf("%s", str);
		rep(j, 1, m) {
			map[i][j] = str[j - 1];
			if (map[i][j] == 'S') {
				sx = i, sy = j;
			} else if (map[i][j] == '$') {
				door.push_back(make_pair(i, j));
			}
		}
	}
}

int main() {
	int t;
	scanf("%d", &t);
	rep(i, 1, t) {
		pre();
		int x = bfs() - 1;
		if (x == -1) {
			printf("oop!\n");
		} else {
			printf("%d\n", x);
		}
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
