/*
 * main.cpp
 *
 *  Created on: Mar 23, 2014
 *      Author: gyf
 */

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define clr(i, a) clr(i, (a), sizeof(i))
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))
#define infi 0x7FFFFFFF
#define mm 3000010
using namespace std;

char str[mm], s[mm];
int p[mm];

int main()
{
	//freopen("a.in", "r", stdin);
	int t = 0;
	scanf("%s", str);
	while (str[0] != 'E')
	{
		++t;
		int len = strlen(str);
		rep(i, 0, len - 1)
		{
			s[2 * i + 1] = '#';
			s[2 * i + 2] = str[i];
		}
		s[0] = '$';
		s[2 * len + 1] = '#';
		s[2 * len + 2] = '\0';
		int best = 0, k = 0;
		rep(i, 0, 2 * len + 1)
		{
			if (best > i)
				p[i] = min(p[2 * k - i], best - i);
			else
				p[i] = 1;
			while (s[i + p[i]] == s[i - p[i]])
				++p[i];
			if (p[i] + i > best)
			{
				k = i;
				best = p[i] + i;
			}
		}
		int ans = 0;
		rep(i, 0, 2 * len + 1)
			ans = max(ans, p[i] - 1);
		printf("Case %d: %d\n", t, ans);
		scanf("%s", str);
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}


