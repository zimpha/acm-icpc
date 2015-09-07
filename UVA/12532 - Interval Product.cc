#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

#define lson (rt<<1)
#define rson (rt<<1|1)
#define mid ((l+r)>>1)

const int MAXN=100005;

struct node
{
	int sum[3];
};

node tree[MAXN*4];
int V[MAXN];
int N, M;

inline void update(int rt)
{
	for (int i=0; i<3; i++)
		tree[rt].sum[i]=tree[lson].sum[i]+tree[rson].sum[i];
}

void build(int rt, int l, int r)
{
	for (int i=0; i<3; i++) tree[rt].sum[i]=0;
	if (l==r)
	{
		if (V[l]<0) tree[rt].sum[0]=1;
		else if (V[l]==0) tree[rt].sum[1]=1;
		else tree[rt].sum[2]=1;
		return;
	}
	build(lson, l, mid);
	build(rson, mid+1, r);
	update(rt);
}

void modify(int rt, int l, int r, int k, int val)
{
	if (l==r)
	{
		for (int i=0; i<3; i++) tree[rt].sum[i]=0;
		if (val<0) tree[rt].sum[0]=1;
		else if (val==0) tree[rt].sum[1]=1;
		else tree[rt].sum[2]=1;
		return;
	}
	if (k<=mid) modify(lson, l, mid, k, val);
	else modify(rson, mid+1, r, k, val);
	update(rt);
}

node query(int rt, int l, int r, int ll, int rr)
{
	if (ll<=l&&rr>=r) return tree[rt];
	node ret, tmp;
	memset(ret.sum, 0, sizeof(ret.sum));
	memset(tmp.sum, 0, sizeof(tmp.sum));
	if (ll<=mid) tmp=query(lson, l, mid, ll, rr);
	for (int i=0; i<3; i++) ret.sum[i]+=tmp.sum[i];
	memset(tmp.sum, 0, sizeof(tmp.sum));
	if (rr>mid) tmp=query(rson, mid+1, r, ll, rr);
	for (int i=0; i<3; i++) ret.sum[i]+=tmp.sum[i];
	return ret;
}

int main()
{
	while (scanf("%d%d", &N, &M)==2)
	{
		for (int i=1; i<=N; i++)
			scanf("%d", &V[i]);
		build(1, 1, N);
		while (M--)
		{
			char opt[10];
			int l ,r;
			scanf("%s%d%d", opt, &l, &r);
			if (opt[0]=='C') modify(1, 1, N, l, r);
			else
			{
				node ret=query(1, 1, N, l, r);
				if (ret.sum[1]>0) putchar('0');
				else if ((ret.sum[0]%2==0)) putchar('+');
				else putchar('-');
			}

		}
		puts("");
	}
	return 0;
}
