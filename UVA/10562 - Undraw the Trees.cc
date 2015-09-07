#include <cstdio>
#include <cstring>

const int MAXN=205;

char a[MAXN][MAXN];
int n;

void dfs(int row, int col)
{
    for (int i=col; a[row][i]=='-'; i++)
    {
	if (a[row+1][i]!=' '&&a[row+1][i]!='\0')
	{
	    printf("%c(",a[row+1][i]);
	    if (row+1<n&&a[row+2][i]=='|')
	    {
		int j;
		for (j=i; j&&a[row+3][j-1]=='-'; j--);
		dfs(row+3,j);
	    }
	    printf(")");
	}
    }
}

int main()
{
    int test;
    scanf("%d",&test);
    getchar();
    while (test--)
    {
	n=1;
	memset(a,0,sizeof(a));
	while (gets(a[n])&&strcmp(a[n],"#")) 
	    n++;
	n--;
	if (n==0) printf("()\n");
	else
	{
	    for (int i=0; i<strlen(a[1]); i++)
		a[0][i]='-';
	    printf("(");
	    dfs(0,0);
	    printf(")\n");
	}
    }
    return 0;
}
