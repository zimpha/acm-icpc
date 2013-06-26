/*
Author: nevergo
Task: ZOJ 1949 Climbing Worm
Language: C
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,u,d;
    int ans,height;
    while (scanf("%d%d%d",&n,&u,&d)!=EOF&&n!=0)
    {
          height=0; 
          ans=0;
          while (1)
          {
                height+=u;
                ans++;
                if (height>=n) break;
                height-=d;
                ans++;
          }
          printf("%d\n",ans);
    }
    return 0;
}
