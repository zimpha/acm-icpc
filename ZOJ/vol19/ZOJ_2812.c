/*
Author: nevergo
Task: ZOJ 2812 Quicksum
Language: C
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[300];
    int len,i,ans;
    
    while (gets(s)!=EOF)
    {
          if (s[0]=='#') break;
          ans=0;
          len=strlen(s);
          for (i=0;i<len;i++)
              if (s[i]!=' ') ans=ans+(i+1)*(s[i]-'A'+1);
          printf("%d\n",ans);
    }    
    return 0;
}
