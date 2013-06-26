/*
Author: nevergo
Task: ZOJ 1240 IBM Minus One
Language: C
*/
#include <stdio.h>
#include <string.h>

int main()
{
    char s[60];
    int n,i,j,len;
    scanf("%d",&n);
    gets(s);
    for (i=1;i<=n;i++)
    {
        gets(s);
        len=strlen(s);
        printf("String #%d\n",i);
        for (j=0;j<len;j++)
            if (s[j]=='Z') printf("A");
            else printf("%c",s[j]+1);
        printf("\n\n");
    }
    return 0;
}
