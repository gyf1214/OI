//Created At: Tue Jul 15 16:53:41 CST 2014
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
#define infi 0x7FFFFFFFFFFFFFFFLL
#define mm 400010
using namespace std;

long long x[mm], y[mm];
int n;

void work()
{
	int m;
	char buffer[10];
	scanf("%d%s", &m, buffer);
	n = 0;
	rep(i, 1, m)
	{
		int l, r;
		long long a, b;
		scanf("%s", buffer);
		if (buffer[0] == 'A')
		{
			++n;
			scanf("%lld%lld", &x[n], &y[n]);
		} else {
			long long ans = -infi;
			scanf("%lld%lld%d%d", &a, &b, &l, &r);
			rep(i, l, r)
				ans = max(ans, a * x[i] + b * y[i]);
			printf("%lld\n", ans);
		}
	}
}

int main()
{
	work();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

