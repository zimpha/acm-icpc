#include <cstdio>
#include <cstring>

const int MAXN=105;

int x[MAXN],y[MAXN];
int n;

void solve()
{
    for (int a=-500; a<=500; a++)
	for (int b=-500; b<=500; b++)
	{
	    int left=0, right=0;
	    for (int i=0; i<n; i++)
	    {
		int ret=a*x[i]+b*y[i];
		if (ret<0) left++;
		else if (ret>0) right++;
		else break;
	    }
	    if (left==n/2&&right==n/2)
	    {
		printf("%d %d\n",a,b);
		return;
	    }
	}
}

int main()
{
    while (scanf("%d",&n)==1&&n)
    {
	n<<=1;
	for (int i=0; i<n; i++)
	    scanf("%d%d",x+i,y+i);
	solve();
    }
    return 0;
}
