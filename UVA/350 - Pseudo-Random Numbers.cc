#include <cstdio>
#include <cstring>

const int MAXN=10000;

bool hash[MAXN];

int main()
{
    int Z,I,M,L;
    int cas=0;
    while (scanf("%d%d%d%d",&Z,&I,&M,&L)==4&&M)
    {
	memset(hash,0,sizeof(hash));
	int len=0;
	while (1)
	{
	    L=(Z*L+I)%M;
	    len++;
	    if (hash[L]) break;
	    hash[L]=1;
	}
	printf("Case %d: %d\n",++cas,len-1);
    }
    return 0;
}
