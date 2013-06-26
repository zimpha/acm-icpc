#include <cstdio>
#include <cstring>

void swap(int *a,int *b)
{
    int t;
    t=*a; *a=*b; *b=t;
}

int main()
{
    int a,b;
    int count;
    while (scanf("%d%d",&a,&b)!=EOF&&a)
    {
        if (a<b) swap(&a,&b);
        if (a/b>=2) printf("Stan wins\n");
        else
        {
            count=0;
            while (a/b==1&&a!=b)
            {
                count++;
                a=a%b;
                if (a<b) swap(&a,&b);
            }
            if (count&1) printf("Ollie wins\n");
            else printf("Stan wins\n");
        }
    }
    return 0;
}
