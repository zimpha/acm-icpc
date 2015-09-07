#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 10000 + 10;
const char dirName[][10] = {"L", "Turning", "R"};

struct Node {
	int id, p, d;
	bool operator < (const Node &rhs) const {
		return p < rhs.p;
	}
};

Node before[MAXN], after[MAXN];
int order[MAXN];
int L, T, N;

int main() {
	int C; scanf("%d", &C);
	for (int cas = 1; cas <= C; ++ cas) {
		scanf("%d%d%d", &L, &T, &N);
		for (int i = 0; i < N; ++ i) {
			int p, d;
			char c;
			scanf("%d %c", &p, &c);
			d = (c == 'L' ? -1 : 1);
			before[i] = (Node){i, p, d};
			after[i] = (Node){0, p + T * d, d};
		}
		sort(before, before + N);
		for (int i = 0; i < N; ++ i) order[before[i].id] = i;
		sort(after, after + N);
		printf("Case #%d:\n", cas);
		for (int i = 1; i < N; ++ i) {
			if (after[i].p == after[i - 1].p) after[i].d = after[i - 1].d = 0;
		}
		for (int i = 0; i < N; ++ i) {
			int r = order[i];
			if (after[r].p < 0 || after[r].p > L) puts("Fell off");
			else printf("%d %s\n", after[r].p, dirName[after[r].d + 1]);
		}
		puts("");
	}
	return 0;
}
