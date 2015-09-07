#include <string>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#define lson (rt<<1)
#define rson (rt<<1|1)
#define mid ((l+r)>>1)

using namespace std;

const int MAXN=1024005;
const int SIZE=55;

struct node
{
	int a, b, tag;
	
	node() : a(0), b(0), tag(0) {}
	node(int a) : a(a), b(0), tag(0) {}
	node(int a, int b) : a(a), b(b), tag(0) {}
	
	node change(int t)
	{
		if (t==1) b+=a, a=0, tag=1;
		else if (t==2) a+=b, b=0, tag=2;
		else if (t==3)
		{
			tag=3-tag;
			swap(a, b);
		}
		return *this;
	}
	
	node operator +(node x)
	{
		return node(a+x.a, b+x.b);
	}
};

struct Segtree
{
	node T[MAXN*4];
	int N;
	
	node build(int rt, int l, int r, int *P)
	{
		if (l==r) return T[rt]=node(1-P[l], P[l]);
		else return 
			T[rt]=build(lson, l, mid, P)+build(rson, mid+1, r, P);
	}
	
	node update(int rt, int l, int r, int ll, int rr, int carry, int inc)
	{
		T[rt].change(carry);
		if (ll>r||rr<l) return node(0);
		if (ll<=l&&rr>=r) return T[rt].change(inc);
		
		node ret=
			update(lson, l, mid, ll, rr, T[rt].tag, inc)+
			update(rson, mid+1, r, ll, rr, T[rt].tag, inc);
		T[rt]=T[lson]+T[rson];
		return ret;
	}
	
	node update(int l, int r, int inc)
	{
		return update(1, 0, N, l, r, 0, inc);
	}
	
	node query(int l, int r)
	{
		return update(l, r, 0);
	}
};

Segtree T;
int P[MAXN];
int M, Q, N;

int main()
{
	int test;
	cin >> test;
	for (int cas=1; cas<=test; cas++)
	{
		cin >> M;
		N=-1;
		for (int t, i=0; i<M; i++)
		{
			string str;
			cin >> t >> str;
			for (int j=0; j<t; j++)
				for (int k=0; k<str.size(); k++)
					P[++N]=(str[k]-'0');
		}
		scanf("%d", &Q);
		T.N=N;
		T.build(1, 0, N, P);
		cout << "Case " << cas << ":" << endl;
		for (int l, r, i=1, q=0; i<=Q; i++)
		{
			char opt;
			cin >> opt >> l >> r;
			if (opt=='F') T.update(l, r, 1);
			else if (opt=='E') T.update(l, r, 2);
			else if (opt=='I') T.update(l, r, 3);
			else
			{
				node ret=T.query(l, r);
				cout << "Q" << ++q << ": " << ret.b << endl;
			}
		}
	}
	return 0;
}
