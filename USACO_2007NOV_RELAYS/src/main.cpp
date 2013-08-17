/*
 * main.cpp
 *
 *  Created on: 2013-8-4
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
#define mm 310
#define nm 1010
using namespace std;

struct matrix
{
	int n, m;
	int map[mm][mm];
	inline int* operator [](int index)
	{
		return map[index];
	}
	matrix()
	{
		n = m = 0;
		clr(map, 0);
	}
	matrix operator * (matrix other)
	{
		matrix ret;
		ret.n = n;
		ret.m = other.m;
		rep(i, 1, n)
			rep(j, 1, other.m)
				ret[i][j] = infi;
		rep(i, 1, n)
			rep(j, 1, other.m)
				rep(k, 1, m)
					ret[i][j] =min(ret[i][j], (*this)[i][k] + other[k][j]);
		return ret;
	}
	matrix operator ^ (int k)
	{
		matrix ret;
		ret.n = ret.m = n;
		rep(i, 1, n)
			rep(j, 1, n)
				ret[i][j] = infi / 3;
		rep(i, 1, n)
			ret[i][i] = 0;
		matrix t = *this;
		while (k > 0)
		{
			if (k % 2 == 1)
				ret = ret * t;
			t = t * t;
			k /= 2;
		}
		return ret;
	}
}mat;

int map[mm], nn, s, e, n;

inline int get(int a)
{
	if (map[a] == 0)
		map[a] = ++nn;
	return map[a];
}

void pre()
{
	clr(map, 0);
	nn = 0;
	int m;
	scanf("%d%d%d%d", &n, &m, &s, &e);
	s = get(s);
	e = get(e);
	rep(i, 1, m)
	{
		int x, y, z;
		scanf("%d%d%d", &z, &x, &y);
		x = get(x);
		y = get(y);
		mat[x][y] = mat[y][x] = z;
	}
	mat.n = mat.m = nn;
	rep(i, 1, nn)
		rep(j, 1, nn)
			if (mat[i][j] == 0)
				mat[i][j] = infi / 3;
}

int main()
{
	freopen("relays.in", "r", stdin);
	freopen("relays.out", "w", stdout);

	pre();
	mat = mat ^ n;
	printf("%d\n", mat[s][e]);

	fclose(stdin);
	fclose(stdout);
	return 0;
}

