#include <stack>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <algorithm>
using namespace std;
const int MAXN = 1000 + 10;
typedef pair<int, int> PII;

int main() {
	int T, N, M;
	int ret[MAXN << 4], height[MAXN];
	char grid[MAXN];

	scanf("%d", &T);
	while (T --) {
		scanf("%d%d", &N, &M);
		fill(height, height + M, 0);
		memset(ret, 0, sizeof(ret));
		for (int i = 0; i < N; ++ i) {
			scanf("%s", grid);
			stack<PII> stk;
			for (int j = 0; j < M; ++ j) {
				if (grid[j] == '#') height[j] = 0;
				else height[j] ++;

				int p = j;
				while (!stk.empty() && stk.top().first >= height[j]) {
					p = stk.top().second; stk.pop();
				}

				if (!height[j]) continue;
				if (stk.empty() || height[j] - stk.top().first > p - stk.top().second) {
					ret[height[j] + j - p + 1] ++;
					stk.push(make_pair(height[j], p));
				} else {
					ret[stk.top().first + j - stk.top().second + 1] ++;
				}
			}
		}
		for (int i = 1; i <= N + M; ++ i)
			if (ret[i]) printf("%d x %d\n", ret[i], i * 2);
	}
	return 0;
}
