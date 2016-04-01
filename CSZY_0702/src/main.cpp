//Created At: Fri Apr 1 14:01:10 CST 2016
//orz zyx
//ntr czr
//Author: gyf

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define clr(i, a) memset(i, (a), sizeof(i))
#define infi 0x7FFFFFFF
#define mm 100010
using namespace std;

char str[50];
priority_queue<double, vector<double>, greater<double> > pq;
double s[mm];
int top, n;

void init() {
	scanf("%d", &n);
	rep(i, 1, n) {
		double x;
		scanf("%lf", &x);
		pq.push(x);
	}
	top = 0;
}

bool run() {
	if (scanf("%s", str) == EOF) return false;
	double x;
	if (sscanf(str, "%lf", &x) > 0) {
		s[top++] = x;
	} else {
		--top;
		switch (str[0]) {
			case '+':
			s[top - 1] += s[top];
			break;
			case '-':
			s[top - 1] -= s[top];
			break;
			case '*':
			s[top - 1] *= s[top];
			break;
			case '/':
			s[top - 1] /= s[top];
			break;
			case '^':
			s[top - 1] = pow(s[top - 1], s[top]);
			break;
			case '=':
			printf("%e\n", s[top]);
			pq.pop();
			pq.push(s[top]);
			break;
		}
	}
	return true;
}

void print() {
	rep(i, 0, n - 1) {
		printf("%c%e", i % 10 == 0 ? '\n' : ' ', pq.top());
		pq.pop();
	}
	printf("\n");
}

int main() {
	init();
	while (run());
	print();

	fclose(stdin);
	fclose(stdout);
	return 0;
}
