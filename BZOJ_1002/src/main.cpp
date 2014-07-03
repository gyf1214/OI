//Created At: Thu Jul 3 17:24:54 CST 2014
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
#define min(a, b) ((a)>(b)?(a):(b))
#define infi 0x7FFFFFFF
#define mm
using namespace std;

int n;
int a[100][100];

int gcd(int x, int y)
{
	x = abs(x);
	y = abs(y);
	while (y != 0)
	{
		x = x % y;
		if (x < y)
			swap(x, y);
	}
	return x;
}

void relax(int& x, int& y)
{
	int z = gcd(x, y);
	x /= z;
	y /= z;
}

int gauss(int n)
{
	int k = 0;
	int det = 1, ans = 1;
	for (int j = 0; j < n && k < n; ++j, ++k)
	{
		int best = k;
		rep(i, k + 1, n - 1)
			if (abs(a[i][j]) > abs(a[best][j]))
				best = i;
		rep(i, 0, n)
			swap(a[k][i], a[best][i]);
		if (a[k][j] == 0)
			continue;
		else {
			ans *= a[k][j];
			relax(ans, det);
			rep(i, k + 1, n - 1)
				if (a[i][j] != 0)
				{
					det *= a[k][j];
					relax(ans, det);
					int la = a[k][j];
					int lb = a[i][j];
					relax(la, lb);
					rep(t, j + 1, n)
					{
						a[i][t] = a[i][t] * a[k][j] - a[k][t] * a[i][j];
					}
					a[i][j] = 0;
				}
		}
	}
	printf("%d %d\n", ans, det);
	return ans / det;
}

int main()
{
	scanf("%d", &n);
	int ans;
	if (n == 1)
	{
		ans = 1;
	} else if (n == 2)
	{
		ans = 5;
	} else {
		clr(a, 0);
		rep(i, 0, n - 1)
		{
			a[i][i] = 3;
			a[i][(i + 1) % n] = -1;
			a[i][(i + n - 1) % n] = -1;
		}
		ans = abs(gauss(n));
	}
	printf("%d\n", ans);

	fclose(stdin);
	fclose(stdout);
	return 0;
}

