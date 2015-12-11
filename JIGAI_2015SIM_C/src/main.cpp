//Created At: Fri Dec 11 15:59:58 CST 2015
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
#define mm 50010
using namespace std;

typedef pair<int, int> pii;
pii cow[mm];
int n, t;

int work() {
	scanf("%d%d", &n, &t);
	rep(i, 0, n - 1) {
		scanf("%d%d", &cow[i].first, &cow[i].second);
	}
	sort(cow, cow + n);
	int last = 1, ans = 0;
	for (int i = 0; i < n; ++i) {
		int best = 0, k;
		rep(j, i, n - 1) {
			if (cow[j].first <= last) {
				if (cow[j].second > best) {
					best = cow[j].second;
					k = j;
				}
			} else break;
		}
		if (best < last) return -1;
		last = best + 1, i = k, ++ans;
		if (last > t) return ans;
	}
	return last > t ? ans : -1;
}

int main() {
	printf("%d\n", work());

	fclose(stdin);
	fclose(stdout);
	return 0;
}
