#include <cstdio>
#include <cstring>

double max=2147483647;

double change(char s[])
{
    int l=strlen(s),pos=0,i;
    double num=0;
    if (s[pos]=='+') --pos;
    while ((pos<l)&&(s[pos]=='0')) ++pos;
    if (l-pos>10) return max+1;
    for (i=pos;i<l;i++)
        num=num*10+s[i]-'0';
    return num;
}

int main()
{
    char s1[1000],s2[1000],lable;
    double num1,num2;
    while (scanf("%s %c %s",s1,&lable,s2)!=EOF)
    {
        num1=change(s1);
        num2=change(s2);
        printf("%s %c %s\n",s1,lable,s2);
        if (num1>max) printf("first number too big\n");
        if (num2>max) printf("second number too big\n");
        if (lable=='+') num1+=num2;
        else num1*=num2;
        if (num1>max) printf("result too big\n");
    }
    return 0;
}
