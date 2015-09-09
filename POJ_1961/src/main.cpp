//Created At: Wed Sep 9 10:17:20 CST 2015
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
#define mm 1000010
using namespace std;

char str[mm];
int ne[mm], ans[mm];
int n;

void work() {
	ne[0] = ne[1] = 0;
	rep(i, 1, n - 1) {
		ne[i + 1] = 0;
		int j = i;
		while (j > 0) {
			j = ne[j];
			if (str[j] == str[i]) {
				ne[i + 1] = j + 1;
				break;
			}
		}
		if (ne[i + 1] > 0 && (i + 1) % (i + 1 - ne[i + 1]) == 0) {
			printf("%d %d\n", i + 1, (i + 1) / (i + 1 - ne[i + 1]));
		}
	}
	printf("\n");
}

int main() {
	int t = 1;
	for (;;) {
		scanf("%d", &n);
		if (n == 0) {
			break;
		}
		scanf("%s", str);
		printf("Test case #%d\n", t++);
		work();
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
