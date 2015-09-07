#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN=211;
const char cv[6]={"AUEOI"};
const char cc[22]={"JSBKTCLDMVNWFXGPYHQZR"};

char v[MAXN],c[MAXN];
int n,tv,tc;

bool cmp(char a,char b)
{
    return (a<b);
}

int main()
{
    int test;
    scanf("%d",&test);
    for (int cas=1; cas<=test; cas++)
    {
	scanf("%d",&n);
	tv=tc=0;
	for (int i=0; i<n; i++)
	    if (i&1) c[tc]=cc[tc/5], tc++;
	    else v[tv]=cv[tv/21], tv++;
	std::sort(c,c+tc,cmp);
	std::sort(v,v+tv,cmp);
	tc=tv=0;
	printf("Case %d: ",cas);
	for (int i=0; i<n; i++)
	    if (i&1) putchar(c[tc++]);
	    else putchar(v[tv++]);
	putchar('\n');
    }
    return 0;
}
