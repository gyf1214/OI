//Created At: Tue Jul 15 17:05:08 CST 2014
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
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))
#define infi 0x7FFFFFFF
#define mm 100000000
using namespace std;

int random(int l, int r)
{
	return rand() % (r - l) + l;
}

int main()
{
	srand(911);
	int n = 200000;
	printf("%d E\n", n * 2);
	rep(i, 1, n)
		printf("A %d %d\n", random(-mm, mm), random(-mm, mm));
	rep(i, 1, n)
	{
		int l = random(1, n + 1);
		int r = random(1, n + 1);
		if (r < l) swap(l, r);
		printf("Q %d %d %d %d\n", random(-mm, mm), random(-mm, mm), l, r);
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}

