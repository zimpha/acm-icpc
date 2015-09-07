#include <cstdio>
#include <cstring>
#include <cstdlib>

void solve(int l, int r, int h) {
	if (l > r) return;
	int root;
	if (r - (1 << h) + 1 >= l) root = r - (1 << h) + 1; 
	else root = l;
	printf(" %d", root);
	if (h == 0) return;
	solve(l, root - 1, h - 1);
	solve(root + 1, r, h - 1);
}

int main() {
	int H, N, cas = 0;
	while (scanf("%d%d", &N, &H) == 2 && N) {
		printf("Case %d:", ++ cas);
		if ((1 << H) <= N) puts(" Impossible.");
		else {
			solve(1, N, H - 1);
			puts("");
		}
	}
	return 0;
}
