#include <cstdio>
#include <cstring>

char s[1000];

int main()
{
    int n;
    scanf("%d\n",&n);
    while (n--)
    {
	gets(s);
	int l=strlen(s);
	if (strcmp(s,"1")==0||strcmp(s,"4")==0||strcmp(s,"78")==0) printf("+\n");
	else if (s[l-2]=='3'&&s[l-1]=='5') printf("-\n");
	else if (s[0]=='9'&&s[l-1]=='4') printf("*\n");
	else printf("?\n");
    }
    return 0;
}
