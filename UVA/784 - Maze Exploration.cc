#include <cstdio>
#include <cstring>

const int MAXN=35;
const int MAXM=85;

char map[MAXN][MAXM];
int len[MAXN];
int n,sx,sy;

void fill(int x,int y)
{
    map[x][y]='#';
    if (x>1&&y<len[x-1]&&map[x-1][y]==' ') fill(x-1,y);
    if (x<n&&y<len[x+1]&&map[x+1][y]==' ') fill(x+1,y);
    if (y>0&&map[x][y-1]==' ') fill(x,y-1);
    if (y+1<len[x]&&map[x][y+1]==' ') fill(x,y+1);
}

int main()
{
    int test;
    scanf("%d\n",&test);
    while (test--)
    {
	n=1;
	memset(map,0,sizeof(map));
	while (gets(map[n])&&map[n][0]!='_')
	{
	    len[n]=strlen(map[n]);
	    for (int i=0; i<len[n]; i++)
		if (map[n][i]=='*')
		{
		    sx=n; sy=i;
		    break;
		}
	    n++;
	}
	n--;
	fill(sx,sy);
	for (int i=1; i<=n+1; i++)
	    puts(map[i]);
    }
    return 0;
}
