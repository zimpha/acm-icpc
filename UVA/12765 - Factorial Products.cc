#include <cstdio>
#include <cstring>

int cnt[10];

void add(int x, int f) {
	for (int i = 2; x / i; i = i * 2) {
		cnt[2] += f * (x / i);
	}
	for (int i = 3; x / i; i = i * 3) {
		cnt[3] += f * (x / i);
	}
	for (int i = 5; x / i; i = i * 5) {
		cnt[5] += f * (x / i);
	}
	for (int i = 7; x / i; i = i * 7) {
		cnt[7] += f * (x / i);
	}
}

int main() {
	int N, M;
	while (scanf("%d%d", &N, &M) == 2 && N) {
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < N; ++ i) {
			int x; scanf("%d", &x);
			add(x, 1);
		}
		for (int i = 0; i < M; ++ i) {
			int x; scanf("%d", &x);
			add(x, -1);
		}
		if (cnt[2] == 0 && cnt[3] == 0 && cnt[5] == 0 && cnt[7] == 0) puts("YES");
		else puts("NO");
	}
	return 0;
}
