#include <iostream>
#include <algorithm>
#include <cstdio>

int main()
{
    double n;
    while (scanf("%lf",&n)!=EOF)
    {
        while (1)
        {
            if (n<=9)
            {
                printf("Stan wins.\n");
                break;
            }
            if (n>9&&n<=18)
            {
                printf("Ollie wins.\n");
                break;
            }
            n/=18.0;
        }
    }
    return 0;
}
