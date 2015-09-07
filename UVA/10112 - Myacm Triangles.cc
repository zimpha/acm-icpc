#include <cmath>
#include <cstdio>

const int MAXN=20;

struct point
{
   int x,y;
};

point a[MAXN];

double area(point a,point b,point c)
{
   return fabs(0.5*((c.y-a.y)*(b.x-a.x)-(b.y-a.y)*(c.x-a.x)));
}

bool inside(point a,point b,point c,point d)
{
   return (area(a,b,c)==area(a,b,d)+area(a,c,d)+area(b,c,d));
}

int main()
{
    int n;
    while (scanf("%d",&n)&&n)
    {
	double max=-1;
	int x,y,z;
	for (int i=0; i<n; i++)
	{
	    char c; getchar();
	    scanf("%c%d%d",&c,&a[i].x,&a[i].y);
	}
	for (int i=0; i<n; i++)
	{
	    for (int j=i+1; j<n; j++)
	    {
		for (int k=j+1; k<n; k++)
		{
		    bool flag=true;
		    for (int p=0; p<n; p++)
		    {
			if (p==i||p==j||p==k) continue;
			if (inside(a[i],a[j],a[k],a[p]))
			{
			    flag=false;
			    break;
			    
			}
		    }
		    if (flag&&max<area(a[i],a[j],a[k]))
		    {
			max=area(a[i],a[j],a[k]);
			x=i; y=j; z=k;
		    }
		}
	    }
	}
	printf("%c%c%c\n",'A'+x,'A'+y,'A'+z);
    }
    return 0;
}
