#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#define lson (rt<<1)
#define rson (rt<<1|1)
#define mid ((l+r)>>1)

using namespace std;

const int MAXN=505;
const int inf=1<<30;

struct node
{
	int max, min;
};

node tree[MAXN][MAXN*4];
int N, M, Q;

void build(int id, int rt, int l, int r)
{
	if (l==r)
	{
		int x;
		scanf("%d", &x);
		tree[id][rt].min=tree[id][rt].max=x;
		return;
	}
	build(id, lson, l, mid);
	build(id, rson, mid+1, r);
	tree[id][rt].min=min(tree[id][lson].min, tree[id][rson].min);
	tree[id][rt].max=max(tree[id][lson].max, tree[id][rson].max);
}

void modify(int id, int rt, int l, int r, int k, int val)
{
	if (l==r)
	{
		tree[id][rt].min=val;
		tree[id][rt].max=val;
		return;
	}
	if (k<=mid) modify(id, lson, l, mid, k, val);
	else modify(id, rson, mid+1, r, k, val);
	tree[id][rt].min=min(tree[id][lson].min, tree[id][rson].min);
	tree[id][rt].max=max(tree[id][lson].max, tree[id][rson].max);
}

node query(int id, int rt, int l, int r, int ll, int rr)
{
	if (ll<=l&&rr>=r) return tree[id][rt];
	node ret, tmp;
	ret.max=-inf, ret.min=inf;
	tmp.max=-inf, tmp.min=inf;
	if (ll<=mid) tmp=query(id, lson, l, mid, ll, rr);
	ret.max=max(tmp.max, ret.max); ret.min=min(ret.min, tmp.min);
	tmp.max=-inf, tmp.min=inf;
	if (rr>mid) tmp=query(id, rson, mid+1, r, ll, rr);
	ret.max=max(tmp.max, ret.max); ret.min=min(ret.min, tmp.min);
	return ret;
}

int main()
{
	while (scanf("%d%d", &N, &M)==2)
	{
		for (int i=1; i<=N; i++)
			build(i, 1, 1, M);
		scanf("%d", &Q);
		while (Q--)
		{
			char opt[10];
			int x1, y1, x2, y2, val;
			scanf("%s%d%d", opt, &x1, &y1);
			if (opt[0]=='q')
			{
				scanf("%d%d", &x2, &y2);
				node ret;
				ret.max=-inf; ret.min=inf;
				for (int i=x1; i<=x2; i++)
				{
					node tmp=query(i, 1, 1, N, y1, y2);
					ret.max=max(ret.max, tmp.max);
					ret.min=min(ret.min, tmp.min);
				}
				printf("%d %d\n", ret.max, ret.min);
			}
			else
			{
				scanf("%d", &val);
				modify(x1, 1, 1, N, y1, val);
			}
		}
	}
}
