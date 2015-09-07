#include <stdio.h>
#include <stdlib.h>
#include<string.h>

char c[1001];

double swit(char f,int j)
{
    double s = 0,x;
    int y,i;
    i = j;
    while(c[j]>='0'&&c[j]<='9'&&j<strlen(c)) j++;
    x = 1;
    y = j;
    y--;
    while(y>=i)
    {
        s += (c[y]-48)*x;
        x *= 10;
        y--;
    }
    x = 1.0/10;
    if(c[j] == '.')
    {
        j++;
        while(c[j]>='0'&&c[j]<='9'&&j<strlen(c))
        {
            s += (c[j]-48)*x;
            x = x/10;
            j++;
        }
    }
    if(j!=strlen(c))
    {
        if (c[j] == 'm') s = s/1000;
        if (c[j] == 'k' ) s = s*1000;
        if (c[j] == 'M') s = s*1000000;
    }
    return s;
}

int main()
{
    int t, i, j, k,count,flag,a[300],g = 0;
    float s,x,I,v,P;
    scanf("%d%*c", &t);
    while(t--)
    {
        g++;
        a['U'] = 1;
        a['I'] = 1;
        a['P'] = 1;
        flag = 0;
        count = 0;
        gets(c);
        k = strlen(c);
        for(i = 0  ; i < k ; i++)
        {
            if(i<k-2&&(c[i] == 'U'||c[i] == 'P'||c[i] == 'I')&&c[i+1] == '=')
            {
                j = i+2;
                s = swit(c[i],j);

                if(c[i] == 'U')
                {
                    v  = s;
                    count++;
                    a[c[i]] = 0;
                }
                if(c[i] == 'I')
                {
                    I = s;
                    count++;
                    a[c[i]] = 0;
                }
                if(c[i] == 'P')
                {
                    P = s;
                    count++;
                    flag = 1;
                    a[c[i]] = 0;
                }
                if(count == 2)
                {
                    break;
                }
                i+=2;
            }
        }
        printf("Problem #%d\n",g);
        if(flag == 0) printf("P=%.2fW\n",I*v);
        else if(a['U'] == 0) printf("I=%.2fA\n",P/v);
        else printf("U=%.2fV\n",P/I);
        puts("");
    }
    return 0;
}
