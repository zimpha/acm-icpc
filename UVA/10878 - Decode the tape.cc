#include<iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN=110;
char result[MAXN];
char temp[12];

int main()
{
    char ascii;
    int i;
    while(gets(temp))
    {
        if(strcmp(temp, "___________") == 0)
        {
            ascii = 0;
            gets(temp);
            while(strcmp(temp, "___________") != 0)
            {
                for(i = 1; i <= 9; i++)
                {
                    if(temp[i] != '.')
                    {
                        ascii <<= 1;
                        if(temp[i] == 'o')
                            ascii += 1;

                    }
                }
                printf("%c", ascii);
                gets(temp);
            }
        }
    }
    return 0;
}
