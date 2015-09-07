#include <cmath>
#include <cstdio>
#include <cstring>

const int MAXN=5005;

struct point
{
    int x,y,z;
};

int count[10];
point p[MAXN];
int n;

int main()
{
    n=0;
    while (scanf("%d%d%d",&p[n].x,&p[n].y,&p[n].z)&&(p[n].x||p[n].y||p[n].z)) n++;
    memset(count,0,sizeof(count));
    for (int i=0; i<n; i++)
    {
	int min=-1;
	for (int j=0; j<n; j++)
	    if (i!=j)
	    {
		int tmp=(p[i].x-p[j].x)*(p[i].x-p[j].x);
		tmp+=(p[i].y-p[j].y)*(p[i].y-p[j].y)+(p[i].z-p[j].z)*(p[i].z-p[j].z);
		tmp=(int)sqrt(tmp);
		if (min==-1||tmp<min) min=tmp;
	    }
	if (min<10) count[min]++;
    }
    for (int i=0; i<10; i++)
	printf("%4d",count[i]);
    printf("\n");
    return 0;    
}
