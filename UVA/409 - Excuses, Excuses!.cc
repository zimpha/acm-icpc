#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>

using namespace std;

char keyword[25][25], line[25][100];

int main()
{
    int k, e, count[20], num = 1;
    while (scanf("%d %d", &k, &e) == 2)
    {
        cout << "Excuse Set #" << num++ << endl;
        getchar();

        for (int i = 0; i < k; i++)
            gets(keyword[i]);
        for (int j = 0; j < e; j++)
        {
            gets(line[j]);
        }
        memset(count, 0, sizeof(count));
        for (int i = 0; i < e; i++){
            int len = strlen(line[i]);
            for (int j = 0; j < len; )
            {
                if (line[i][j] >= 'A' && line[i][j] <= 'Z' || line[i][j] >= 'a' && line[i][j] <= 'z')
                {
                    char ch[100];
                    int t = 0,k;
                    for (k = j; k < len; ++k)
                    {
                        if (line[i][k] >= 'A' && line[i][k] <= 'Z' || line[i][k] >= 'a' && line[i][k] <= 'z')
                        {
                            ch[t++] = tolower(line[i][k]);
                        }
                        else break;
                    }
                    ch[t] = '\0';
                    for (int m = 0; m < k; m++)
                    {
                        if (strcmp(keyword[m], ch) == 0)
                        count[i]++;
                    }
                    j = k;
                }
                else j++;
            }
        }
        int maxx = 0;
        for (int i = 0; i < e; i++)
        {
            if (count[i] > maxx)
                maxx = count[i];
        }
        for (int i = 0; i < e; i++)
        {
            if (count[i] == maxx)
            cout << line[i] << endl;
        }
        cout << endl;
    }
    return 0;
}
