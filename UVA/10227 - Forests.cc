#include <set>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
const int MAXN = 100 + 10;
set<int> S[MAXN];
int fa[MAXN];

int Find(int x) {
	if (x - fa[x]) fa[x] = Find(fa[x]);
	return fa[x];
}

void Union(int a, int b) {
	a = Find(a), b = Find(b);
	if (a != b) fa[a] = b;
}

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		int N, M;
		scanf("%d%d\n", &N, &M);
		char st[100];
		for (int i = 0; i < N; ++ i) S[i].clear();
		while (gets(st) && st[0]) {
			int a, b;
			sscanf(st, "%d%d", &a, &b);
			S[a - 1].insert(b);
		}
		for (int i = 0; i < N; ++ i) fa[i] = i;;
		for (int i = 0; i < N; ++ i)
			for (int j = i + 1; j < N; ++ j)
				if (S[i] == S[j]) Union(i, j);
		int ret = 0;
		for (int i = 0; i < N; ++ i)
			if (i == Find(i)) ret ++;
		printf("%d\n", ret);
		if (T) puts("");
	}
	return 0;
}
