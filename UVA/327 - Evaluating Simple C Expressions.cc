#include <deque>
#include <cctype>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

const int MAXN=26;

deque<int>opd;
bool hash[MAXN];
int val[MAXN];
string s;

void clear_blank()
{
    int cur=0;
    for (int i=0; i<s.size(); i++)
	if (s[i]!=' ') s[cur++]=s[i];
    s.erase(s.begin()+cur,s.end());
}

bool prefix(int p)
{
    return ((s[p-1]=='-'&&s[p-2]=='-')||(s[p-1]=='+'&&s[p-2]=='+'));
}

bool suffix(int p)
{
    return ((s[p+1]=='-'&&s[p+2]=='-')||(s[p+1]=='+'&&s[p+2]=='+'));
}

void simplify()
{
    for (int i=0; i<MAXN; i++)
    {
	val[i]=i+1;
	hash[i]=0;
    }
    while (!opd.empty()) opd.pop_back();
    for (int i=0; i<s.size(); i++)
	if (isalpha(s[i]))
	{
	    int x;
	    hash[s[i]-'a']=true;
	    if (i>=2&&prefix(i))
	    {
		if (s[i-1]=='+') val[s[i]-'a']++;
		else val[s[i]-'a']--;
		s[i-1]=s[i-2]=' ';
		x=val[s[i]-'a'];
	    }
	    else if (i+2<s.size()&&suffix(i))
	    {
		x=val[s[i]-'a'];
		if (s[i+1]=='-') val[s[i]-'a']--;
		else val[s[i]-'a']++;
		s[i+1]=s[i+2]=' ';
	    }
	    else x=val[s[i]-'a'];
	    opd.push_back(x);
	}
}

void calc()
{
    for (int i=0; i<s.size(); i++)
	if (s[i]=='-'||s[i]=='+')
	{
	    int a=opd.front(); opd.pop_front();
	    int b=opd.front(); opd.pop_front();
	    if (s[i]=='-') opd.push_front(a-b);
	    else opd.push_front(a+b);
	}
}

void print()
{
    cout << "    value = " << opd.front() << endl;
    for (int i=0; i<MAXN; i++)
	if (hash[i]) 
	    cout << "    " << (char)(i+'a') << " = " << val[i] << endl;
}

int main()
{
    while (getline(cin,s))
    {
	cout << "Expression: " << s << endl;
	clear_blank();
	simplify();
	calc();
	print();
    }
    return 0;
}
