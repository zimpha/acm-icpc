#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 500000 + 10;
struct Node {
	int l, r;
	int ml, mr;
};

Node mn[MAXN];
int A[MAXN], n;
int L[MAXN], R[MAXN];

inline void update(int &x, int y) {
	if (A[y] > A[x]) x = y;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) scanf("%d", A + i);
	for (int i = 1; i <= n; ++ i) {
		int j = i - 1; mn[i].ml = i;
		while (j >= 1 && A[j] > A[i]) {
			update(mn[i].ml, mn[j].ml);
			j = mn[j].l;
		}
		mn[i].l = j;
		j = i - 1;
		while (j >= 1 && A[j] < A[i]) j = L[j];
		L[i] = j;
	}
	for (int i = n; i >= 1; -- i) {
		int j = i + 1; mn[i].mr = i;
		while (j <= n && A[j] > A[i]) {
			update(mn[i].mr, mn[j].mr);
			j = mn[j].r;
		}
		mn[i].r = j;
		j = i + 1;
		while (j <= n && A[j] < A[i]) j = R[j];
		R[i] = j;
	}
	int len = -1, pos = -1;
	for (int i = 1; i <= n; ++ i) {
		int mx = max(A[mn[i].ml], A[mn[i].mr]);
		if (mx == A[mn[i].ml]) {
			int j = mn[i].ml;
			if (i > L[j] && i < R[j] && j > mn[i].l && j < mn[i].r) {
				int x = max(L[j], mn[i].l) + 1;
				int y = min(R[j], mn[i].r);
				if ((y - x > len) || (y - x == len && pos > x)) {
					len = y - x;
					pos = x;
				}
			}
		}
		if (mx == A[mn[i].mr]) {
			int j = mn[i].mr;
			if (i > L[j] && i < R[j] && j > mn[i].l && j < mn[i].r) {
				int x = max(L[j], mn[i].l) + 1;
				int y = min(R[j], mn[i].r);
				if ((y - x > len) || (y - x == len && pos > x)) {
					len = y - x;
					pos = x;
				}
			}
		}
	}
	printf("%d %d\n", len, pos);
	return 0;
}
