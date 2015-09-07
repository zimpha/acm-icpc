#include <map>
#include <set>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int MAXN=50005;
const int SIZE=1000005;

struct node
{
	int l, r, size;
};

set<int> pos1[SIZE], pos2[SIZE];
node blk[MAXN];
int pre[SIZE];
int A[MAXN], F[MAXN], B[MAXN], own[MAXN];
int N, Q, M, L, cnt;

inline void change(int x, int v)
{
	int px=own[x]; F[x]=v;
	memcpy(B+blk[px].l, F+blk[px].l, sizeof(int)*blk[px].size);
	sort(B+blk[px].l, B+blk[px].r);
}

int main()
{
	for (int i=0; i<SIZE; i++) pos1[i].clear(), pos2[i].clear();
	memset(pre, -1, sizeof(pre));
	scanf("%d%d", &N, &Q); L=sqrt(N)+1; M=0;
	for (int i=0; i<N; i++)
	{
		own[i]=i/L;
		scanf("%d", &A[i]); F[i]=pre[A[i]];
		pos1[A[i]].insert(i); pos2[A[i]].insert(-i);
		if (i%L==0)
		{
			blk[M].l=i; blk[M].r=min(N, i+L);
			blk[M].size=blk[M].r-blk[M].l; M++;
		}
		pre[A[i]]=i;
	}
	memcpy(B, F, sizeof(F));
	for (int i=0; i<M; i++) sort(B+blk[i].l, B+blk[i].r);
	while (Q--)
	{
		char st[10];
		int x, y, px, py, ret=0;
		scanf("%s%d%d", st, &x, &y);
		if (st[0]=='M')
		{
			if (A[x]==y) continue;
			set<int>::iterator it1, it2;
			int p1, p2;
			it1=pos1[A[x]].upper_bound(x); it2=pos2[A[x]].upper_bound(-x);
			if (it1!=pos1[A[x]].end())
			{
				p1=*it1;
				if (it2==pos2[A[x]].end()) p2=-1;
				else p2=-(*it2);
				change(p1, p2);
			}
			pos1[A[x]].erase(x); pos2[A[x]].erase(-x);
			pos1[y].insert(x); pos2[y].insert(-x);
			it1=pos1[y].upper_bound(x); it2=pos2[y].upper_bound(-x);
			if (it1!=pos1[y].end()) change(*it1, x);
			if (it2==pos2[y].end()) p2=-1;
			else p2=-(*it2);
			change(x, p2);
			A[x]=y;
		}
		else
		{
			y--; px=own[x], py=own[y];
			if (px==py)
			{
				for (int i=x; i<=y; i++) ret+=(F[i]<x);
			}
			else
			{
				for (int i=x; i<blk[px].r; i++) ret+=(F[i]<x);
				for (int i=blk[py].l; i<=y; i++) ret+=(F[i]<x);
				for (int i=px+1; i<py; i++)
					ret+=lower_bound(B+blk[i].l, B+blk[i].r, x)-(B+blk[i].l);
			}
			printf("%d\n", ret);
		}
	}
	return 0;
}
