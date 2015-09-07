#include <cctype>
#include <cstdio>
#include <cstring>
#include <cstdlib>

const int MAXN=1005;
const int MAXM=25;

typedef char string[MAXM];

string dict[MAXN];
string word[MAXN];
int n;

int cmp_string(const void *_a,const void *_b)
{
    char *a=(char *)_a;
    char *b=(char *)_b;
    return strcmp(a,b);
}

int cmp_char(const void *_a,const void *_b)
{
    char *a=(char *)_a;
    char *b=(char *)_b;
    return (*a-*b);
}

int main()
{
    string s;
    n=0;
    while (scanf("%s",s)&&s[0]!='#')
    {
	strcpy(dict[n],s);
	n++;
    }
    qsort(dict,n,sizeof(dict[0]),cmp_string);
    for (int i=0; i<n; i++)
    {
	int len=strlen(dict[i]);
	strcpy(word[i],dict[i]);
	for (int j=0; j<len; j++)
	    word[i][j]=tolower(word[i][j]);
	qsort(word[i],len,sizeof(char),cmp_char);
    }
    for (int i=0; i<n; i++)
    {
	bool flag=false;
	for (int j=0; j<n; j++)
	    if (i!=j&&strcmp(word[i],word[j])==0)
	    {
		flag=true;
		break;
	    }
	if (!flag) printf("%s\n",dict[i]);
    }
    return 0;
}
