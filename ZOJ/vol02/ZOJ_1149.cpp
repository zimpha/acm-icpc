#include <cstdio>
#include <cstring>

const int MAXW=60005;
const int MAXN=20000;

bool f[MAXW];
int w[MAXN];
int s[6];
int n,m;

void divide(int sum, int per)
{
    if (sum==0) return;
    int p=1;
    while (sum>=p)
    {
	w[n++]=p*per;
	sum-=p;
	p*=2;
    }
    if (sum) w[n++]=sum*per;
}

int main()
{
    int cas=0;
    while (scanf("%d%d%d%d%d%d",s+0,s+1,s+2,s+3,s+4,s+5)==6)
    {
	m=s[0]+s[1]*2+s[2]*3+s[3]*4+s[4]*5+s[5]*6;
	if (m==0) break;
	printf("Collection #%d:\n",++cas);
	if (m&1)
	{
	    printf("Can't be divided.\n\n");
	    continue;
	}
	n=0; m>>=1;
	for (int i=0; i<6; i++)
	    divide(s[i],i+1);
	memset(f,0,sizeof(f));
	f[0]=true;
	for (int i=0; i<n; i++)
	    for (int j=m; j>=w[i]; j--)
		f[j]|=f[j-w[i]];
	if (f[m]) printf("Can be divided.\n\n");
	else printf("Can't be divided.\n\n");
    }
    return 0;
}
