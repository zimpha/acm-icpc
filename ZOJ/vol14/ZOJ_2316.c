#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 10010

int N, n, m, ans;
int d[MAXN];

int main()
{
    int i, x, y;

    scanf("%d", &N);

    while (N)
    {
        scanf("%d%d",&n, &m);
        ans=2*m;
        memset(d,0,sizeof(d));
        for (i=0; i<m; i++)
        {
            scanf("%d%d",&x, &y);
            d[x]++; d[y]++;
        }
        for (i=1; i<=n; i++) ans+=d[i]*(d[i]-1);
        printf("%d\n",ans);
        N--;
        if (N) printf("\n");
    }
    return 0;
}
