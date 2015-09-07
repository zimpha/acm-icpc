#include <stack>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN=100000;

int level[MAXN], num[MAXN];
stack<int>s;
int n;

bool check()
{
    if (n&1) return false;
    memset(level,0,sizeof(level));
    while (!s.empty()) s.pop();
    for (int i=0; i<n; i++)
    {
	if (num[i]<0)
	{
	    s.push(-num[i]);
	    level[s.size()]=-num[i];
	}
	else
	{
	    if (s.empty()||s.top()!=num[i]) return false;
	    s.pop();
	    if (!s.empty())
	    {
		level[s.size()]-=num[i];
		if (level[s.size()]<=0) return false;
	    }
	}
    }
    return true;
}

int main()
{
    while (scanf("%d",&num[0])==1)
    {
	n=1;
	while (getchar()!='\n')
	    scanf("%d",&num[n++]);
	if (check()) printf(":-) Matrioshka!\n");
	else printf(":-( Try again.\n");
    }
    return 0;
}
