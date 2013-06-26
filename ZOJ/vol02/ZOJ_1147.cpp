#include <cstdio>
#include <cstring>

const int MAXN=10005;
const int MAXM=85;
const int inf=100000000;

char word[MAXN][MAXM], st[MAXN];
int f[MAXN], len[MAXN], pre[MAXN];
int n, m, cnt;

int calc(int sum, int num)
{
	if (num==1) return 500;
	int p=(m-sum)/(num-1);
	int q=(m-sum)%(num-1);
	return (q*p*p+(num-q-1)*(p-1)*(p-1));
}

int main()
{	
	while (scanf("%d", &m)==1&&m)
	{
		getchar();
		memset(len,0,sizeof(len));
		n=1; cnt=0;
		while (gets(st))
		{
			if (st[0]=='\0') break;
			int l=strlen(st);
			for (int i=0; i<l; i++)
			{
				if (st[i]!=' ') word[n][cnt++]=st[i];
				else if (i&&st[i-1]!=' ')
				{
					len[n]=len[n-1]+cnt;
					word[n][cnt]='\0';
					n++; cnt=0;
				}
			}
			len[n]=len[n-1]+cnt; word[n][cnt]='\0';
			n++; cnt=0;
		}
		memset(f,0,sizeof(f));
		memset(pre,0,sizeof(pre));
		for (int i=n-1; i>0; i--)
		{
			int ret=inf;
			for (int j=1; i+j-1<n&&len[i+j-1]-len[i-1]+j-1<=m; j++)
			{
				int tmp=f[i+j]+calc(len[i+j-1]-len[i-1],j);
				if (tmp<=ret)
				{
					ret=tmp;
					pre[i]=i+j-1;
				}
			}
			f[i]=ret;
		}
		for (int i=1; i<n; i=pre[i]+1)
		{
			if (pre[i]==i)
			{
				printf("%s\n", word[i]);
				continue;
			}
			int p=(m-(len[pre[i]]-len[i-1]))/(pre[i]-i);
			int q=(m-(len[pre[i]]-len[i-1]))%(pre[i]-i);
			for (int j=i; j<pre[i]; j++)
			{
				printf("%s", word[j]);
				for (int k=1; k<=(j-i+1>pre[i]-i-q)+p; k++)
					putchar(' ');
			}
			printf("%s\n", word[pre[i]]);
		}
		puts("");
	}
	return 0;
}
