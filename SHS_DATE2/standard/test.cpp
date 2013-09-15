#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <ctime>
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define clr(i, a) memset(i, a, sizeof(i))
#define rnd(i) ((rand() % (i)) + 1)

bool vis[10010][10010];

int main(int argc, char** argv)
{
	srand(argv[1][0] + argv[1][1]);
	clr(vis, 0);
	int n = rnd(10000);
	int m;
	if (n * (n - 1) / 2 > 50000)
		m = rnd(50000);
	else
		m = rnd(n * (n - 1) / 2);
	printf("%d %d\n", n, m);
	rep(i, 1, m)
	{
		int x, y;
		do
		{
			x = rnd(n);
			y = rnd(n);
		} while (vis[x][y]);
		vis[x][y] = true;
		printf("%d %d\n", x, y);
	}

	return 0;
}
