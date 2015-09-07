#include <cstdio>
#include <cstring>
#include <cstdlib>
const int MAXN = 1000 + 10;
const int MAXM = 50 + 10;

char DNA[MAXM][MAXN];
int N, M;

int main() {
	int T; scanf("%d", &T);	
	while (T --) {
		scanf("%d%d", &M, &N);
		for (int i = 0; i < M; ++ i) scanf("%s", DNA[i]);
		int ret = 0;
		for (int i = 0; i < N; ++ i) {
			int cnt[256];
			cnt['A'] = cnt['C'] = cnt['G'] = cnt['T'] = 0;
			for (int j = 0; j < M; ++ j) cnt[(int)DNA[j][i]] ++;
			int t1 = cnt['A'], t2 = 'A';
			if (cnt['C'] > t1) t2 = 'C', t1 = cnt[t2];
			if (cnt['G'] > t1) t2 = 'G', t1 = cnt[t2];
			if (cnt['T'] > t1) t2 = 'T', t1 = cnt[t2];
			ret += cnt['A'] + cnt['C'] + cnt['G'] + cnt['T'] - t1;
			putchar((char)t2);
		}
		printf("\n%d\n", ret);
	}
	return 0;
}
