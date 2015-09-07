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

const int MAXN=250005;

struct node
{
	LL add, step, sum, val;
	bool flag;
	
	void changeAB(int l, int r, LL a, LL k)
	{
		LL n=(LL)r-l+1;
		add+=a; step+=k;
		sum+=a*n+n*(n-1)*k/2ll;
	}

	void changeC(int l, int r, LL x)
	{
		flag=true; val=x;
		add=step=0ll;
		sum=x*(r-l+1);
	}
};

node Tr[MAXN*4];

inline void pushdown(int rt, int l, int r)
{
	if (Tr[rt].flag)
	{
		Tr[lson].changeC(l, mid, Tr[rt].val);
		Tr[rson].changeC(mid+1, r, Tr[rt].val);
		Tr[rt].flag=false; Tr[rt].val=0ll;
	}
	if (Tr[rt].add||Tr[rt].step)
	{
		Tr[lson].changeAB(l, mid, Tr[rt].add, Tr[rt].step);
		LL add=Tr[rt].add+Tr[rt].step*(mid-l+1);
		Tr[rson].changeAB(mid+1, r, add, Tr[rt].step);
		Tr[rt].add=Tr[rt].step=0ll;
	}
}

void modifyAB(int rt, int l, int r, int ll, int rr, int add, int step)
{
	if (ll<=l&&rr>=r)
	{
		add+=step*(l-ll);
		Tr[rt].changeAB(l, r, add, step);
		return;
	}
	pushdown(rt, l, r);
	if (ll<=mid) modifyAB(lson, l, mid, ll, rr, add, step);
	if (rr>mid) modifyAB(rson, mid+1, r, ll, rr, add, step);
	Tr[rt].sum=Tr[lson].sum+Tr[rson].sum;
}

void modifyC(int rt, int l, int r, int ll, int rr, int val)
{
	if (ll<=l&&rr>=r)
	{
		Tr[rt].changeC(l, r, val);
		return;
	}
	pushdown(rt, l, r);
	if (ll<=mid) modifyC(lson, l, mid, ll, rr, val);
	if (rr>mid) modifyC(rson, mid+1, r, ll, rr, val);
	Tr[rt].sum=Tr[lson].sum+Tr[rson].sum;
}

LL query(int rt, int l, int r, int ll, int rr)
{
	if (ll<=l&&rr>=r) return Tr[rt].sum;
	pushdown(rt, l, r);
	LL ret=0ll;
	if (ll<=mid) ret+=query(lson, l, mid, ll, rr);
	if (rr>mid) ret+=query(rson, mid+1, r, ll, rr);
	return ret;
}

int main()
{
	int N=250000, M;
	memset(Tr, 0, sizeof(Tr));
	cin >> M;
	while (M--)
	{
		char opt;
		int l, r, x;
		cin >> opt >> l >> r;
		if (opt=='A') modifyAB(1, 1, N, l, r, 1, 1);
		else if (opt=='B') modifyAB(1, 1, N, l, r, r-l+1, -1);
		else if (opt=='C')
		{
			cin >> x;
			modifyC(1, 1, N, l, r, x);
		}
		else cout << query(1, 1, N, l, r) << endl;
	}
	return 0;
}
