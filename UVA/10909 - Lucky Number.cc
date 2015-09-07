#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 2000000 + 10;

int C[MAXN], lucky[MAXN];
int N, M;

void Update(int idx, int v) {
	for (int i = idx; i < MAXN; i += i & -i) C[i] += v;
}

int Sum(int idx) {
	int ret = 0;
	for (int i = idx; i; i -= i & -i) ret += C[i];
	return ret;
}

int Kth(int k) {
	int ret = 0, cnt = 0;
	for (int i = 20; i >= 0; -- i) {
		ret += (1 << i);
		if (ret >= MAXN || cnt + C[ret] >= k) ret -= (1 << i);
		else cnt += C[ret];
	}
	return ret + 1;
}

void get_lucky() {
	memset(C, 0, sizeof(C));
	for (int i = 1; i < 2000000; i += 2) Update(i, 1);
	M = 1; lucky[0] = 1; N = 1000000;
	for (int i = 2; i <= N; ++ i) {
		int ret = Kth(i); lucky[M ++] = ret;
		for (int j = ret; j <= N; j += ret - 1, N --) {
			int tmp = Kth(j);
			Update(tmp, -1);
		}
	}
	memset(C, 0, sizeof(C));
	for (int i = 0; i < M; ++ i) C[lucky[i]] = 1;
}

int main() {
	get_lucky();
	while (scanf("%d", &N) == 1) {
		if (N & 1) {
			printf("%d is not the sum of two luckies!\n", N);
			continue;
		}
		int pos = lower_bound(lucky, lucky + M, N / 2) - lucky;
		for (int i = pos; i >= 0; -- i) {
			if (C[N - lucky[i]] && lucky[i] <= N - lucky[i]) {
				printf("%d is the sum of %d and %d.\n", N, lucky[i], N - lucky[i]);
				break;
			}
		}
	}
	return 0;
}
