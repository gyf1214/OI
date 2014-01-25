/*
 * main.cpp
 *
 *  Created on: Jan 25, 2014
 *      Author: gyf
 */

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
#define mm 2000
#define nn 20
#define base 10000
using namespace std;

struct bignum
{
	int length;
	int data[nn];
	bignum()
	{
		length = 0;
		clr(data, 0);
	}
	void init(int i)
	{
		for (; i; i /= base)
			data[length++] = i % base;
	}
	void print()
	{
		if (length == 0)
		{
			printf("0");
		} else {
			int i = length - 1;
			printf("%d", data[i]);
			for (--i; i >= 0; --i)
				printf("%04d", data[i]);
		}
	}
	int& operator [](int index)
	{
		return data[index];
	}
	bignum operator +(bignum other)
	{
		bignum ret = *this;
		rep(i, 0, other.length)
		{
			ret[i] += other[i];
			ret[i + 1] += ret[i] / base;
			ret[i] %= base;
		}
		for (; ret[ret.length]; ++ret.length);
		return ret;
	}
};

int n, k;
bignum f[mm][mm];

void work()
{
	rep(i, 1, k)
		f[0][i].init(1);
	rep(i, 1, n)
		rep(j, 1, k)
		{
			f[i][j] = f[i][j - 1];
			if (i >= j)
				f[i][j] = f[i][j] + f[i - j][j];
		}
}

int main()
{
	freopen("ddayz.in", "r", stdin);
	freopen("ddayz.out", "w", stdout);

	scanf("%d%d", &n, &k);
	work();
	f[n][k].print();
	printf("\n");

	fclose(stdin);
	fclose(stdout);
	return 0;
}


