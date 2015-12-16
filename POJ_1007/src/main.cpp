//Created At: Wed Dec 16 23:18:59 CST 2015
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

char str[mm][mm];
int cnt[mm], ans[mm];
int m, n;

bool cmp(int i, int j) {
	return cnt[i] < cnt[j] || (cnt[i] == cnt[j] && i < j);
}

void calc(int k) {
	cnt[k] = 0;
	rep(i, 0, n - 2) {
		rep(j, i + 1, n - 1) {
			if (str[k][i] > str[k][j]) ++cnt[k];
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	rep(i, 0, m - 1) {
		scanf("%s", str[i]);
		calc(i);
		ans[i] = i;
	}
	sort(ans, ans + m, cmp);
	rep(i, 0, m - 1) {
		printf("%s\n", str[ans[i]]);
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
