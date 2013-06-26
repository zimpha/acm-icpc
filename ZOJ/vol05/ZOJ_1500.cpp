#include <cstdio>
#include <cstring>

const int MAXN=30;
const int MAXM=25;

char s1[MAXN], s2[MAXN];
int c[MAXM][MAXM];
int m;

int com(int n, int m)
{
	if (c[n][m]!=-1) return c[n][m];
	if (!m) c[n][m]=1;
	else if (n==m) c[n][m]=1;
	else c[n][m]=com(n-1,m)+com(n-1,m-1);
	return c[n][m];
}

int calc(int st1, int en1, int st2, int en2)
{
	if (en1-st1==-1) return 1;
	int ret=1, num=0;
	for (; st1<=en1;)
	{
		int tmp;
		for (int i=st2; i<=en2; i++)
			if (s1[st1]==s2[i])
			{
				tmp=i; num++;
				break;
			}
		ret*=calc(st1+1,st1+tmp-st2,st2,tmp-1);
		st1+=tmp-st2+1;
		st2=tmp+1;
	}
	return ret*com(m,num);
}

int main()
{
	while (scanf("%d", &m)==1&&m)
	{
		memset(c,-1,sizeof(c));
		scanf("%s%s", s1, s2);
		int len=strlen(s1);
		int ans=calc(1,len-1,0,len-2);
		printf("%d\n", ans);
	}
	return 0;
}

