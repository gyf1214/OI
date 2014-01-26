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
#define mm 33
using namespace std;

int k, g;
int f[mm][mm];
struct binnum
{
	bool data[mm];
	int length;
	binnum()
	{
		length = 0;
		clr(data, 0);
	}
	int calc(int t)
	{
		if (length < 0)
			return 0;
		if (t == 0)
			return length > 0 ? 1 : 0;
		int ans = 0;
		int k = 0;
		for (int i = length - 1; i >= 0; --i)
			if (data[i])
			{
				if (t >= k)
					ans += f[i][t - k];
				++k;
			}
		return ans;
	}
	bool& operator [](int index)
	{
		return data[index];
	}
	void init(char * str)
	{
		length = strlen(str);
		if (length == 1 && (*str) == '0')
			length = 0;
		rep(i, 0, length - 1)
			data[length - i - 1] = str[i] == '1';
	}
	void inc()
	{
		int i;
		for (i = 0; data[i]; ++i)
			data[i] = false;
		data[i] = true;
		if (data[length])
			++length;
	}
}a, b, c;
char str[mm];

void pre()
{
	scanf("%s", str);
	a.init(str);
	scanf("%s", str);
	b.init(str);
	scanf("%d", &k);
	clr(f, 0);
	f[0][0] = 1;
	rep(i, 1, mm - 1)
	{
		f[i][0] = 1;
		rep(j, 1, i)
			f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
	}
	b.inc();
	for (g = 0; true; ++g)
	{
		int t = b.calc(g) - a.calc(g);
		if (t >= k)
			break;
		k -= t;
	}
	k += a.calc(g);
}

void work()
{
	int t = g;
	for (int i = mm - 1; i >= 0; --i)
	{
		if (t <= 0)
			break;
		if (f[i][t] < k)
		{
			k -= f[i][t];
			c[i] = true;
			--t;
		}
	}
	bool flag = false;
	for (int i = mm - 1; i >= 0; --i)
	{
		if (flag)
		{
			printf("%d", c[i] ? 1 : 0);
		} else {
			if (c[i])
			{
				printf("1");
				flag = true;
			}
		}
	}
	if (!flag)
		printf("0");
	printf("\n");
}

int main()
{
	freopen("cowq.in", "r", stdin);
	freopen("cowq.out", "w", stdout);

	pre();
	work();

	fclose(stdin);
	fclose(stdout);
	return 0;
}
