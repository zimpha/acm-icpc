#include <stdio.h>
typedef char str[60];

str s[110];
int sort[110],id[110];
int n,m;

int main()
{
    int i,j,k;
	int T; scanf("%d", &T);
    while (T --) {
		scanf("%d%d\n",&n,&m);
		for (i=1;i<=m;i++)
        {
            id[i]=i;
            scanf("%s",s[i]);
            sort[i]=0;
            for (j=0;j<n;j++)
                for (k=j+1;k<n;k++)
                    if (s[i][j]>s[i][k]) sort[i]++;
        }
        for (i=1;i<=m;i++)
            for (j=1;j<=m-i;j++)
                if (sort[j]>sort[j+1])
                {
                    sort[0]=sort[j]; sort[j]=sort[j+1]; sort[j+1]=sort[0];
                    id[0]=id[j]; id[j]=id[j+1]; id[j+1]=id[0];
                }
        for (i=1;i<=m;i++) printf("%s\n",s[id[i]]);
		if (T) puts("");
    }
    return 0;
}

