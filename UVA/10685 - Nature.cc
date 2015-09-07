#include <map>
#include <string>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 5000 + 10;
map<string, int> Table;
int fa[MAXN], size[MAXN], N, M;

int Find(int x) {
	if (x - fa[x]) fa[x] = Find(fa[x]);
	return fa[x];
}

void Union(int a, int b) {
	a = Find(a), b = Find(b);
	if (a != b) fa[a] = b, size[b] += size[a];
}

int main() {
	while (scanf("%d%d", &N, &M) == 2 && N) {
		char s1[50], s2[50]; Table.clear();
		for (int i = 0; i < N; ++ i) {
			scanf("%s", s1);
			Table[(string)s1] = i;
			fa[i] = i; size[i] = 1;
		}
		for (int i = 0; i < M; ++ i) {
			scanf("%s%s", s1, s2);
			Union(Table[(string)s1], Table[(string)s2]);
		}
		int ret = 0;
		for (int i = 0; i < N; ++ i) ret = max(ret, size[i]);
		printf("%d\n", ret);
	}
	return 0;
}
