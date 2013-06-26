/*
Author: nevergo
Task: ZOJ 1025 Wooden Sticks
Language: C
*/
#include <stdio.h>
#include <stdlib.h>
#define MAXN 5010

int l[MAXN],w[MAXN];
int f[MAXN];
int n,ans;

void init()
{
     int i;
     scanf("%d",&n);
     for (i=0;i<n;i++) scanf("%d%d",&l[i],&w[i]);  
}

void swap(int *a,int *b)
{
     int tmp;
     tmp=*a; *a=*b;*b=tmp;
}

void sort()
{
     int i,j;
     for (i=0;i<n-1;i++)
         for (j=0;j<n-i-1;j++)
             if ((l[j]>l[j+1])||((l[j]==l[j+1])&&(w[j]>w[j+1])))
             {
                swap(&l[j],&l[j+1]);
                swap(&w[j],&w[j+1]);
             } 
}

void solve()
{
     int i,j;
     memset(f,0,sizeof(f));
     ans=0;
     for (i=0;i<n;i++)
     {
         f[i]=1;
         for (j=0;j<i;j++)
             if ((w[i]<w[j])&&(f[i]<f[j]+1)) f[i]=f[j]+1;
         if (f[i]>ans) ans=f[i];
     }
}

int main()
{
    int test;
    scanf("%d",&test);
    while (test)
    {         
          init();
          sort();
          solve();
          printf("%d\n",ans);
          test--;
    }
    return 0;
}
