#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 100000 + 10;

vector <int> A[MAXN];
int N, M;

int main() {
	while (scanf("%d", &N) == 1) {
		for (int i = 0; i < N; ++ i) {
			int m, x; scanf("%d", &m);
			A[i].clear(); A[i].push_back(0);
			while (m --) {
				scanf("%d", &x);
				A[i].push_back(x);
			}
			sort(A[i].begin(), A[i].end());
		}
		scanf("%d", &N);
		while (N --) {
			int x, y, ret = 0;;
			scanf("%d%d", &x, &y);
			x --, y --;
			if (A[x].size() > A[y].size()) swap(x, y);
			for (int i = 1; i < (int)A[x].size(); ++ i) {
				int left = 0, right = A[y].size() - 1, pos = -1;
				while (left <= right) {
					int mid = (left + right) >> 1;
					if (A[y][mid] < A[x][i]) left = mid + 1, pos = left;
					else right = mid - 1;
				}
				if (pos > 1 && (i == 1 || A[y][pos - 1] > A[x][i - 1])) ret ++;
				if (pos < (int)A[y].size() && (i == (int)A[x].size() - 1 || A[y][pos] < A[x][i + 1])) ret ++;
			}
			printf("%d\n", ret);
		}
	}
	return 0;
}
