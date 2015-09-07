#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

#define lson (rt<<1)
#define rson (rt<<1|1)
#define mid ((l+r)>>1)

using namespace std;

typedef long long LL;

const int MAXN=500005;

struct node
{
	LL lc, rc, mc, sum;
	int l, r, ml, mr;
};

node tree[MAXN*4];
int N, M;

inline void update(int rt)
{
	tree[rt].sum=tree[lson].sum+tree[rson].sum;

	tree[rt].mc=max(tree[lson].rc+tree[rson].lc, max(tree[lson].mc, tree[rson].mc));
	if (tree[rt].mc==tree[lson].mc)
	{
		tree[rt].ml=tree[lson].ml;
		tree[rt].mr=tree[lson].mr;
	}
	else if (tree[rt].mc==tree[lson].rc+tree[rson].lc)
	{
		tree[rt].ml=tree[lson].r;
		tree[rt].mr=tree[rson].l;
	}
	else
	{
		tree[rt].ml=tree[rson].ml;
		tree[rt].mr=tree[rson].mr;
	}

	tree[rt].lc=max(tree[lson].lc, tree[lson].sum+tree[rson].lc);
	if (tree[rt].lc==tree[lson].lc) tree[rt].l=tree[lson].l;
	else tree[rt].l=tree[rson].l;

	tree[rt].rc=max(tree[rson].rc, tree[rson].sum+tree[lson].rc);
	if (tree[rt].rc==tree[rson].sum+tree[lson].rc) tree[rt].r=tree[lson].r;
	else tree[rt].r=tree[rson].r;
}

void build(int rt, int l, int r)
{
	if (l==r)
	{
		int x;
		scanf("%d", &x);
		tree[rt].lc=tree[rt].rc=tree[rt].mc=tree[rt].sum=x;
		tree[rt].l=tree[rt].r=tree[rt].ml=tree[rt].mr=l;
		return;
	}
	build(lson, l, mid);
	build(rson, mid+1, r);
	update(rt);
}

node query(int rt, int l, int r, int ll, int rr)
{
	if (ll==l&&rr==r) return tree[rt];
	if (rr<=mid) return query(lson, l, mid, ll, rr);
	else if (ll>mid) return query(rson, mid+1, r, ll, rr);
	else
	{
		node left, right, ret;
		left=query(lson, l, mid, ll, mid);
		right=query(rson, mid+1, r, mid+1, rr);
		ret.sum=left.sum+right.sum;

		ret.mc=max(left.rc+right.lc, max(left.mc, right.mc));
		if (ret.mc==left.mc) ret.ml=left.ml, ret.mr=left.mr;
		else if (ret.mc==left.rc+right.lc) ret.ml=left.r, ret.mr=right.l;
		else ret.ml=right.ml, ret.mr=right.mr;

		ret.lc=max(left.lc, left.sum+right.lc);
		if (ret.lc==left.lc) ret.l=left.l;
		else ret.l=right.l;

		ret.rc=max(right.rc, right.sum+left.rc);
		if (ret.rc==right.sum+left.rc) ret.r=left.r;
		else ret.r=right.r;
		return ret;
	}
}

int main()
{
	int cas=0;
	while (scanf("%d%d", &N, &M)==2)
	{
		build(1, 1, N);
		printf("Case %d:\n", ++cas);
		while (M--)
		{
			int l, r;
			scanf("%d%d", &l, &r);
			node ret=query(1, 1, N, l, r);
			printf("%d %d\n", ret.ml, ret.mr);
		}
	}
	return 0;
}
