#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN=1005;
const int MAXT=10;

int milk[MAXN][MAXT];
bool eaten[MAXN];
int len[MAXN];
int n,day;

int gcd(int a,int b)
{
    if (b==0) return a;
    else return gcd(b,a%b);
}

int main()
{
    int test;
    scanf("%d",&test);
    while (test--)
    {
	scanf("%d",&n);
	int T=1; day=0;
	for (int i=1; i<=n; i++)
	{
	    scanf("%d",&len[i]);
	    for (int j=0; j<len[i]; j++)
		scanf("%d",&milk[i][j]);
	    int tmp=gcd(T,len[i]);
	    T=T*len[i]/tmp;
	}
	int ans1=n,ans2=0,p=0;
	memset(eaten,0,sizeof(eaten));
	while (1)
	{
	    bool flag=false;
	    for (int i=0; i<T; i++)
	    {
		int count=0,cow=0,min=1000;
		for (int j=1; j<=n; j++)
		    if (!eaten[j])
		    {
			if (milk[j][i%len[j]]<min)
		        {
			    min=milk[j][i%len[j]];
			    cow=j; count=1;
			}
			else if (milk[j][i%len[j]]==min) count++;
		    }
		if (count==1)
		{
		    flag=eaten[cow]=1;
		    ans1--; ans2=p*T+i+1;
		}
	    }
	    if (!flag) break;
	    p++;
	}
	printf("%d %d\n",ans1,ans2);
    }
    return 0;
}
