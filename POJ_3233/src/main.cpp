/*
 * main.cpp
 *
 *  Created on: Feb 24, 2014
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
#define mm 100
using namespace std;

int mod;

struct matrix
{
	int data[mm][mm];
	int n, m;

	matrix()
	{
		n = 0, m = 0;
		clr(data, 0);
	}

	matrix(int n, int m): n(n), m(m)
	{
		clr(data, 0);
	}

	int* operator[](int index)
	{
		return data[index];
	}

	matrix operator*(matrix& other)
	{
		matrix ret(n, other.m);
		rep(i, 1, n)
			rep(j, 1, other.m)
				rep(k, 1, m)
					ret[i][j] = (ret[i][j] + (*this)[i][k] * other[k][j] % mod) % mod;
		return ret;
	}

	matrix operator^(int k)
	{
		matrix ret(n, n);
		rep(i, 1, n)
			ret[i][i] = 1;
		matrix p = *this;
		for (; k; k /= 2)
		{
			if (k % 2 == 1) ret = ret * p;
			p = p * p;
		}
		return ret;
	}
}a, ans;

int n, k;

int main()
{
	scanf("%d%d%d", &n, &k, &mod);
	rep(i, 1, n)
		rep(j, 1, n)
			scanf("%d", &a[i][j]);
	a.n = a.m = 2 * n;
	rep(i, 1, n)
		a[i + n][i] = a[i + n][i + n] = 1;
	a = a ^ (k + 1);
	ans.n = 2 * n;
	ans.m = n;
	rep(i, 1, n)
		ans[i][i] = 1;
	ans = a * ans;
	rep(i, 1, n)
	{
		rep(j, 1, n)
		{
			int t = ans[i + n][j];
			if (i == j)
				t = (t + mod - 1) % mod;
			printf("%d ", t);
		}
		printf("\n");
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}




