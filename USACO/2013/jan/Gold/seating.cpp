#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXN 500005

struct node
{
	int ml, mr, max;
	int tag, len;
};

node tree[MAXN*4];
int N, M;

void build_tree(int l, int r, int rt)
{
	tree[rt].ml=tree[rt].mr=tree[rt].max=r-l+1;
	tree[rt].tag=-1; tree[rt].len=r-l+1;
	int mid=(l+r)>>1;
	if (l!=r) 
	{
		build_tree(l, mid, rt<<1);
		build_tree(mid+1, r, rt<<1|1);
	}
}

void pushdown(int rt)
{
	if (tree[rt].tag==0)
	{
		tree[rt].tag=-1;
		tree[rt<<1].tag=tree[rt<<1|1].tag=0;
		tree[rt<<1].ml=tree[rt<<1].mr=tree[rt<<1].max=tree[rt<<1].len;
		tree[rt<<1|1].ml=tree[rt<<1|1].mr=tree[rt<<1|1].max=tree[rt<<1|1].len;
	}
	else
	{
		tree[rt].tag=-1;
		tree[rt<<1].tag=tree[rt<<1|1].tag=1;
		tree[rt<<1].ml=tree[rt<<1].mr=tree[rt<<1].max=0;
		tree[rt<<1|1].ml=tree[rt<<1|1].mr=tree[rt<<1|1].max=0;
	}
}

void update(int rt)
{
	tree[rt].tag=-1;
	node ls=tree[rt<<1];
	node rs=tree[rt<<1|1];
	if (ls.len==ls.max) tree[rt].ml=ls.len+rs.ml;
	else tree[rt].ml=ls.ml;
	if (rs.len==rs.max) tree[rt].mr=rs.len+ls.mr;
	else tree[rt].mr=rs.mr;
	tree[rt].max=max(max(ls.max, rs.max), max(ls.mr+rs.ml, max(tree[rt].ml, tree[rt].mr)));
}

int query(int l, int r, int rt, int len)
{
	if (tree[rt].ml>=len) 
		return l;
	if (tree[rt].tag!=-1) 
		pushdown(rt);
	int mid=(l+r)>>1;
	if (tree[rt<<1].max>=len) 
		return query(l, mid, rt<<1, len);
	if (tree[rt<<1].mr+tree[rt<<1|1].ml>=len) 
		return mid-tree[rt<<1].mr+1;
	return query(mid+1, r, rt<<1|1, len);
}

void clear(int l, int r, int rt, int ll, int rr)
{
	if (ll<=l&&rr>=r)
	{
		tree[rt].ml=tree[rt].mr=tree[rt].max=tree[rt].len;
		tree[rt].tag=0;
		return;
	}
	if (tree[rt].tag!=-1) pushdown(rt);
	int mid=(l+r)>>1;
	if (ll<=mid) clear(l, mid, rt<<1, ll, rr);
	if (rr>mid) clear(mid+1, r, rt<<1|1, ll, rr);
	update(rt);
}

void cover(int l, int r, int rt, int ll, int rr)
{
	if (ll<=l&&rr>=r)
	{
		tree[rt].ml=tree[rt].mr=tree[rt].max=0;
		tree[rt].tag=1;
		return;
	}
	if (tree[rt].tag!=-1) pushdown(rt);
	int mid=(l+r)>>1;
	if (ll<=mid) cover(l, mid, rt<<1, ll, rr);
	if (rr>mid) cover(mid+1, r, rt<<1|1, ll, rr);
	update(rt);
}

int main()
{
	freopen("seating.in", "r", stdin);
	freopen("seating.out", "w", stdout);
	scanf("%d%d\n", &N, &M);
	build_tree(1, N, 1);
	int ret=0;
	while (M--)
	{
		char ch;
		int a, b;
		scanf("%c", &ch);
		if (ch=='A')
		{
			scanf("%d", &a);
			getchar();
			if (tree[1].max<a) ret++;
			else
			{
				int pos=query(1, N, 1, a);
				cover(1, N, 1, pos, pos+a-1);
			}
		}
		else
		{
			scanf("%d%d", &a, &b);
			getchar();
			clear(1, N, 1, a, b);
		}
	}
	printf("%d\n", ret);
	fclose(stdin); fclose(stdout);
	return 0;
}
