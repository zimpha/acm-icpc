#include <stdio.h>
#include <math.h>
#define MAXN 210
#define e 1e-6
#define PI 3.1415926
#define R 2.5

typedef struct
{
    double x,y;
}point;

point a[MAXN];
int n;

double dis(point a,point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

point find(point a,point b)
{
    point d,m,o;
    double alpha,h;
    m.x=(a.x+b.x)/2.0; m.y=(a.y+b.y)/2.0;
    d.x=b.x-a.x; d.y=a.y-b.y;
    if (fabs(d.y)<e) alpha=PI/2;
    else alpha=atan(d.x/d.y);
    h=sqrt(R*R-dis(a,m)*dis(a,m));
    o.x=m.x+h*cos(alpha);
    o.y=m.y+h*sin(alpha);
    return o;
}

int main()
{
	char buff[1000];
	int i,j,k;
    int ans;
    int count;
    point center;
    n=0;
	while (gets(buff))
	{
		if (buff[0]=='\0')
		{
       		ans=1;
   			for (i=0;i<n;i++)
        		for (j=0;j<n;j++)
        		{
           	 		if (i==j) continue;
            		if (dis(a[i],a[j])-R*2>e) continue;
            		center=find(a[i],a[j]);
            		if (fabs(center.x-R)<e) continue;
            		if (fabs(center.y-R)<e) continue;
            		if (center.x+R>50) continue;
            		if (center.y+R>50) continue;
            		count=0;
            		for (k=0;k<n;k++)
                		if (dis(center,a[k])-R<=e) count++;
            		if (count>ans) ans=count;
       			}
    		printf("%d\n",ans);
    		n=0;
   		}
   		else
   		{
   			sscanf(&buff[0], "%lf%lf",&a[n].x,&a[n].y);
   			n++;
   		}
   	}
   	ans=1;
   			for (i=0;i<n;i++)
        		for (j=0;j<n;j++)
        		{
           	 		if (i==j) continue;
            		if (dis(a[i],a[j])-R*2>e) continue;
            		center=find(a[i],a[j]);
            		if (fabs(center.x-R)<e) continue;
            		if (fabs(center.y-R)<e) continue;
            		if (center.x+R>50) continue;
            		if (center.y+R>50) continue;
            		count=0;
            		for (k=0;k<n;k++)
                		if (dis(center,a[k])-R<=e) count++;
            		if (count>ans) ans=count;
       			}
    		printf("%d\n",ans);
    return 0;
}
