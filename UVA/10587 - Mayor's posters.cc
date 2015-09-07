#include <map>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define mid ((l+r)>>1)
#define lson rt<<1
#define rson rt<<1|1

using namespace std;

const int MAXN=40005;

struct node
{
	int col, tag;
};

node tree[MAXN*4];
int left[MAXN], right[MAXN];
int cnt[MAXN];
int N, M;

void pushdown(int rt)
{
	tree[lson].col=tree[rson].col=tree[rt].col;
	tree[lson].tag=tree[rson].tag=1;
	tree[rt].tag=0;
}

void update(int rt)
{
	if (tree[lson].col==-1||tree[rson].col==-1||tree[lson].col!=tree[rson].col) tree[rt].col=-1;
	else tree[rt].col=tree[rson].col;
}

int find(int l, int r, int x)
{
	while (l<=r)
	{
		int m=(l+r)>>1;
		if (cnt[m]==x) return m;
		if (cnt[m]<x) l=m+1;
		else r=m-1;
	}
	return -1;
}

void cover(int rt, int l, int r, int ll, int rr, int d)
{
	if (l>r) return;
	if (ll<=l&&rr>=r)
	{
		tree[rt].col=d, tree[rt].tag=1;
		return;
	}
	if (tree[rt].tag) pushdown(rt);
	if (ll<=mid) cover(lson, l, mid, ll, rr, d);
	if (rr>mid) cover(rson, mid+1, r, ll, rr, d);
	update(rt);
}

void query(int rt, int l, int r)
{
	if (l>r) return;
	if (tree[rt].col!=-1)
	{
		cnt[tree[rt].col]++;
		return;
	}
	query(lson, l, mid);
	query(rson, mid+1, r);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &N); M=0;
		for (int i=1; i<=N; i++)
		{
			scanf("%d%d", &left[i], &right[i]);
			cnt[M++]=left[i], cnt[M++]=right[i];
		}
		sort(cnt, cnt+M);
		int tmp=M;
		for (int i=1; i<tmp; i++)
			if (cnt[i]-cnt[i-1]>1) cnt[M++]=cnt[i]+1;
		tmp=M;
		sort(cnt, cnt+tmp); M=0;
		for (int i=1; i<tmp; i++)
			if (cnt[i]!=cnt[i-1]) cnt[++M]=cnt[i];
		memset(tree, 0, sizeof(tree));
		for (int i=1; i<=N; i++)
		{
			int ll=find(0, M, left[i]);
			int rr=find(0, M, right[i]);
			cover(1, 0, M, ll, rr, i);
		}
		memset(cnt, 0, sizeof(cnt));
		query(1, 0, M);
		M=0;
		for (int i=1; i<=N; i++)
			if (cnt[i]) M++;
		printf("%d\n", M);
	}
	return 0;
}
