#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>

using namespace std;

struct key{
    string word;
    int tot;
    int tno[201][2];
}keyword[1000];

map<string,int> isign,iskey;
string title[201];
int totkey,tott;

bool cmp_key(key a,key b)
{
    return (a.word<b.word);
}

void print(string title,int pos)
{
    int l=title.length(),b=1;
    for (int i=0;i<l;i++)
    {
        if (b!=pos) cout <<(char)tolower(title[i]);
        else cout << (char)toupper(title[i]);
        if (title[i]==' ') b++;
    }
    cout << '\n';
}

int main()
{
    tott=totkey=0;
    string buf,word;
    while (getline(cin,buf))
    {
        if(buf=="::") break;
        isign[buf]=1;
    }
    while (getline(cin,buf))
    {
        title[++tott]=buf;
        int p=0,l=buf.length(),no=0;
        while (p<l)
        {
            word=""; no++;
            while (buf[p]==' '&&p<l) p++;
            while (buf[p]!=' '&&p<l)
            {
                word+=tolower(buf[p]);
                p++;
            }
            if (isign[word]) continue;
            else if (iskey[word])
            {
                ++keyword[iskey[word]].tot;
                keyword[iskey[word]].tno[keyword[iskey[word]].tot][0]=tott;
                keyword[iskey[word]].tno[keyword[iskey[word]].tot][1]=no; //
            }
            else
            {
                totkey++;
                iskey[word]=totkey;
                keyword[totkey].word=word;
                ++keyword[totkey].tot;
                keyword[totkey].tno[keyword[totkey].tot][0]=tott;
                keyword[totkey].tno[keyword[totkey].tot][1]=no;
            }
        }
    }
    sort(keyword+1,keyword+totkey+1,cmp_key);
    for (int i=1;i<=totkey;i++)
        for (int j=1;j<=keyword[i].tot;j++)
            print(title[keyword[i].tno[j][0]],keyword[i].tno[j][1]);
    return 0;
}
