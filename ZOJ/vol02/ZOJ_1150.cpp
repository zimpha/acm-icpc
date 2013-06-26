#include <cstdio>
#include <cstring>

const int MAXN=10;

char value[1<<MAXN];
char vva[MAXN];
int order[MAXN];
int n,m;

int main()
{
    int cas=0;
    while (scanf("%d",&n)==1&&n)
    {
	for (int i=1; i<=n; i++)
	{
	    getchar(); getchar();
	    scanf("%d",order+i);
	}
	getchar();
	scanf("%s",value);
	scanf("%d",&m);
	printf("S-Tree #%d:\n",++cas);
	while (m--)
	{
	    getchar();
	    scanf("%s",vva+1);
	    int pos=0;
	    for (int i=1; i<=n; i++)
		pos=pos*2+vva[i]-'0';
	    printf("%c",value[pos]);
	}
	printf("\n\n");
    }
    return 0;
}
