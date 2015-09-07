#include <cstdio>

int main() {
	int T; scanf("%d", &T);
	for (int cas = 1; cas <= T; ++ cas) {
		int N, M; scanf("%d%d", &N, &M);
		int c = N / 2, ret = 0;
		for (int i = 0; i < M / 2; ++ i) {
			if (i & 1) ret += c / 2;
			else ret += c / 2 + (c & 1);
		}
		int Ana = ret * 4, Bob = N * M - Ana;
		printf("Case #%d: ", cas);
		if (Ana > Bob) puts("Ana");
		else if (Ana == Bob) puts("Draw");
		else puts("Bob");
	}
	return 0;
}
