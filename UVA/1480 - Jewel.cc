#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN=100000+10;
const int SIZE=22;
int A[MAXN], S[MAXN];
int num[SIZE][MAXN], cnt[SIZE][MAXN];

bool cmp(int i, int j) {return (A[i]<A[j]);}

void build(int l, int r, int d)
{
	if (l==r) return;
	int m=(l+r)>>1, p=0;
	for (int i=l; i<=r; i++)
		if (num[d][i]<=m)
		{
			num[d+1][l+p]=num[d][i];
			cnt[d][i]=++p;
		}
		else
		{
			num[d+1][m+1+i-l-p]=num[d][i];
			cnt[d][i]=p;
		}
	build(l, m, d+1); build(m+1, r, d+1);
}

int query(int l, int r, int d, int ll, int rr, int k)
{
	if (l==r) return l;
	int ls=(ll==l)?0:cnt[d][ll-1];
	int rs=cnt[d][rr];
	int m=(l+r)>>1;
	if (k<=rs-ls) return query(l, m, d+1, l+ls, l+rs-1, k);
	return query(m+1, r, d+1, m+1+(ll-l-ls), m+1+(rr-l-rs), k-(rs-ls));
}

struct node
{
	int type, x, y, k;
}CMD[MAXN];

int main()
{
	int N, M, Q, cas=0;
	while (scanf("%d", &M)==1)
	{
		Q=N=0;
		while (M--)
		{
			char st[30];
			scanf("%s", st);
			if (st[0]=='I')
			{
				N++; S[N]=N;
				scanf("%d", &A[N]);
			}
			else
			{
				CMD[Q].type=st[6]-'1';
				if (st[6]=='1') scanf("%d%d%d", &CMD[Q].x, &CMD[Q].y, &CMD[Q].k);
				else if (st[6]=='2') scanf("%d", &CMD[Q].x), CMD[Q].y=N;
				else if (st[6]=='3')
				{
					CMD[Q].x=1; CMD[Q].y=N;
					scanf("%d", &CMD[Q].k);
				}
				Q++;
			}
		}
		sort(S+1, S+1+N, cmp);
		for (int i=1; i<=N; i++) num[0][S[i]]=i;
		build(1, N, 0);
		long long ret[3]={0, 0, 0};
		for (int i=0; i<Q; i++)
		{
			int x=CMD[i].x, y=CMD[i].y, k=CMD[i].k;
			if (CMD[i].type==0||CMD[i].type==2)
			{
				long long tmp=A[S[query(1, N, 0, x, y, k)]];
				ret[CMD[i].type]+=tmp;
			}
			else
			{
				int l=1, r=y+1;
				while (l<r)
				{
					int m=(l+r)>>1;
					int ret=A[S[query(1, N, 0, 1, y, m)]];
					if (ret>=x) r=m;
					else l=m+1;
				}
				ret[1]+=r;
				//printf("%d\n", r);
			}
		}
		printf("Case %d:\n", ++cas);
		for (int i=0; i<3; i++) printf("%lld\n", ret[i]);
	}
	return 0;
}
