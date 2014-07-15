//Created At: Tue Jul 15 16:20:17 CST 2014
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
#define infi 0x7FFFFFFFFFFFFFLL
#define mm 400010
#define km 500
#define nm 800
using namespace std;

long long ans;
long long x[mm], y[mm];
int n;
char magic;

struct Block
{
	int a[km];
	int q[km], l, r;
	
	void rebuild(int, int);
	void push(int);
	long long query(long long, long long);
}block[nm];

bool cmp(int i, int j)
{
	return x[i] < x[j];
}

void Block::push(int i)
{
	while (r > l + 1 &&
			(x[i] - x[q[r - 1]]) * (y[q[r - 1]] - y[q[r - 2]]) < 
			(x[q[r - 1]] - x[q[r - 2]]) * (y[i] - y[q[r - 1]]))
		--r;
	q[r++] = i;
}

void Block::rebuild(int s, int t)
{
	rep(i, s, t)
		a[i - s] = i;
	sort(a, a + t - s + 1, cmp);
	l = 0, r = 0;
	rep(i, 0, t - s)
		push(a[i]);
}

long long Block::query(long long a, long long b)
{
	int l = this -> l;
	int r = this -> r;
	while (r - l > 1)
	{
		int m = (l + r) / 2;
		if (m > l &&
			a * x[q[m]] + b * y[q[m]] > a * x[q[m - 1]] + b * y[q[m - 1]])
			l = m;
		else
			r = m;
	}
	return a * x[q[l]] + b * y[q[l]];
}

int decode()
{
	int x;
	scanf("%d", &x);
	if (magic == 'E') return x;
	return x ^ (ans & 0x7FFFFFFF);
}

void push()
{
	x[n] = decode();
	y[n] = decode();
	int k = n / km;
	block[k].rebuild(k * km, n);
	++n;
}

long long query()
{
	long long a = decode();
	long long b = decode();
	int l = decode() - 1;
	int r = decode() - 1;
	int lb = l / km, rb = r / km;
	long long ans = -infi;
	rep(i, lb + 1, rb - 1)
		ans = max(ans, block[i].query(a, b));
	rep(i, l, min(r, lb * km + km))
		ans = max(ans, a * x[i] + b * y[i]);
	rep(i, max(l, rb * km), r)
		ans = max(ans, a * x[i] + b * y[i]);
	return ans;
}

void work()
{
	int m;
	char buffer[10];
	scanf("%d%s", &m, buffer);
	magic = buffer[0];
	ans = 0;
	rep(i, 1, m)
	{
		scanf("%s", buffer);
		if (buffer[0] == 'A')
			push();
		else
		{
			ans = query();
			printf("%lld\n", ans);
		}
	}
}

int main()
{
	//freopen("input", "r", stdin);
	//freopen("output", "w", stdout);

	work();

	fclose(stdin);
	fclose(stdout);
	return 0;
}

