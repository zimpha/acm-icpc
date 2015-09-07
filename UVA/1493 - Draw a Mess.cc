#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 200 + 10;
const int MAXM = 50000 + 10;
const int MAXQ = 50000 + 10;

struct cmd {
	int x, y, w, c, l;
    char s;
};

cmd opt[MAXQ];
int f[MAXN][MAXM];
int Count[10];
int n, m, q;

void makeset(int n, int m) {
	for (int i = 0; i <= n; ++ i)
		for (int j = 0; j <= m; ++ j)
			f[i][j] = j;
}

int find(int r, int x) {
	if (x != f[r][x]) f[r][x] = find(r, f[r][x]);
	return f[r][x];
}

void paint(int x, int l, int r, int c) {
	l = find(x, l);
	while (l <= r) {
		Count[c] ++;
		f[x][l] = find(x, f[x][l + 1]);
		l = f[x][l];
	}
}

void Cir(int x, int y, int r, int c) {
	int lower = max(0, y - r), upper = min(y + r, m - 1);
	paint(x, lower, upper, c);
	for (int i = 1; i <= r; ++ i) {
		if (x + i >= n && x - i < 0) break;
		while ((y - lower) * (y - lower) + i * i > r * r) lower ++;
		while ((y - upper) * (y - upper) + i * i > r * r) upper --;
		if (x + i < n) paint(x + i, lower, upper, c);
		if (x - i >= 0) paint(x - i, lower, upper, c);
	}
}

void Dia(int x, int y, int r, int c) {
    int lower = max(0, y - r), upper = min(y + r, m - 1);
	paint(x, lower, upper, c);
	for (int i = 1; i <= r; ++ i) {
		if (x + i >= n && x - i < 0) break;
		while (y - lower + i > r) lower ++;
		while (upper - y + i > r) upper --;
		if (x + i < n) paint(x + i, lower, upper, c);
		if (x - i >= 0) paint(x - i, lower, upper, c);
	}
}

void Rec(int x, int y, int l, int w, int c) {
	for (int i = x; i < n && i < x + l; ++ i)
		paint(i, y, min(m - 1, y + w - 1), c);
}

void Tri(int x, int y, int w, int c) {
	for (w = w/2; x < n && w / 2 >= 0; ++ x, -- w) 
		paint(x, max(0, y - w), min(m - 1, y + w), c);
}

int main() {
	while (scanf("%d%d%d", &n, &m, &q) == 3) {
		memset(Count, 0, sizeof(Count));
		makeset(n, m);
		for (int i = 1; i <= q; ++ i) {
			char name[10];
			scanf("%s%d%d", name, &opt[i].x, &opt[i].y);
			opt[i].s = name[0];
			switch (opt[i].s) {
			case 'C' : scanf("%d%d", &opt[i].l, &opt[i].c); break;
			case 'D' : scanf("%d%d", &opt[i].l, &opt[i].c); break;
			case 'R' : scanf("%d%d%d", &opt[i].l, &opt[i].w, &opt[i].c); break;
			case 'T' : scanf("%d%d", &opt[i].w, &opt[i].c); break;
			}
		}
		for (int i = q; i > 0; -- i) {
			switch (opt[i].s) {
			case 'C' : Cir(opt[i].x, opt[i].y, opt[i].l, opt[i].c); break;
			case 'D' : Dia(opt[i].x, opt[i].y, opt[i].l, opt[i].c); break;
			case 'R' : Rec(opt[i].x, opt[i].y, opt[i].l, opt[i].w, opt[i].c); break;
			case 'T' : Tri(opt[i].x, opt[i].y, opt[i].w, opt[i].c); break;
			}
		}
		for (int i = 1; i <= 9; ++ i)
			if (i == 9) printf("%d\n", Count[i]);
			else printf("%d ", Count[i]);
	}
	return 0;
}
