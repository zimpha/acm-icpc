#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 200000 + 10;

struct Point{
	int x, y;
	int id;
	bool operator < (const Point &oth) const {
		if (x == oth.x) return y > oth.y;
		else return x < oth.x;
	}
} P[MAXN];

struct FenwickTree {
	int C[MAXN], N;
	void init(int n) {
		this->N = ++ n;
		memset(C, 0, sizeof(int) *n);
	}
	void Update(int x) {
		for ( ; x < N; x += x & -x) C[x] ++;
	}
	int rsq(int x) {
		int ret = 0;
		for ( ; x; x -= x & -x) ret += C[x];
		return ret;
	}
} T;

int cnt[MAXN], cnt2[MAXN], pool[MAXN], ans[MAXN];
int N, M;

int main() {
	while(scanf("%d" , &N) == 1 && N) {
		for(int i = 0;i < N; ++ i) {
			scanf("%d %d", &P[i].x, &P[i].y);
			P[i].id = i; pool[i] = P[i].y;
		}
		sort(pool, pool + N);
		M = unique(pool, pool + N) - pool;
		for (int i = 0; i < N; ++ i){
			P[i].y = lower_bound(pool, pool + M, P[i].y) - pool + 1;
		}
		memset(cnt, 0, sizeof(cnt)); memset(cnt2, 0, sizeof(cnt2));
		//bot-left
		sort(P, P + N); T.init(M);
		for (int i = 0; i < N; ++ i) {
			cnt[P[i].id] += T.rsq(P[i].y - 1);
			T.Update(P[i].y);
		}
		//bot-right
		for (int i = 0; i < N; ++ i) P[i].x = -P[i].x;
		sort(P, P + N); T.init(M);
		for (int i = 0; i < N; ++ i) {
			cnt2[P[i].id] += T.rsq(P[i].y - 1);
			T.Update(P[i].y);
		}
		//top-right
		for (int i = 0; i < N; ++ i) P[i].y = M - P[i].y + 1;
		sort(P, P + N); T.init(M);
		for (int i = 0; i < N; ++ i) {
			cnt[P[i].id] += T.rsq(P[i].y - 1);
			T.Update(P[i].y);
		}
		//top-left
		for (int i = 0; i < N; ++ i) P[i].x = -P[i].x;
		sort(P, P + N); T.init(M);
		for (int i = 0; i < N; ++ i) {
			cnt2[P[i].id] += T.rsq(P[i].y - 1);
			T.Update(P[i].y);
		}
		int best = -1, na = 0;
		for (int i = 0; i < N; ) {
			int st = i, b1 = MAXN , b2 = -1;
			while (i < N && P[i].x == P[st].x){
				int t1 = cnt[P[i].id], t2 = cnt2[P[i].id];
				if (t2 > b2 || (t2 == b2 && t1 < b1)) {
					b1 = t1, b2 = t2;
				}
				++ i;
			}
			if (b1 > best) {
				best = b1;
				na = 0;
				ans[na ++] = b2;
			} else if (b1 == best) {
				ans[na ++] = b2;
			}
		}
		sort(ans, ans + na);
		na = unique(ans, ans + na) - ans;
		printf("Stan: %d; Ollie:", best);
		for(int i = 0;i < na; ++i) printf(" %d", ans[i]);
		puts(";");
	}
	return 0;
}

