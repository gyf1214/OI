#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define clr(i, a) memset(i, a, sizeof(a))
#define max(a, b) (a)>(b)?(a):(b)
#define min(a, b) (a)<(b)?(a):(b)
#define infi 0x7FFFFFFF
#define mm 40000
using namespace std;

int p[mm], s[mm], l[mm];

int find(int i)
{
	if (p[i] != i)
	{
		int t = find(p[i]);
		l[i] += l[p[i]];
		p[i] = t;
	}
	return p[i];
}

void merge(int i, int j)
{
	i = find(i);
	j = find(j);
	p[i] = j;
	l[i] = s[j];
	s[j] += s[i];
}

int main()
{
	freopen("cubes.in", "r", stdin);
	freopen("cubes.out", "w", stdout);

	rep(i, 1, mm-1)
	{
		p[i] = i;
		l[i] = 0;
		s[i] = 1;
	}

	int n;
	scanf("%d", &n);
	rep(i, 1, n)
	{
		fflush(stdin);
		getchar();
		getchar();
		char ch;
		scanf("%c", &ch);
		if (ch == 'C')
		{
			int x;
			scanf("%d", &x);
			find(x);
			printf("%d\n", l[x]);
		}
		else
		{
			int x, y;
			scanf("%d%d", &x, &y);
			merge(x, y);
		}
	}
	return 0;
}
