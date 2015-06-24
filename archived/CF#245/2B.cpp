#include <cstdio>

int col[200], cnt[200], a[200];
int n, k, x, m;

int main() {
	scanf("%d%d%d", &n, &k, &x);
	for (int i = 0; i < n; ++ i) scanf("%d", a + i);
	m = 0; col[0] = a[0], cnt[0] = 1;
	for (int i = 1; i < n; ++ i)
		if (a[i] == a[i - 1]) cnt[m] ++;
		else col[++ m] = a[i], cnt[m] = 1;
	int ret = 0;
	for (int i = 0; i <= m; ++ i) 
		if (col[i] == x && cnt[i] >= 2) {
			int tmp = cnt[i];
			int l = i - 1, r = i + 1;
			while (l >= 0 && r <= m && col[l] == col[r]) {
				if (cnt[l] + cnt[r] < 3) break;
				tmp += cnt[l] + cnt[r];
				l --; r ++;
			}
			if (tmp > ret) ret = tmp;
		}
	printf("%d\n", ret);
	return 0;
}
