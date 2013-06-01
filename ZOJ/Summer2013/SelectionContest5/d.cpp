#include <cstdio>
#include <cstring>

const int MAXN=2005;

char str[MAXN];
char stk[MAXN];
int n, top;

bool match(char a, char b)
{
	if (a=='('&&b==')') return true;
	if (a=='['&&b==']') return true;
	if (a=='{'&&b=='}') return true;
	return false;
}

bool check(int st, int len)
{
	memset(stk, 0, sizeof(stk));
	top=0;
	for (int i=0; i<len; i++)
		if (str[i+st]=='('||str[i+st]=='['||str[i+st]=='{')
		{
			stk[++top]=str[i+st];
		}
		else
		{
			if (top&&match(stk[top], str[i+st])) top--;
			else return false;
		}
	if (top) return false;
	return true;
}

int main()
{
	int test;
	scanf("%d", &test);
	getchar();
	while (test--)
	{
		gets(str);
		n=strlen(str);
		if (n)
		{
			for (int i=0; i<n; i++)
				str[i+n]=str[i];
			bool flag=false;
			for (int i=0; i<n; i++)
				if (check(i, n))
				{
					flag=true;
					break;
				}
			if (flag) puts("YES");
			else puts("NO");
		}
		else puts("YES");
	}
	return 0;
}
