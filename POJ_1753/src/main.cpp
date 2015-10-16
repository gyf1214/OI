//Created At: Fri Oct 16 15:52:59 CST 2015
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
#define mm 4
#define km (1 << 16)
using namespace std;

int dx[] = {0, -1, 0, 1, 0};
int dy[] = {0, 0, -1, 0, 1};

bool bound(int x, int y) {
	return x >= 0 && x < mm && y >= 0 && y < mm;
}

bool map[mm][mm];

bool check(int m) {
	int cnt = 0;
	rep(i, 0, mm - 1) {
		rep(j, 0, mm - 1) {
			bool ans = map[i][j];
			rep(k, 0, 4) {
				int x = i + dx[k];
				int y = j + dy[k];
				int t = mm * x + y;
				if (bound(x, y)) {
					ans ^= ((m >> t) & 1);
				}
			}
			cnt += ans ? 1 : 0;
		}
	}
	return cnt == 0 || cnt == 16;
}

int calc(int i) {
	int ans = 0;
	for (; i; i /= 2) ans += i % 2;
	return ans;
}

int main() {
	char str[20];
	rep(i, 0, mm - 1) {
		scanf("%s", str);
		rep(j, 0, mm - 1) {
			map[i][j] = str[j] == 'b';
		}
	}
	int ans = infi;
	rep(i, 0, km - 1) {
		if (check(i)) {
			ans = min(ans, calc(i));
		}
	}
	if (ans == infi) {
		printf("Impossible\n");
	} else {
		printf("%d\n", ans);
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
