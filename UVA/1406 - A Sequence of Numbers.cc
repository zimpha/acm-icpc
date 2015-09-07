#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 1<<16;

int cnt[16][MAXN];
int N;

int main() {
	int cas = 0;
	while (scanf("%d", &N) == 1 && N != -1) {
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0, x; i < N; ++ i) {
			scanf("%d", &x);
			for (int j = 0; j < 16; ++ j) {
				cnt[j][x % (1 << (j + 1))] ++;
			}
		}
		for (int i = 0; i < 16; ++ i) {
			for (int j = 1; j < MAXN; ++ j) {
				cnt[i][j] += cnt[i][j - 1];
			}
		}
		char st[10];
		int S = 0, T;
		long long ret = 0;
		while (scanf("%s", st) == 1 && st[0] != 'E') {
			scanf("%d", &T);
			if (st[0] == 'C') S += T, S %= MAXN;
			else {
				int i = 1 << T, j = i << 1;	
				int l = ((i - S) % j + j) %j, r = j - 1;
				if (l <= i) ret += cnt[T][l + i -1] - (l ? cnt[T][l - 1] : 0);
				else {
					ret += cnt[T][r] - (l ? cnt[T][l - 1] : 0);
					ret += cnt[T][(l + i - 1) % j];
				}
			}
		}
		printf("Case %d: %lld\n", ++ cas, ret);
	}
	return 0;
}
