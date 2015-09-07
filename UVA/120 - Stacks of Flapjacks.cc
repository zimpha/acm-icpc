#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>

const int MAXN=35;

int a[MAXN],ans[MAXN];
int n;

void flip(int x)
{
    int tmp;
    for (int i=0,j=x; j>i; j--,i++)
    {
	tmp=a[i];
	a[i]=a[j];
        a[j]=tmp;
    }
}

int main()
{
    while (scanf("%d",&a[0])==1)
    {
	n=1;
	while(1)
	{
	    if (getchar()!=' ') break;
	    scanf("%d",&a[n++]);
	}
	for (int i=0; i<n; i++)
	    printf("%d%c",a[i],(i==n-1)?'\n':' ');
	int pv=0;
	for (int i=0; i<n; i++)
	{
	    int p,max=-10000;
	    for (int j =n-i-1; j>=0; j--)
		if (max<a[j])
		{
		    max=a[j];
		    p=j;
		}
	    if (p!=n-i-1)
	    {
	        if (p!=0)
	        {
		    flip(p);
		    ans[pv++]=n-p;
		}
		flip(n-i-1);
		ans[pv++]=i+1;
	    }
	}
	if (pv==0) printf("%d\n",0);
	else
	{
	    for (int i=0; i<pv; i++)
		printf("%d ",ans[i]);
	    printf("%d\n",0);
	}
    }
    return 0;
}
