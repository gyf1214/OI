//Created At: Fri Jul 18 18:26:09 CST 2014
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
#define mm 10
using namespace std;

long long m;

long long mul(long long a, long long b)
{
	long long ans = 0;
	while (b)
	{
		if (b % 2 == 1) ans = (ans + a) % m;
		a = (a + a) % m;
		b /= 2;
	}
	return ans;
}

struct Matrix
{
	int n;
	long long a[mm][mm];
	
	Matrix()
	{
		n = 0;
		clr(a, 0);
	}

	Matrix(int n)
	{
		this -> n = n;
		clr(a, 0);
	}

	long long* operator [](int x)
	{
		return a[x];
	}

	Matrix operator *(Matrix other)
	{
		Matrix ret(n);
		rep(i, 1, n)
			rep(j, 1, n)
				rep(k, 1, n)
					ret[i][j] = (ret[i][j] + mul(a[i][k], other[k][j])) % m;
		return ret;
	}

	Matrix operator ^(long long p)
	{
		Matrix ret(n);
		Matrix t = *this;
		rep(i, 1, n)
			ret[i][i] = 1;
		while (p)
		{
			if (p % 2 == 1) ret = ret * t;
			t = t * t;
			p /= 2;
		}
		return ret;
	}
}ma(2);

int main()
{
	long long x, n, g;
	scanf("%lld%lld%lld%lld%lld%lld", &m, &ma[1][1], &ma[1][2], &x, &n, &g);
	ma[2][1] = 0;
	ma[2][2] = 1;
	ma = ma ^ n;
	long long ans = ((mul(ma[1][1], x) + ma[1][2]) % m) % g;
	printf("%lld\n", ans);

	fclose(stdin);
	fclose(stdout);
	return 0;
}

