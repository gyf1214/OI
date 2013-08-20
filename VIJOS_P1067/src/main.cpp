/*
 * main.cpp
 *
 *  Created on: 2013-8-20
 *      Author: gyf
 */

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define clr(i, a) memset(i, a, sizeof(i))
#define max(a, b) (a)>(b)?(a):(b)
#define min(a, b) (a)<(b)?(a):(b)
#define infi 0x7FFFFFFF
#define mm 12

struct matrix
{
	long long a[mm][mm];
	int n, m;
	matrix()
	{
		clr(a, 0);
		n = m = 0;
	}
	matrix(int n, int m)
	{
		clr(a, 0);
		this->n = n;
		this->m = m;
	}
	long long* operator [](int index)
	{
		return a[index];
	}
	matrix operator +(matrix other)
	{
		matrix ret(n, m);
		rep(i, 1, n)
			rep(j, 1, m)
				ret[i][j] = ((*this)[i][j] + other[i][j]) % 7777777;
		return ret;
	}
	matrix operator *(matrix other)
	{
		matrix ret(n, other.m);
		rep(i, 1, n)
			rep(j, 1, other.m)
				rep(k, 1, m)
					ret[i][j] = (ret[i][j] + (*this)[i][k] * other[k][j]) % 7777777;
		return ret;
	}
	matrix operator ^(int index)
	{
		matrix ret(n, n);
		matrix k(n, n);
		rep(i, 1, n)
			rep(j, 1, n)
				k[i][j] = (*this)[i][j];
		rep(i, 1, n)
			ret[i][i] = 1;
		while (index > 0)
		{
			if (index % 2 == 1)
				ret = ret * k;
			k = k * k;
			index /= 2;
		}
		return ret;
	}
};

matrix ans, t;
int n, k;

int work()
{
	t.n = t.m = k;
	rep(i, 1, k)
		t[1][i] = 1;
	rep(i, 2, k)
		t[i][i - 1] = 1;
	ans.n = k;
	ans.m = 1;
	rep(i, 1, k - 1)
		ans[i][1] = 1 << (k - i - 1);
	ans[k][1] = 1;
	if (k > n)
	{
		return ans[k - n][1];
	} else {
		t = t ^ (n - k + 1);
		ans = t * ans;
		return ans[1][1] % 7777777;
	}
}

int main()
{
	scanf("%d%d", &k, &n);
	printf("%d\n", work());

	fclose(stdin);
	fclose(stdout);
	return 0;
}
