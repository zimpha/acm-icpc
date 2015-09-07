/*
Author: linxi
Task: UVA 458 The Decoder
Language: C
*/
#include <stdio.h>
#include <string.h>

int main()
{
    char s[10000];
    int len, i;
    
    while (scanf("%s",s)!=EOF)
    {
           len=strlen(s);
           for (i=0;i<len;i++)
               printf("%c",s[i]-7);
           printf("\n");
    }
    return 0;
}
