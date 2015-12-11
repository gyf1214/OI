//Created At: Fri Dec 11 15:36:13 CST 2015
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
#define abs(x) ((x) > 0 ? (x) : (-(x)))
#define mm 300
using namespace std;

char a[mm], b[mm], c[mm];
int n;

void getline2(char *a) {
	char ch;
	while ((ch = getchar()) != '\n') {
		*a++ = ch;
	}
	*a = 0;
}

int main() {
	scanf("%d", &n);
	getline2(c);
	rep(i, 1, n) {
		getline2(a), getline2(b);
		if (i != n) getline2(c);
		char *ch1, *ch2;
		for (ch1 = a, ch2 = b; *ch1 && *ch2; ++ch1, ++ch2) {
			while (*ch1 == ' ') ++ch1;
			while (*ch2 == ' ') ++ch2;
			if (*ch1 != *ch2 && abs(*ch1 - *ch2) != 'a' - 'A') {
				break;
			}
		}
		while (*ch1 == ' ') ++ch1;
		while (*ch2 == ' ') ++ch2;
		printf("%s\n", *ch1 || *ch2 ? "NO" : "YES");
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
