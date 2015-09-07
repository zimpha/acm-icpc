/*
Author: linxi
Task: UVa 10055 Hashmat the Brave Warrior
Language: C 
*/
#include <stdio.h>

int main()
{
    long long a=0,b=0;
    while (scanf("%lld %lld",&a,&b)!=EOF)
    {
          if (a>b) printf("%lld\n",a-b);
          else printf("%lld\n",b-a);
    }
    return 0;
}
