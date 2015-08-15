#include <queue>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
const int MOD = 1e9 + 7;
const int MAXN = 300000 + 10;

int magic[MAXN], A[MAXN];
int N, M, L;

int main() {
	scanf("%d%d", &L, &N);
	int mx = 0, has = 0;
	for (int i = 1; i <= N; ++ i) {
		scanf("%d", &A[i]);
		mx = max(mx, A[i]);
	}
	queue<int> R, S;
	for (int i = 1; i < 10; ++ i) {
		if (i * i <= L) {
			R.push(i);
			S.push(i * i);
		}
	}
	while (!R.empty()) {
		int x = R.front(), y = S.front(); R.pop(); S.pop();
		magic[has ++] = x;
		if (has == mx) break;
		for (int i = 0; i < 10; ++ i) {
			if (y + i * i <= L) {
				S.push(y + i * i);
				R.push(((long long)x * 10 + i) % MOD);
			}
		}
	}
	for (int i = 1; i <= N; ++ i) A[i] = magic[A[i] - 1];
	A[0] = 0;
	for (int i = 1; i <= N; ++ i) A[i] = (A[i] + A[i - 1]) % MOD;
	scanf("%d", &M);
	while (M --) {
		int l, r; scanf("%d%d", &l, &r);
		int ret = (A[r] - A[l - 1] + MOD) % MOD;
		if (ret < 0) ret += MOD;
		printf("%d\n", ret);
	}
	return 0;
}
