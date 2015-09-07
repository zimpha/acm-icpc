#include <cstdio>
#include <cstring>
#define SIZE 110

char s1[SIZE],s2[SIZE],s3[SIZE],s4[SIZE],s5[SIZE];
int n;

void getline1()
{
    int l=-1; while ((s1[++l]=getchar())!='<'); s1[l]='\0';
    l=-1; while ((s2[++l]=getchar())!='>'); s2[l]='\0';
    l=-1; while ((s3[++l]=getchar())!='<'); s3[l]='\0';
    l=-1; while ((s4[++l]=getchar())!='>'); s4[l]='\0';
    l=-1; while ((s5[++l]=getchar())!='\n'); s5[l]='\0';
    printf("%s%s%s%s%s\n",s1,s2,s3,s4,s5);
}

void getline2()
{
    int l=-1; while ((s1[++l]=getchar())!='\n'); s1[l-3]='\0';
    printf("%s%s%s%s%s\n",s1,s4,s3,s2,s5);
}

int main()
{
    scanf("%d\n",&n);
    while (n--)
    {
        getline1();
        getline2();
    }
    return 0;
}
