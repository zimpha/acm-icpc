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
	int N, M, cas = 0;
	while (scanf("%d%d", &N, &M) == 2 && N) {
		fa.resize(N);
		for (int i = 0; i < N; ++ i) fa[i] = i;
		while (M --) {
			int a, b;
			scanf("%d%d", &a, &b);
			a --, b --;
			a = Find(a); b = Find(b);
			if (a != b) fa[a] = b;
		}
		int ret = 0;
		for (int i = 0; i < N; ++ i) 
			if (i == Find(i)) ret ++;
		printf("Case %d: %d\n", ++ cas, ret);
	}
	return 0;
}
