#include <string>
#include <iostream>

using namespace std;

struct node
{
    int val;
    node *son[4];
};

node *T1, *T2;
string s;
int sum;
int p;

node *new_node()
{
    node *p=new(node);
    p->val=0;
    for (int i=0; i<4; i++)
	p->son[i]=NULL;
    return p;
}

node *build()
{
    node *T=new_node();
    if (s[p]=='p')
    {
	for (int i=0; i<4; i++)
	{
	    p++;
	    T->son[i]=build();
	}
    }
    else T->val=(s[p]=='f');
    return T;
}

void dfs(node *T1, node *T2, int pixel)
{
    if (T1==NULL&&T2==NULL) return;
    if (T1==NULL)
    {
	if (T2->val)
	{
	    sum+=pixel;
	    return;
	}
	for (int i=0; i<4; i++)
	    dfs(T1,T2->son[i],pixel>>2);
	return;
    }
    if (T2==NULL)
    {
	if (T1->val)
	{
	    sum+=pixel;
	    return;
	}
	for (int i=0; i<4; i++)
	    dfs(T1->son[i],T2,pixel>>2);
	return;
    }
    if (T1->val||T2->val)
    {
	sum+=pixel;
	return;
    }
    for (int i=0; i<4; i++)
	dfs(T1->son[i],T2->son[i],pixel>>2);
}

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
	cin >> s; p=0;
	T1=build();
	cin >> s; p=0;
	T2=build();
	sum=0;
	dfs(T1,T2,1024);
	cout << "There are " << sum << " black pixels." <<endl;
    }
    return 0;
}
