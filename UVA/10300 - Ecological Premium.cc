/*
Author: linxi
Task: UVA 10300 Ecological Premium
Language: C
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,f,a,b,c;
    long long ans;
    scanf("%d",&n);
    while (n)
    {
          ans=0;
          scanf("%d",&f);
          while (f)
          {
                scanf("%d%d%d",&a,&b,&c);
                ans+=a*c;
                f--;
          }
          printf("%lld\n",ans);
          n--;
    }
    return 0;
} 
