#include <cstdio>
#include <cstring>
const int MAXN = 10000 + 10;

int n, p[MAXN];

bool DFSID(int dep, int step) {
	if (dep > step) return false;
	if (p[dep] == n) return true;
	if (p[dep] << (step - dep) < n) return false;
	for (int i = 0; i <= dep; ++ i) {
		p[dep + 1] = p[dep] + p[i];
		if (p[dep + 1] <= 10000 && DFSID(dep + 1, step)) return true;
		p[dep + 1] = p[dep] - p[i];
		if (p[dep + 1] > 0 && DFSID(dep + 1, step)) return true;
	}
	return false;
}

int main() {
	while (scanf("%d", &n) == 1 && n) {
		for (int ret = 0; ; ++ ret) {
			p[0] = 1;
			if (DFSID(0, ret)) {
				printf("%d\n", ret);
				break;
			}
		}
	}
	return 0;
}
