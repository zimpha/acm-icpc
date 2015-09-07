#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#define lson (rt<<1)
#define rson (rt<<1|1)
#define mid ((l+r)>>1)

const int MAXN=10005;

int tree[MAXN*4];
int col[MAXN];
int N;

void build(int rt, int l, int r)
{
	tree[rt]=0;
	if (l+1==r) return;
	build(lson, l, mid);
	build(rson, mid, r);
}

void modify(int rt, int l, int r, int ll, int rr, int h)
{
	if (ll<=l&&rr>=r)
	{
		if (h>tree[rt]) tree[rt]=h;
		return;
	}
	if (ll<mid) modify(lson, l, mid, ll, rr, h);
	if (rr>mid) modify(rson, mid, r, ll, rr, h);
}

void query(int rt, int l, int r, int h)
{
	if (h>tree[rt]) tree[rt]=h;
	if (l+1==r)
	{
		col[l]=tree[rt];
		return;
	}
	query(lson, l, mid, tree[rt]);
	query(rson, mid, r, tree[rt]);
}

int main()
{
	build(1, 1, 10000);
	int L, R, H;
	int MAX=0;
	while (scanf("%d%d%d", &L, &H, &R)==3)
	{
		modify(1, 1, 10000, L, R, H);
		if (R>MAX) MAX=R;
	}
	memset(col, 0, sizeof(col));
	query(1, 1, 10000, 0);
	printf("%d %d ", 1, col[1]);
	for (int i=2; i<MAX; i++)
		if (col[i]!=col[i-1]) printf("%d %d ", i, col[i]);
	printf("%d 0\n", MAX);
}
