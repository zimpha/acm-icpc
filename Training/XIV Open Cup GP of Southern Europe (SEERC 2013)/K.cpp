#include <cstdio>
#include <cstring>

int main() {
	freopen("k.in", "r", stdin);
	int N, ret = -1, l, r, sum = -1;
	scanf("%d", &N);
	for (int i = 0, p; i < N; ++ i) {
		int x; scanf("%d", &x);
		if (sum < 0) sum = 0, p = i;
		sum += x;
		if (sum > ret) {
			l = p;
			r = i;
			ret = sum;
		}
	}
	printf("%d %d\n", l + 1, r + 1);
	fclose(stdin);
	return 0;
}
