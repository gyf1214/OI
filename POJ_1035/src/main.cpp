//Created At: Fri Oct 16 07:09:57 CST 2015
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
#define mm 11000
using namespace std;

char dic[mm][20];
int n;

bool match(char *a, char *b, bool c) {
	int l1 = strlen(a), l2 = strlen(b);
	if (l1 > l2) swap(a, b);
	if (abs(l2 - l1) > 1) return false;
	if (l1 == l2) {
		for (; *a; ++a, ++b) {
			if (*a != *b) {
				if (!c) return false;
				c = false;
			}
		}
	} else {
		for (; *b; ++a, ++b) {
			if (*a != *b) {
				if (!c) return false;
				--a;
				c = false;
			}
		}
	}
	return true;
}

void pre() {
	for (scanf("%s", dic[n++]); dic[n - 1][0] != '#'; scanf("%s", dic[n++]));
	--n;
}

void work() {
	char str[20];
	for (scanf("%s", str); str[0] != '#'; scanf("%s", str)) {
		bool flag = false;
		rep(i, 0, n - 1) {
			if (match(str, dic[i], false)) {
				printf("%s is correct\n", str);
				flag = true;
				break;
			}
		}
		if (!flag) {
			printf("%s:", str);
			rep(i, 0, n - 1) {
				if (match(str, dic[i], true)) {
					printf(" %s", dic[i]);
				}
			}
			printf("\n");
		}
	}
}

int main() {
	pre();
	work();

	fclose(stdin);
	fclose(stdout);
	return 0;
}
