#include <cstdio>
#include <cstring>

const int MAXN=205;

int a[MAXN], b[MAXN];
int n, m;

int main()
{
	char s[MAXN];
	while (scanf("%s", s)==1)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		int n=strlen(s);
		for (int i=0; i<n; i++)
		{
			int dig;
			if (s[i]>='0'&&s[i]<='9') dig=s[i]-'0';
			else dig=s[i]-'a'+10;
			a[n-i]=dig;
		}
		scanf("%s", s); m=strlen(s);
		for (int i=0; i<m; i++)
		{
			int dig;
			if (s[i]>='0'&&s[i]<='9') dig=s[i]-'0';
			else dig=s[i]-'a'+10;
			b[m-i]=dig;
		}
		if (m>n) n=m; m=0;
		for (int i=1; i<=n; i++)
		{
			a[i]+=b[i]+m;
			m=a[i]/20;
			a[i]%=20;
		}
		if (m) a[++n]=m;
		for (int i=n; i>0; i--)
		{
			if (a[i]<10) putchar('0'+a[i]);
			else putchar('a'+a[i]-10);
		}
		puts("");
	}
	return 0;
}
