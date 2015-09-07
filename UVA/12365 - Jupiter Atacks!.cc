#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#define lson (rt<<1)
#define rson (rt<<1|1)
#define mid ((l+r)>>1)

typedef long long LL;

const int MAXN=100005;

LL PA[MAXN], PB[MAXN];
LL tree[MAXN*4];
int N, M, B, P;

LL power(LL a, LL b, LL P)
{
	if (b==0ll) return 1ll;
	LL ret=power(a, b>>1ll, P)%P;
	if (b&1ll) return ret*ret%P*a%P;
	else return ret*ret%P;
}

void build(int rt, int l, int r)
{
	tree[rt]=0;
	if (l==r) return;
	build(lson, l, mid);
	build(rson, mid+1, r);
}

void modify(int rt, int l, int r, int k, int val)
{
	if (l==r)
	{
		tree[rt]=(LL)val*PA[l]%P;
		return;
	}
	if (k<=mid) modify(lson, l, mid, k, val);
	else modify(rson, mid+1, r, k, val);
	tree[rt]=(tree[lson]+tree[rson])%P;
}

LL query(int rt, int l, int r, int ll, int rr)
{
	if (ll<=l&&rr>=r) return tree[rt];
	LL ret=0;
	if (ll<=mid) ret=(ret+query(lson, l, mid, ll, rr))%P;
	if (rr>mid) ret=(ret+query(rson, mid+1, r, ll, rr))%P;
	return ret%P;
}

int main()
{
	while (scanf("%d%d%d%d", &B, &P, &N, &M)==4&&N>0)
	{
		PA[0]=PB[0]=1ll;
		for (int i=1; i<=N; i++)
		{
			PB[i]=PB[i-1]*B%P;
			PA[i]=power(PB[i], P-2, P);
		}
		build(1, 1, N);
		while (M--)
		{
			char opt[10];
			int l, r;
			scanf("%s%d%d", opt, &l, &r);
			if (opt[0]=='E') modify(1, 1, N, l, r);
			else 
			{
				LL ret=query(1, 1, N, l, r)%P;
				ret=ret*PB[r]%P;
				printf("%lld\n", ret);
			}
		}
		puts("-");
	}
	return 0;
}
