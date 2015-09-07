#include <cstdio>
#include <cstring>
#define SIZE 55

int main()
{
	int test,n,m;
	char a[SIZE][SIZE];
	char s[SIZE];

	scanf("%d",&test);
	while (test--)
	{
		scanf("%d%d\n",&n,&m);
		for (int i=1; i<=n; i++)
		{
			for (int j=1; j<=m; j++)
			{
				a[i][j]=getchar();
				if (a[i][j]>='A'&&a[i][j]<='Z')
					a[i][j]=a[i][j]+'a'-'A';
			}
			getchar();
		}
		int k;
		scanf("%d\n",&k);
		while (k--)
		{
			scanf("%s",s);
			int len=strlen(s);
			bool flag;
			int i,j,l;

            for (int l=0; l<len; l++)
                if (s[l]>='A'&&s[l]<='Z')
                    s[l]=s[l]+'a'-'A';

			for (i=1; i<=n; i++)
			{
				for (j=1; j<=m; j++)
				{
					for (flag=true,l=0; l<len; l++)
					{
						if (i+l>n||a[i+l][j]!=s[l])
						{
							flag=false;
							break;
						}
					}
					if (flag) break;
					for (flag=true,l=0; l<len; l++)
					{
						if (j+l>m||a[i][j+l]!=s[l])
						{
							flag=false;
							break;
						}
					}
					if (flag) break;
					for (flag=true,l=0; l<len; l++)
					{
						if (i-l<1||a[i-l][j]!=s[l])
						{
							flag=false;
							break;
						}
					}
					if (flag) break;
					for (flag=true,l=0; l<len; l++)
					{
						if (j-l<1||a[i][j-l]!=s[l])
						{
							flag=false;
							break;
						}
					}
					if (flag) break;
					for (flag=true,l=0; l<len; l++)
					{
						if (i+l>n||j+l>m||a[i+l][j+l]!=s[l])
						{
							flag=false;
							break;
						}
					}
					if (flag) break;
					for (flag=true,l=0; l<len; l++)
					{
						if (i+l>n||j-l<1||a[i+l][j-l]!=s[l])
						{
							flag=false;
							break;
						}
					}
					if (flag) break;
					for (flag=true,l=0; l<len; l++)
					{
						if (i-l<1||j+l>m||a[i-l][j+l]!=s[l])
						{
							flag=false;
							break;
						}
					}
					if (flag) break;
					for (flag=true,l=0; l<len; l++)
					{
						if (i-l<1||j-l<1||a[i-l][j-l]!=s[l])
						{
							flag=false;
							break;
						}
					}
					if (flag) break;
				}
				if (flag) break;
			}
			printf("%d %d\n",i,j);
		}
		if (test) printf("\n");
	}
	return 0;
}
