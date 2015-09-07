#include <stdio.h>
#include <string.h>

#define MAXN 80 + 10
#define MAX 255 + 10

struct Rule
{
	char find[MAXN];
	char repalceBy[MAXN];
} rules[10];

char text[MAX];
char temp[MAX];

int main()
{
	int numberOfRules;
	int i, j;
	char *p;
	while(scanf("%d", &numberOfRules) && numberOfRules != 0)
	{
		memset(text, 0, sizeof(text));
		getchar();
	 	for(i = 0; i < numberOfRules; i++)
	 	{

	 		gets(rules[i].find);
	 		gets(rules[i].repalceBy);
 		}

		gets(text);
		for(i = 0; i < numberOfRules; i++)
		{
			p = strstr(text, rules[i].find);
			if(p != NULL)
			{
				strcpy(temp, p + strlen(rules[i].find));
				strcpy(p, rules[i].repalceBy);
				strcpy(p + strlen(rules[i].repalceBy), temp);
				i--;
			}
		}
		 printf("%s\n", text);
	}
	return 0;
}
