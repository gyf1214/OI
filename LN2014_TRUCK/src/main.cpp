//Created At: Mon Jul 21 19:09:13 CST 2014
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
#define infi 0x7FFFFFFF
#define mm 500010
#define km 30
using namespace std;

struct Edge
{
	int u, v, x;
	double l;
	Edge* next;
}edge[mm * 2], *next_edge = edge, *head[mm], *circle;

typedef pair<double, double> pdd;

struct Node
{
	int l, r;
	double sum, val;
	Node* ch[2];

	Node* update(int, double, double);
	pdd query(int, int);
}node[mm * km], *next_node = node, *root[mm];

int n, m, nq;
double w[mm], v[mm];
int p[mm][km];
int q[mm], d[mm];

Node* new_node(int l, int r, double s, double v)
{
	Node* ret = next_node++;
	ret -> l = l;
	ret -> r = r;
	ret -> sum = s;
	ret -> val = v;
	return ret;
}

Node* Node::update(int k, double v, double w)
{
	Node* ret = new_node(l, r, sum + v, val + w);
	ret -> ch[0] = ch[0];
	ret -> ch[1] = ch[1];
	if (l == r) return ret;
	int m = (l + r) / 2;
	if (k <= m)
		ret -> ch[0] = ch[0] -> update(k, v, w);
	else
		ret -> ch[1] = ch[1] -> update(k, v, w);
	return ret;
}

pdd Node::query(int l, int r)
{
	if (l > r) return make_pair(.0, .0);
	if (this -> l >= l && this -> r <= r)
		return make_pair(sum, val);
	pdd ret = make_pair(.0, .0), ans;
	int m = (this -> l + this -> r) / 2;
	if (l <= m)
	{
		ans = ch[0] -> query(l, r);
		ret.first += ans.first;
		ret.second += ans.second;
	}
	if (r > m)
	{
		ans = ch[1] -> query(l, r);
		ret.first += ans.first;
		ret.second += ans.second;
	}
	return ret;
}

Node* build(int l, int r)
{
	Node* ret = new_node(l, r, .0, .0);
	if (l != r)
	{
		int m = (l + r) / 2;
		ret -> ch[0] = build(l, m);
		ret -> ch[1] = build(m + 1, r);
	}
	return ret;
}

void ins(int u, int v, double l, int x)
{
	Edge* ret = next_edge++;
	ret -> u = u;
	ret -> v = v;
	ret -> x = x;
	ret -> l = l;
	ret -> next = head[u];
	head[u] = ret;
}

void pre()
{
	scanf("%d%d%d", &n, &m, &nq);
	int s, t, x;
	double y;
	rep(i, 1, n)
	{
		scanf("%d%d%lf%d", &s, &t, &y, &x);
		ins(s, t, y, x);
		ins(t, s, y, x);
	}
	rep(i, 1, m)
		scanf("%lf%lf", &v[i], &w[i]);
	int l = 0, r = 0;
	q[r++] = 1;
	root[1] = build(1, m);
	while (r > l)
	{
		int u = q[l++];
		for (Edge* e = head[u]; e; e = e -> next)
			if (!root[e -> v])
			{
				p[e -> v][0] = u;
				root[e -> v] = root[u] -> update(e -> x, e -> l * w[e -> x], e -> l * w[e -> x] / v[e -> x]);
				d[e -> v] = d[u] + 1;
				q[r++] = e -> v;
			} else if (p[u][0] != e -> v)
				circle = e;
	}
	rep(j, 1, km - 1)
		rep(i, 1, n)
			p[i][j] = p[p[i][j - 1]][j - 1];
	v[0] = -infi;
}

int go(int u, int d)
{
	int t = 0;
	while (d)
	{
		if (d % 2 == 1) u = p[u][t];
		++t;
		d /= 2;
	}
	return u;
}

int lca(int u, int v)
{
	if (d[v] > d[u]) swap(u, v);
	u = go(u, d[u] - d[v]);
	if (u == v) return u;
	for (int i = km - 1; i >= 0; --i)
		if (p[u][i] != p[v][i])
		{
			u = p[u][i];
			v = p[v][i];
		}
	return p[u][0];
}

double __query(int u, int l, double k)
{
	return root[u] -> query(1, l).first / k + root[u] -> query(l + 1, m).second;
}

double _query(int s, int t, int l, double k)
{
	int m = lca(s, t);
	return __query(s, l, k) + __query(t, l, k) - 2 * __query(m, l, k);
}

double query(int s, int t, double k)
{
	int l = 0, r = m + 1;
	while (r - l > 1)
	{
		int m = (l + r) / 2;
		if (v[m] >= k)
			l = m;
		else
			r = m;
	}
	double road = circle -> l * w[circle -> x] / min(v[circle -> x], k);
	double a1 = _query(s, t, l, k);
	double a2 = _query(s, circle -> u, l, k) + _query(circle -> v, t, l, k) + road;
	double a3 = _query(s, circle -> v, l, k) + _query(circle -> u, t, l, k) + road;
	return min(a1, min(a2, a3));
}

void work()
{
	rep(i, 1, nq)
	{
		int u, v;
		double k;
		scanf("%d%d%lf", &u, &v, &k);
		printf("%.10lf\n", query(u, v, k));
	}
}

int main()
{
	freopen("truck.in", "r", stdin);
	freopen("truck.out", "w", stdout);
	pre();
	work();

	fclose(stdin);
	fclose(stdout);
	return 0;
}

