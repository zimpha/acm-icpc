#include <cstdio>
#include <cctype>
#include <cstring>

const int MAXN=300;

char str[MAXN];
bool s[MAXN];
int n, top;

int main()
{
	int test;
	scanf("%d", &test);
	getchar();
	while (test--)
	{
		char pre;
		int m=0;
		gets(str);
		n=strlen(str);
		top=0; pre='+';
		for (int i=0; i<n; i++)
		{
			if (str[i]==' ') ;
			else if (isalpha(str[i])) str[m++]=str[i];
			else if (str[i]=='-'||str[i]=='+')
			{
				pre=str[i];
				str[m++]=str[i];
			}
			else if (str[i]=='(')
			{
				top++;
				if (pre=='-')
				{
					str[m++]=str[i];
					s[top]=true;
				}
				else s[top]=false;
				pre='(';
			}
			else
			{
				if (s[top]) str[m++]=str[i];
				top--;
			}
		}
		n=m;
		for (int i=0; i<n; i++)
			if (str[i]=='(')
			{
				if (str[i+2]!=')') putchar(str[i]);
			}
			else if (str[i]==')')
			{
				if (str[i-2]!='(') putchar(str[i]);
			}
			else putchar(str[i]);
		puts("");
	}
	return 0;
}
