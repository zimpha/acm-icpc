#include <cstdio>
#include <cstring>

const int MAXN=100005;

char s1[MAXN], s2[MAXN];
int n, m;

int main()
{
	while (scanf("%s%s", s1, s2)==2)
	{
		n=strlen(s1);
		m=strlen(s2);
		bool flag=true;
		if (n>m) flag=false;
		if (flag)
		{
			int i=0, j=0;
			while (1)
			{
				if (s1[i]==s2[j]) i++, j++;
				else j++;
				if (i==n) break;
				if (j==m) 
				{
					flag=false;
					break;
				}
			}
		}
		if (flag) puts("Yes");
		else puts("No");
	}
	return 0;
}
