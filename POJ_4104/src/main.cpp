//Created At: Wed Sep 16 13:12:36 CST 2015
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
#define mm 600
using namespace std;

char str[mm], tmp[mm];

int main() {
	gets(str);
	int n = strlen(str);
	int j = 0;
	for (int i = 0; i < n; ++i) {
		if (str[i] == ' ') {
			for (--j; j >= 0; --j) {
				printf("%c", tmp[j]);
			}
			printf(" ");
			j = 0;
		} else {
			tmp[j++] = str[i];
		}
	}
	for (--j; j >= 0; --j) {
		printf("%c", tmp[j]);
	}
	printf("\n");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
