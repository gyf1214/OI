//Created At: Wed Sep 23 12:56:54 CST 2015
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
#define mm 1010
using namespace std;

typedef pair<int, int> pii;

pii f[mm * mm];
int a[mm], n, m;

bool work() {
	scanf("%d", &n);
	if (n == 0) return false;
	rep(i, 0, n - 1) {
		scanf("%d", a + i);
	}
	sort(a, a + n);
	m = 0;
	rep(i, 0, n - 1) {
		rep(j, i + 1, n - 1) {
			f[m++] = make_pair(a[i] + a[j], a[i]);
		}
	}
	sort(f, f + m);
	int ans = -infi;
	rep(i, 0, n - 1) {
		rep(j, 0, n - 1) {
			if (i != j) {
				pii *now =lower_bound(f, f + m, make_pair(a[i] - a[j], -infi));
				while (now - f < m && now -> first == a[i] - a[j]) {
					if (a[i] != now -> second && a[j] != now -> second
					&& a[i] != now -> first - now -> second
					&& a[j] != now -> first - now -> second) {
						ans = max(ans, a[i]);
						break;
					}
					++now;
				}
			}
		}
	}
	if (ans == -infi) {
		printf("no solution\n");
	} else {
		printf("%d\n", ans);
	}
	return true;
}

int main() {
	while (work());

	fclose(stdin);
	fclose(stdout);
	return 0;
}
