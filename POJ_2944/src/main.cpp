//Created At: Fri Sep 11 15:59:01 CST 2015
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
#define mm 210
using namespace std;

char str[mm][mm], a[mm], b[mm];

bool getstr(char* buf) {
	int ch = getchar();
	while (ch != ' ' && ch != '\n') {
		*(buf++) = ch;
		ch = getchar();
	}
	*buf = 0;
	return ch == ' ';
}

void work() {
	int len = 0;
	while (getstr(str[len++]));
	getstr(a), getstr(b);
	rep(i, 0, len - 1) {
		if (strcmp(str[i], a) == 0) {
			printf("%s", b);
		} else {
			printf("%s", str[i]);
		}
		printf("%c", i == len - 1 ? '\n' : ' ');
	}
}

int main() {
	work();

	fclose(stdin);
	fclose(stdout);
	return 0;
}
