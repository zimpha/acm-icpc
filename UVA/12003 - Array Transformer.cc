#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int MAXN=300005;
const int SIZE=600;

struct node
{
	int l, r, size;
};

node blk[SIZE];
int pos[MAXN];
int A[MAXN], B[MAXN];
int N, M, P, U, Q;

int main()
{
	scanf("%d%d%d", &N, &Q, &U);
	P=sqrt(N); M=0;
	for (int i=0; i<N; i++)
	{
		scanf("%d", &A[i]);
		pos[i]=i/P;
		if (i%P==0)
		{
			blk[M].l=i, blk[M].r=min(N, i+P);
			blk[M].size=blk[M].r-blk[M].l;
			M++;
		}
	}
	memcpy(B, A, sizeof(A));
	for (int i=0; i<M; i++) sort(B+blk[i].l, B+blk[i].r);
	while (Q--)
	{
		int l, r, v, p;
		int ret=0;
		scanf("%d%d%d%d", &l, &r, &v, &p);
		l--, r--, p--;
		int pl=pos[l], pr=pos[r];
		if (pl==pr)
		{
			for (int i=l; i<=r; i++) ret+=(A[i]<v);
		}
		else
		{
			for (int i=l; i<blk[pl].r; i++) ret+=(A[i]<v);
			for (int i=blk[pr].l; i<=r; i++) ret+=(A[i]<v);
			for (int i=pl+1; i<pr; i++)
			{
				int k=lower_bound(B+blk[i].l, B+blk[i].r, v)-(B+blk[i].l);
				ret+=k;
			}
		}
		int pp=pos[p];
		A[p]=(long long)U*ret/(r-l+1);
		memcpy(B+blk[pp].l, A+blk[pp].l, sizeof(int)*blk[pp].size);
		sort(B+blk[pp].l, B+blk[pp].r);
	}
	for (int i=0; i<N; i++)
		printf("%d\n", A[i]);
	return 0;
}
