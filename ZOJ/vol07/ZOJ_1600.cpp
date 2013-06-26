#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

const int MAXN=205;

int pri[MAXN], price[MAXN], p[MAXN], bk[MAXN];
int n;

int count(int k,int p)
{
	for (int i=0; i<k; i++) pri[i]=price[i];
	for (int i=k; i<n; i++) pri[i+1]=price[i];
	pri[k]=p;
    
	int index=0, profit=0;
	for (int i=0; i<n; i++)
	{
		if (pri[i]<=pri[index]) index=i;
		if (index>k) break;
		if (index==k) profit+=bk[i];
	}
	index=n;
	for (int i=n; i>0; i--)
	{
		if (pri[i]<=pri[index]) index=i;
		if (index<k) break;
		if (index==k) profit+=bk[n-i];
	}
	return p*profit;
}

int main()
{
	while (scanf("%d", &n)==1)
	{
	for (int i=0; i<n; i++)
	{
		scanf("%d",price+i);
		p[2*i]=price[i]-1;
		p[2*i+1]=price[i];
	}
	for (int i=0; i<n; i++) scanf("%d",bk+i);
    
	std::sort(p,p+2*n);
	int m=1;
    for (int i=1; i<2*n; i++)
		if (p[i]!=p[i-1]) p[m++]=p[i];
		
	int ans=0, pos=1, ret;
	for (int i=1; i<n; i++)
		for (int j=0; j<m; j++)
		{
			int tmp=count(i,p[j]);
			if (tmp>ans)
			{
				ans=tmp;
				pos=i;
				ret=p[j];
			}
		}
	printf("%d %d\n", pos, ret);
	}
	return 0;
}
