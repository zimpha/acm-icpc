#include<stdio.h>

int main()
{
    const long maxn=1007;
    long n, i;
    while(scanf("%ld",&n)==1)
    {
       if(n==0) break;
       double a[maxn],ave=0,ans1=0,ans2=0;
       char tmp[maxn];
       for(i=1;i<=n;i++)
       {
          scanf("%lf",&a[i]);
          ave+=a[i];
       }
       ave/=n;
       sprintf(tmp,"%.2lf",ave);
       sscanf(tmp,"%lf",&ave);
       for(i=1;i<=n;i++)
         if(a[i]<ave)
           ans1+=(ave-a[i]);
         else ans2+=(a[i]-ave);
       if(ans1<ans2) printf("$%.2lf\n",ans1);
       else printf("$%.2lf\n",ans2);
    }
    return 0;
}
