#include <map>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cassert>

using namespace std;

const int MAXN = 100005;

map<int, int> hash;
vector<int> pos[MAXN];
int N, M, K;

int main() {
	while (scanf("%d%d", &N, &K) == 2) {
		hash.clear(); M = 1;
		for (int i = 0; i < N; ++ i) {
			int x;
			scanf("%d", &x);
			if (!hash[x]) {
				pos[M].clear();
				hash[x] = M ++;
			}
			pos[hash[x]].push_back(i);
		}
		int ret = 0;
		for (int l = 1; l < M; ++ l) {
			int N = pos[l].size();
			int sum = 0;
			for (int i = 0, j = 0; i < N; ) {
				while (j < N && sum <= K) {
					if (ret < j - i + 1) ret = j - i + 1;
					++ j;
					if (j >= N) break;
					sum += pos[l][j] - pos[l][j - 1] - 1;
				}
				++ i;
				if (i >= N) break;
				sum -= pos[l][i] - pos[l][i - 1] - 1;
			}
		}
		printf("%d\n", ret);
	}
	return 0;
}
