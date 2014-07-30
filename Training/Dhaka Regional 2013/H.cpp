#include <cstdio>
#include <cstring>
const int MAXN = 30000000 + 10;
int s[MAXN];

int main() {
	int N = 30000000, T; scanf("%d", &T);
	for (int i = 1; i <= N; ++ i) s[i] = 0;
	for (int i = 1; i <= N; ++ i) {
		for (int j = i + i; j <= N; j += i)
			if ((j ^ (j - i)) == i) s[j] ++;
	}
	for (int i = 1; i <= N; ++ i) s[i + 1] += s[i];
	for (int cas = 1; cas <= T; ++ cas) {
		scanf("%d", &N);
		printf("Case %d: %d\n", cas, s[N]);
	}
	return 0;
}
