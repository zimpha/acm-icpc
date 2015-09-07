#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	int T, N; scanf("%d", &T);
	while (T --) {
		int f[10], r[10], vis[2][10];
		scanf("%d", &N);
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < N; ++ i) scanf("%d", &f[i]);
		for (int i = 0; i < N; ++ i) scanf("%d", &r[i]);
		int mi = 0, ma = 0;
		for (int i = 0; i < N; ++ i) 
			for (int j = 0; j < N; ++ j)
				if (f[i] == r[j] && !vis[0][i] && !vis[1][j]) {
					mi += f[i]; vis[0][i] = vis[1][j] = 1;
				}
		for (int i = 0; i < N; ++ i) {
			if (!vis[1][i]) mi += r[i];
			if (!vis[0][i]) mi += f[i];
		}
		for (int i = 0; i < N; ++ i)
			for (int j = 0; j < N; ++ j)
				ma += min(f[i], r[j]);
		printf("Matty needs at least %d blocks, and can add at most %d extra blocks.\n", mi, ma - mi);
	}
	return 0;
}
