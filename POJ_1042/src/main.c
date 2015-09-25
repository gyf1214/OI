#include <stdio.h>
#include <string.h>
#define mm 35
#define clr(i, x) memset(i, x, sizeof(i))

struct Ans {
    int num[mm];
    int ans;
}ans[mm];

int h[mm], hi[mm], hn;
int n, time, t[mm], d[mm], f[mm];


void _swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap(int x, int y) {
    _swap(&h[x], &h[y]);
    _swap(&hi[x], &hi[y]);
}

int cmp(int x, int y) {
    return (h[x] > h[y]) || (h[x] == h[y] && hi[x] < hi[y]);
}

void up(int x) {
    int y = x / 2;
    if (y > 0 && cmp(x, y)) {
        swap(x, y);
        up(y);
    }
}

void down(int x) {
    int y = 2 * x;
    if (y < hn && cmp(y + 1, y)) {
        ++y;
    }
    if (y <= hn && cmp(y, x)) {
        swap(x, y);
        down(y);
    }
}

void push(int x) {
    hi[++hn] = x;
    h[hn] = f[x];
    up(hn);
}

void work(int k) {
    int x = time;
    int i;
    for (i = 0; i < k - 1; ++i) {
        x -= t[i];
    }
    hn = 0;
    for (i = 0; i < k; ++i) {
        push(i);
    }
    for (; x > 0; --x) {
        ans[k - 1].ans += h[1];
        ++ans[k - 1].num[hi[1]];
        h[1] -= d[hi[1]];
        if (h[1] < 0) h[1] = 0;
        down(1);
    }
}

void print() {
    int best = 0, i;
    for (i = 1; i < n; ++i) {
        if (ans[i].ans > ans[best].ans) {
            best = i;
        }
    }
    for (i = 0; i < n; ++i) {
        printf("%d%s", ans[best].num[i] * 5, i == n - 1 ? "\n" : ", ");
    }
    printf("Number of fish expected: %d\n", ans[best].ans);
}

int pre(int x) {
    clr(ans, 0);
    scanf("%d", &n);
    if (n == 0) return 0;
    if (x) printf("\n");
    scanf("%d", &time);
    time *= 12;
    int i;
    for (i = 0; i < n; ++i) {
        scanf("%d", f + i);
    }
    for (i = 0; i < n; ++i) {
        scanf("%d", d + i);
    }
    for (i = 0; i < n - 1; ++i) {
        scanf("%d", t + i);
    }
    for (i = 0; i < n; ++i) {
        work(i + 1);
    }
    print();
    return 1;
}

int main() {
    pre(0);
    while(pre(1));

    fclose(stdin);
    fclose(stdout);
    return 0;
}
