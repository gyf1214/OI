//Created At: Thu Dec 10 10:37:26 CST 2015
//orz zyx
//ntr czr
//Author: gyf

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define clr(i, a) memset(i, (a), sizeof(i))
#define infi 0x7FFFFFFF
#define inf 1e500
#define eps 1e-8
#define mm 50
using namespace std;

struct Vector {
	double x, y;
	Vector() {}
	Vector(double x, double y) : x(x), y(y) {}
	Vector operator +(Vector other) {
		return Vector(x + other.x, y + other.y);
	}
	Vector operator -(Vector other) {
		return Vector(x - other.x, y - other.y);
	}
	Vector operator *(double k) {
		return Vector(k * x, k * y);
	}
	double operator *(Vector other) {
		return x * other.x + y * other.y;
	}
	double abs2() {
		return x * x + y * y;
	}
	double abs() {
		return sqrt(this -> abs2());
	}
	Vector normalize() {
		return (*this) * (1 / this -> abs());
	}
};

struct Circle {
	Vector c;
	double r;
}circle[mm];

int n, t = 0;
Vector st, dir;

int cmp(double x) {
	return abs(x) <= eps ? 0 : (x > eps ? 1 : -1);
}

double interact(Vector a, Vector norm, Circle b) {
	Vector pos = b.c - a;
	double proj = pos * norm;
	if (cmp(proj) <= 0) return inf;
	double dist2 = pos.abs2() - proj * proj;
	double radi2 = b.r * b.r - dist2;
	if (cmp(radi2) <= 0) return inf;
	return proj - sqrt(radi2);
}

Vector reflact(Vector norm, Vector norm2) {
	return norm - norm2 * (2 * (norm * norm2));
}

void work(Vector a, Vector norm, int depth) {
	//printf("%lf %lf\n", a.x, a.y);
	if (depth > 9) {
		printf("...\n\n");
		return;
	}
 	double best = inf;
	int k;
	rep(i, 0, n - 1) {
		double x = interact(a, norm, circle[i]);
		if (x < best) {
			best = x;
			k = i;
		}
	}
	if (best < inf) {
		printf("%d ", k + 1);
		Vector b = a + norm * best;
		Vector norm2 = (b - circle[k].c).normalize();
		work(b, reflact(norm, norm2), depth + 1);
	} else {
		printf("inf\n\n");
		return;
	}
}

bool pre() {
	scanf("%d", &n);
	if (n == 0) return false;
	rep(i, 0, n - 1) {
		scanf("%lf%lf%lf", &circle[i].c.x, &circle[i].c.y, &circle[i].r);
	}
	scanf("%lf%lf%lf%lf", &st.x, &st.y, &dir.x, &dir.y);
	printf("Scene %d\n", ++t);
	return true;
}

int main() {
	while (pre()) work(st, dir.normalize(), 0);

	fclose(stdin);
	fclose(stdout);
	return 0;
}
