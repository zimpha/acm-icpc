/*
Author: nevergo
Task: ZOJ 1045 HangOver
Language: C 
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    double tar,sta;
    int ans;
    while (scanf("%lf",&tar))
    {
          if (tar==0.00) break;
          ans=1; sta=0;
          while (1)
          {
                sta+=1.0/(ans+1);
                if (sta>=tar) break; 
                ans++;
          }
          printf("%d card(s)\n",ans);
    }
    return 0;
}
