//Created At: Fri Nov 20 10:43:27 CST 2015
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
#define mm 9
using namespace std;

const int c[mm][mm] = {
	{ 3, 2, 3, 2, 2, 1, 3, 1, 0 },
	{ 3, 3, 3, 3, 3, 3, 2, 0, 2 },
	{ 3, 2, 3, 1, 2, 2, 0, 1, 3 },
	{ 3, 3, 2, 3, 3, 0, 3, 3, 2 },
	{ 3, 2, 3, 2, 1, 2, 3, 2, 3 },
	{ 2, 3, 3, 0, 3, 3, 2, 3, 3 },
	{ 3, 1, 0, 2, 2, 1, 3, 2, 3 },
	{ 2, 0, 2, 3, 3, 3, 3, 3, 3 },
	{ 0, 1, 3, 1, 2, 2, 3, 2, 3 }
};

int y[mm], x[mm];

void work() {
	rep(i, 0, mm - 1) scanf("%d", y + i);
	rep(i, 0, mm - 1) y[i] = (4 - y[i]) % 4;
	rep(i, 0, mm - 1) {
		x[i] = 0;
		rep(j, 0, mm - 1) {
			x[i] += c[i][j] * y[j];
		}
		x[i] = (x[i] + 4) % 4;
	}
	rep(i, 0, mm - 1) {
		rep(j, 0, x[i] - 1) {
			printf("%d%c", i + 1, i == mm - 1 && j == x[i] - 1 ? '\n' : ' ');
		}
	}
}

int main() {
	work();

	fclose(stdin);
	fclose(stdout);
	return 0;
}
