#include <cstdio>
#include <cctype>
#include <cstring>

const int MAXN=30;

int f[MAXN],s[MAXN];
int n;

void initial(int n)
{
    for (int i=0; i<=n; i++)
	f[i]=i, s[i]=-1;
}

void cleartop(int top,int bottom)
{
    while (top!=bottom)
    {
        int tmp=s[top];
        f[top]=top;
        s[top]=-1;
        top=tmp;
    }
    f[bottom]=bottom;
}

int find(int x)
{
    while (x!=f[x]) x=f[x];
    return x;
}

void moveonto(int a,int b)
{
    int fa=find(a), fb=find(b);
    if (fa==fb) return;
    if (s[a]!=-1) f[s[a]]=s[a];
    cleartop(fa,a); cleartop(fb,b);
    s[a]=b; f[b]=a;
}

void moveover(int a,int b)
{
    int fa=find(a), fb=find(b);
    if (fa==fb) return;
    if (s[a]!=-1) f[s[a]]=s[a];
    cleartop(fa,a);
    s[a]=fb; f[fb]=a;
}

void pileonto(int a,int b)
{
    int fa=find(a), fb=find(b);
    if (fa==fb) return;
    cleartop(fb,b);
    if (s[a]!=-1) f[s[a]]=s[a];
    s[a]=b; f[b]=a;
}

void pileover(int a,int b)
{
    int fa=find(a), fb=find(b);
    if (fa==fb) return;
    if (s[a]!=-1) f[s[a]]=s[a];
    s[a]=fb; f[fb]=a;
}

int main()
{
    scanf("%d\n",&n);
    char st[100];
    initial(n);
    while (gets(st)&&strcmp(st,"quit")!=0)
    {
	int a,b;
	char s1[10],s2[10];
	sscanf(&st[0],"%s%d",s1,&a);
	for (int i=5; i<strlen(st); i++)
	    if (isalpha(st[i]))
	    {
		sscanf(&st[i],"%s%d",s2,&b);
		break;
	    }
	if (strcmp(s1,"move")==0)
	    if (strcmp(s2,"onto")==0) moveonto(a,b);
	    else moveover(a,b);
	else
	    if (strcmp(s2,"onto")==0) pileonto(a,b);
	    else pileover(a,b);
    }
    for (int i=0; i<n; i++)
    {
	printf("%d:",i);
	if (s[i]==-1)
	{
	    int j=i;
	    printf(" %d",j);
	    while (j!=f[j])
	    {
		j=f[j];
		printf(" %d",j);
	    }
	}
	printf("\n");
    }
    return 0;
}

