//Created At: Wed Sep 9 09:55:38 CST 2015
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
#define mm
using namespace std;

char str[1000000];

int work() {
	int len = strlen(str);
	for (char *st = str, *ed = str + len - 1; st < ed; st++, ed--) {
		if (*st != *ed) {
			return 0;
		}
	}
	return 1;
}

int main() {
	scanf("%s", str);
	printf("%d\n", work());

	fclose(stdin);
	fclose(stdout);
	return 0;
}
