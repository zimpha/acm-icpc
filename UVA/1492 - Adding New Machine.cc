#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define lson (rt<<1)
#define rson (rt<<1|1)
#define mid ((l+r)>>1)
using namespace std;
const int MAXN = 100000 + 10;
typedef long long LL;

struct Node {
	int cnt, width;
}Tr[MAXN << 2];

struct SEG {
	int l, r, x, tag;
	bool operator < (const SEG &oth) const {
		if (x == oth.x) return tag < oth.tag;
		else return x < oth.x;
	}
}seg[MAXN];

struct REC {
	int x1, x2, y1, y2;
}rec[MAXN];

int C[MAXN], xs[MAXN][2], ys[MAXN][2];
int N, M, W, H;

void build(int rt, int l, int r) {
	Tr[rt].cnt = Tr[rt].width = 0;
	if (l + 1 == r) return;
	build(lson, l, mid); build(rson, mid, r);
}

inline void Update(int rt, int l, int r) {
	if (Tr[rt].cnt > 0) Tr[rt].width = C[r] - C[l];
	else if (l + 1 == r) Tr[rt].width = 0;
	else Tr[rt].width = Tr[lson].width + Tr[rson].width;
}

void Modify(int rt, int l, int r, int k) {
	if (seg[k].l <= C[l] && seg[k].r >= C[r]) {
		Tr[rt].cnt += seg[k].tag;
		Update(rt, l, r);
		return;
	}
	if (seg[k].l < C[mid]) Modify(lson, l, mid, k);
	if (seg[k].r > C[mid]) Modify(rson, mid, r, k);
	Update(rt, l, r);
}

LL calc_area(int N, REC rec[]) {
	if (N == 0) return 0;
	for (int i = 1; i <= N; ++ i) {
		C[2 * i - 1] = rec[i].y1; C[2 * i] = rec[i].y2;
		seg[2 * i - 1].l = rec[i].y1; seg[2 * i].l = rec[i].y1;
		seg[2 * i - 1].r = rec[i].y2; seg[2 * i].r = rec[i].y2;
		seg[2 * i - 1].x = rec[i].x1; seg[2 * i].x = rec[i].x2;
		seg[2 * i - 1].tag = 1; seg[2 * i].tag = -1;
	}
	int cnt = 1; N <<= 1;
	sort(C + 1, C + N + 1); sort(seg + 1, seg + N + 1);
	for (int i = 2; i <= N; ++ i) {
		if (C[i] != C[i - 1]) C[++ cnt] = C[i];
	}
	build(1, 1, cnt);
	LL ret = 0;
	for (int i = 1; i <= N; ++ i) {
		ret += (LL) Tr[1].width * (seg[i].x - seg[i - 1].x);
		Modify(1, 1, cnt, i);
	}
	return ret;
}

LL solve(int W, int H, int xs[][2], int ys[][2]) {
	if (W - M + 1 <= 0) return 0;
	LL ret = (LL)H * (W - M + 1);
	int cnt = 1;
	for (int i = 1; i <= N; ++ i) {
		rec[cnt].x1 = max(0, xs[i][0] - M);
		rec[cnt].x2 = min(W - M + 1, xs[i][1]);
		rec[cnt].y1 = ys[i][0] - 1;
		rec[cnt].y2 = ys[i][1];
		if (rec[cnt].y1 > rec[cnt].y2 || rec[cnt].x1 > rec[cnt].x2)continue;
		cnt ++;
	}
	return ret - calc_area(cnt - 1, rec);
}

int main() {
	while (scanf("%d%d%d%d", &W, &H, &N, &M)==4) {
		for (int i = 1; i <= N; ++ i)
			scanf("%d%d%d%d", &xs[i][0], &ys[i][0], &xs[i][1], &ys[i][1]);
		LL ans = solve(W, H, xs, ys);
		if (M > 1) ans += solve(H, W, ys, xs);
		printf("%lld\n", ans);
	}
	return 0;
}
