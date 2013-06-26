#include <cstdio>
#include <cstring>

const int MAXN=1005;

struct node
{
    int id,time,delta;
};

node h[MAXN];
int n;

void push(node a)
{
    n++; h[n]=a;
    int i=n;
    while (i>>1)
    {
	if (h[i].time<h[i>>1].time||(h[i].time==h[i>>1].time&&h[i].id<h[i>>1].id))
	{
	    node tmp=h[i];
	    h[i]=h[i>>1];
	    h[i>>1]=tmp;
	}
	else break;
	i>>=1;
    }
}

void sink()
{
    int i=1; 
    while ((i<<1)<=n)
    {
	i<<=1;
	if (i<n&&(h[i].time>h[i+1].time||(h[i].time==h[i+1].time&&h[i].id>h[i+1].id))) i++;
	if (h[i].time<h[i>>1].time||(h[i].time==h[i>>1].time&&h[i].id<h[i>>1].id))
	{
	    node tmp=h[i];
	    h[i]=h[i>>1];
	    h[i>>1]=tmp;
	}
	else break;
    }
}

int main()
{
    char s[20]; n=0;
    while (scanf("%s",s)&&s[0]!='#')
    {
	node a;
	scanf("%d%d",&a.id,&a.time);
	a.delta=a.time;
	push(a);
    }
    int k;
    scanf("%d",&k);
    while (k--)
    {
	printf("%d\n",h[1].id);
	h[1].time+=h[1].delta;
	sink();
    }
    return 0;
}
