#include <cstdio>
#include <cstring>

int main()
{
	char s[1000];
	while (gets(s)&&s[0]!='0')
	{
		int n=0;
		for (int i=0; s[i]; i++)
			n+=s[i]-'0';
		n%=9;
		if (n==0) n=9;
		printf("%d\n", n);
	}
	return 0;
}
