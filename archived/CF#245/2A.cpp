#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int x[200], d[200], n, m;

bool cmp(const int &a, const int &b) {
	return x[a] < x[b];
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++ i) {
		scanf("%d", &x[i]);
		d[i] = i;
	}
	sort(d, d + n, cmp);
	for (int i = 0; i < n; ++ i) x[d[i]] = i & 1;
	for (int i = 0; i < n; ++ i) {
		if (i) putchar(' ');
		printf("%d", x[i]);
	}
	puts("");
	return 0;
}
