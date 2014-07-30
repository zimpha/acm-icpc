#include <cstdio>
#include <cstring>
#include <cstdlib>

int main() {
	int T; scanf("%d", &T);
	for (int cas = 1; cas <= T; ++ cas) {
		int N, B = 0, W = 0, tie = 0, A = 0; 
		char st[100];
		scanf("%d%s", &N, st);
		for (int i = 0; i < N; ++ i) {
			if (st[i] == 'B') B ++;
			else if (st[i] == 'W') W ++;
			else if (st[i] == 'T') tie ++;
			else if (st[i] == 'A') A ++;
		}
		printf("Case %d: ", cas);
		if (A == N) puts("ABANDONED");
		else if (B + A == N) puts("BANGLAWASH");
		else if (W + A == N) puts("WHITEWASH");
		else if (W == B) printf("DRAW %d %d\n", W, tie);
		else if (W > B) printf("WWW %d - %d\n", W, B);
		else if (W < B) printf("BANGLADESH %d - %d\n", B, W);
	}
	return 0;
}
