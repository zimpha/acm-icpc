#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

vector<int> fa;

int Find(int x) {
	if (x != fa[x]) fa[x] = Find(fa[x]);
	return fa[x];
}

int main() {
	int T, N; scanf("%d", &T);
	while (T --) {
		scanf("%d\n", &N); fa.resize(N);
		for (int i = 0; i < N; ++ i) fa[i] = i;
		char st[100];
		int N1 = 0, N2 = 0;
		while (gets(st) && st[0]) {
			int a, b;
			sscanf(st + 1, "%d%d", &a, &b);
			a --, b --;
			if (st[0] == 'c') {
				a = Find(a); b = Find(b);
				if (a != b) fa[a] = b;
			} else if (st[0] == 'q') {
				a = Find(a); b = Find(b);
				if (a == b) N1 ++;
				else N2 ++;
			}
		}
		printf("%d,%d\n", N1, N2);
		if (T) puts("");
	}
	return 0;
}
