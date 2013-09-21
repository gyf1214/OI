#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#define rep(i, a,  b) for (int i = a; i <= b; ++i)
#define clr(i, a) memset(i, a, sizeof(i))
#define max(a, b) (a)>(b)?(a):(b)
#define min(a, b) (a)<(b)?(a):(b)
#define infi 0x7FFFFFFF
#define mm 2000
using namespace std;

int x[mm],n;
int l[mm], l0[mm], r[mm], r0[mm], s;

void pre()
{
	int k;
	scanf("%d%d", &n, &k);
	rep(i, 1, n)
		scanf("%d", x + i);
	x[0] = k;
	sort(x, x + n + 1);
	rep(i, 0, n)
		if (x[i] == k)
		{
			s = i;
			break;
		}
}

inline bool in(int i)
{
	return i >= 0 && i <= n;
}

int work()
{
	rep(i, 0, n)
	{
		l0[i] = infi / 3;
		r0[i] = infi / 3;
	}
	l0[s] = r0[s] = 0;
	rep(i, 1, n)
	{
		rep(j, 0, n)
		{
			l[j] = infi / 3;
			r[j] = infi / 3;
		}
		rep(j, 0, n)
		{
			if (in(j - 1)) l[j - 1] = min(l[j - 1], l0[j] + (x[j] - x[j - 1]) * (n - i + 1));
			if (in(j + i)) r[i + j] = min(r[i + j], l0[j] + (x[i + j] - x[j]) * (n - i + 1));
			if (in(j + 1)) r[j + 1] = min(r[j + 1], r0[j] + (x[j + 1] - x[j]) * (n - i + 1));
			if (in(j - i)) l[j - i] = min(l[j - i], r0[j] + (x[j] - x[j - i]) * (n - i + 1));
		}
		rep(j, 0, n)
		{
			l0[j] = l[j];
			r0[j] = r[j];
		}
	}
	return min(l[0], l[n]);
}

int main()
{
	//freopen("ontherun.in", "r", stdin);
	//freopen("ontherun.out", "w", stdout);

	pre();
	printf("%d\n", work());

	fclose(stdin);
	fclose(stdout);
	return 0;
}

