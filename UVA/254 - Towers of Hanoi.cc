#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int ans[5], b[130];
char str[130];

void binary() {
	int k = 0, l, a[130];
	memset(b, 0, sizeof(b));
	l = strlen(str);
    for (int i = 0; i < l; ++ i) a[i] = str[i] - '0';
	for (int p = 0; p < l; ) {
		int mod = 0;
		for (int i = p; i < l; ++ i) {
			a[i] = mod * 10 + a[i];
			mod = a[i] & 1;
			a[i] >>= 1;
		}
		b[k ++] = mod;
		if (!a[p]) p ++;
	}
}

void hanoi(int A, int B, int C, int k) {
	if (k <= 0) return;
	if (b[k - 1]) {
		ans[A] -= k;
		ans[B] += k - 1;
		ans[C] ++;
		hanoi(B, A, C, k - 1);
	} else hanoi(A, C, B, k - 1);
}

int main() {
	int N;
	while (scanf("%d%s", &N, str), N || str[0] != '0') {
		binary();
		ans[0] = N;
		ans[1] = ans[2] = 0;
		if (N & 1) hanoi(0, 2, 1, N);
		else hanoi(0, 1, 2, N);
		printf("%d %d %d\n", ans[0], ans[1], ans[2]);
	}
	return 0;
}

