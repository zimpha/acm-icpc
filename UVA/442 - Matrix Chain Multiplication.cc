#include <cctype>
#include <cstdio>
#include <cstring>
#include <cstring>
#include <iostream>

using namespace std;

const int MAXN=30;

typedef struct Matrix
{
    int row, col;
}Matrix;

Matrix s1[MAXN],m[MAXN];
char s2[MAXN];
int top1,top2;
int n;

int main()
{
    scanf("%d",&n);
    for (int i=0; i<n; i++)
    {
	getchar();
	char c;
	int a,b;
	scanf("%c%d%d",&c,&a,&b);
	m[c-'A'].row=a; m[c-'A'].col=b;
    }
    string exp;
    while (cin >> exp)
    {
	int ans=0;
	bool flag=true;
	top1=top2=0;
	for (int i=0; i<exp.size(); i++)
	{
	    if (isalpha(exp[i]))
	    {
		top1++;
		s1[top1]=m[exp[i]-'A'];
	    }
	    else if (exp[i]=='(')
	    {
		top2++;
		s2[top2]='(';
	    }
	    else if (exp[i]==')')
	    {
		top2--;
		if (s1[top1].row!=s1[top1-1].col)
		{
		    flag=false;
		    break;
		}
		ans+=s1[top1-1].row*s1[top1].row*s1[top1].col;
		top1--;
		s1[top1].col=s1[top1+1].col;
	    }
	}
	if (!flag) cout << "error\n";
	else cout << ans << endl;
    }
}
