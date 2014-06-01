/*
 * main.cpp
 *
 *  Created on: Jun 1, 2014
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
#define mm 200
using namespace std;

char str[mm];
bool vis[256];

int main()
{
	clr(vis, 0);
	gets(str);
	int n = strlen(str);
	rep(i, 0, n - 1)
		vis[str[i]] = true;
	int ans = 0;
	rep(i, 'a', 'z')
		ans += vis[i] ? 1 : 0;
	printf("%s\n", ans % 2 == 0 ? "CHAT WITH HER!" : "IGNORE HIM!");

	fclose(stdin);
	fclose(stdout);
	return 0;
}


