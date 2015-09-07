#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#define lson (rt<<1)
#define rson (rt<<1|1)
#define mid ((l+r)>>1)

using namespace std;

typedef long long LL;

const int MAXN=120005;
const int MAXK=15;

struct node
{
	int sum[MAXK], cnt;
};

struct SEG
{
	int l, r, x;
	int tag;
};

node tree[MAXN*4];
SEG seg[MAXN];
int C[MAXN];
int N, K;

bool cmp(SEG a, SEG b)
{
	if (a.x==b.x) return a.tag>b.tag;
	else return a.x<b.x;
}

void build(int rt, int l, int r)
{
	memset(tree[rt].sum, 0, sizeof(tree[rt].sum));
	tree[rt].cnt=0; tree[rt].sum[0]=C[r]-C[l];
	if (l+1==r) return;
	build(lson, l, mid);
	build(rson, mid, r);
}

inline void update(int rt, int l, int r)
{
	memset(tree[rt].sum, 0, sizeof(tree[rt].sum));
	if (tree[rt].cnt>=K) tree[rt].sum[K]=C[r]-C[l];
	else if (l+1==r) tree[rt].sum[tree[rt].cnt]=C[r]-C[l];
	else
	{
		for (int i=tree[rt].cnt; i<K; i++)
			tree[rt].sum[i]=tree[lson].sum[i-tree[rt].cnt]+tree[rson].sum[i-tree[rt].cnt];
		for (int i=K-tree[rt].cnt; i<=K; i++)
			tree[rt].sum[K]+=tree[lson].sum[i]+tree[rson].sum[i];
	}
}

void modify(int rt, int l, int r, int k)
{
	if (seg[k].l<=C[l]&&seg[k].r>=C[r])
	{
		tree[rt].cnt+=seg[k].tag;
		update(rt, l, r);
		return;
	}
	if (seg[k].l<C[mid]) modify(lson, l, mid, k);
	if (seg[k].r>C[mid]) modify(rson, mid, r, k);
	update(rt, l, r);
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int cas=1; cas<=T; cas++)
	{
		scanf("%d%d", &N, &K);
		for (int i=1; i<=N; i++)
		{
			int x1, y1, x2, y2;
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			y2++; x2++;
			C[2*i-1]=y1; C[2*i]=y2;
			seg[2*i-1]=(SEG){y1, y2, x1, 1};
			seg[2*i]=(SEG){y1, y2, x2, -1};
		}
		N*=2;
		sort(C+1, C+1+N);
		sort(seg+1, seg+1+N, cmp);
		int cnt=1;
		for (int i=2; i<=N; i++)
			if (C[i]!=C[i-1]) C[++cnt]=C[i];
		build(1, 1, cnt);
		LL ret=0;
		for (int i=1; i<=N; i++)
		{
			ret+=(LL)tree[1].sum[K]*(seg[i].x-seg[i-1].x);
			modify(1, 1, cnt, i);
		}
		printf("Case %d: %lld\n", cas, ret);
	}
	return 0;
}
