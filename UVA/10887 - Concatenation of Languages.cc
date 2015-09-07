#include <set>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int SIZE = 20;
const int MAXN = 2000;
const int seed = 123;

typedef unsigned long long ULL;

set <ULL> S;
char S1[MAXN][SIZE], S2[MAXN][SIZE];
int L1[MAXN], L2[MAXN];
ULL f1[MAXN], f2[MAXN], pp[MAXN];

int main() {
	char st[10000];
	int T;
	gets(st); sscanf(st, "%d", &T);
	for (int i = 0; i < MAXN; ++ i) {
		pp[i] = i ? pp[i - 1] * seed : 1;
	}
	for (int cas = 1; cas <= T; ++ cas) {
		S.clear();
		int n, m;
		gets(st); sscanf(st, "%d%d", &n, &m);
		for (int i = 0; i < n; ++ i) {
			gets(S1[i]);
			L1[i] = strlen(S1[i]); f1[i] = 0;
			for (int j = L1[i] - 1; j >= 0; -- j) {
				f1[i] += S1[i][j] * pp[L1[i] - j - 1];
			}
		}
		for (int i = 0; i < m; ++ i) {
			gets(S2[i]);
			L2[i] = strlen(S2[i]); f2[i] = 0;
			for (int j = L2[i] - 1; j >= 0; -- j) {
				f2[i] += S2[i][j] * pp[L2[i] - j - 1];
			}
		}
		if (n == 0 || m == 0) {
			printf("Case %d: %d\n", cas, 0);
			continue;
		}
		for (int i = 0; i < n; ++ i) {
			for (int j = 0; j < m; ++ j) {
				ULL tmp = f1[i] * pp[L2[j]] + f2[j];
				S.insert(tmp);
			}
		}
		printf("Case %d: %d\n", cas, (int)S.size());
	}
	return 0;
}
