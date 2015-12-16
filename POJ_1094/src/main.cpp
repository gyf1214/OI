//Created At: Wed Dec 16 23:31:16 CST 2015
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
#define mm 30
using namespace std;

bool map[mm][mm];
int dg[mm], temp[mm], q[mm];
int n, m;

int tsort() {
	int ans = 1, r = 0;
	memcpy(temp, dg, sizeof(dg));
	clr(q, 0);
	rep(i, 0, n - 1) {
		int cnt = 0, k;
		rep(j, 0, n - 1) {
			if (!temp[j]) {
				++cnt;
				k = j;
			}
		}
		if (!cnt) return -1;
		if (cnt > 1) ans = 0;
		q[r++] = k;
		temp[k] = -1;
		rep(j, 0, n - 1) {
			if (map[k][j]) --temp[j];
		}
	}
	return ans;
}

void work() {
	char str[10];
	bool flag = false;
	clr(map, 0);
	clr(dg, 0);
	clr(q, 0);
	rep(i, 1, m) {
		scanf("%s", str);
		if (!flag) {
			int x = str[0] - 'A';
			int y = str[2] - 'A';
			map[x][y] = 1;
			++dg[y];
			int z = tsort();
			if (z == -1) {
				printf("Inconsistency found after %d relations.\n", i);
				flag = true;
			} else if (z == 1) {
				printf("Sorted sequence determined after %d relations: ", i);
				rep(j, 0, n - 1) printf("%c%s", 'A' + q[j], j == n - 1 ? ".\n" : "");
				flag = true;
			}
		}
	}
	if (!flag) printf("Sorted sequence cannot be determined.\n");
}

int main() {
	do {
		scanf("%d%d", &n, &m);
		if (n != 0 || m != 0) work();
	} while (n != 0 || m != 0);

	fclose(stdin);
	fclose(stdout);
	return 0;
}
