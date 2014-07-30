#include <cstdio>
#include <cstring>

const int MAXN = 50;
const int SIZE = 1005;

typedef long long LL;

int N, M, a, b;

int prime[SIZE];

struct Node {
	LL cnt[SIZE];
	void init(int x) {
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; x > 1 && i < M; ++ i) {
			while (x % prime[i] == 0) {
				cnt[i] ++;
				x /= prime[i];
			}
		}
	}
};

Node F[MAXN];

void get_prime() {
	bool vis[SIZE];
	memset(vis, 0, sizeof(vis)); M = 0;
	for (int i = 2; i < SIZE; ++ i) {
		if (!vis[i]) {
			prime[M ++] = i;
			for (int j = i * 2; j < SIZE; j += i) {
				vis[j] = 1;
			}
		}
	}
}

int main() {
	int T; scanf("%d", &T);
	get_prime();
	while (T --) {
		scanf("%d%d%d", &N, &a, &b);
		F[0].init(a); F[1].init(b);
		for (int i = 2; i <= N; ++ i) {
			F[i].init(1);
			for (int j = 0; j < M; ++ j) {
				F[i].cnt[j] = F[i - 1].cnt[j] + F[i - 2].cnt[j];
			}
		}
		for (int i = 0; i < M; ++ i) {
			if (F[N].cnt[i]) {
				printf("%d %lld\n", prime[i], F[N].cnt[i]);
			}
		}
		puts("");
	}
	return 0;
}
