#include <cstdio>
#include <cstring>

const int MAXN=105;
const int MAXP=20;

bool hash[1<<16];
int a[MAXN][MAXP];
int pow[MAXP];
int n,p;

int main()
{
    int test;
    for (int i=0; i<MAXP; i++)
	pow[i]=1<<i;
    scanf("%d",&test);
    while (test--)
    {
        scanf("%d%d",&p,&n);
        for (int i=0; i<n; i++)
            for (int j=0; j<p; j++)
                scanf("%d",&a[i][j]);
        int ans=p;
        for (int s=0; s<pow[p]; s++)
        {
            memset(hash,0,sizeof(hash));
            int cur=0;
            for (int i=0; i<p; i++)
                if (s&pow[i]) cur++;
            bool flag=true;
            for (int i=0; i<n; i++)
            {
                int ret=0;
                for (int j=0; j<p; j++)
                    if (s&pow[j]) ret+=pow[j]*a[i][j];
                if (!hash[ret]) hash[ret]=true;
                else
		{
		    flag=false;
                    break;
                }
            }
	    if (flag&&cur<ans) ans=cur;
	}
        printf("%d\n",ans);
    }
    return 0;
}
