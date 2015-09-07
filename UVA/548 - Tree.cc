#include <cstdio>
#include <cstring>

const int MAXN=10005;
const int inf=1000000000;

struct node
{
    int value;
    node *left, *right;
};

int inorder[MAXN], postorder[MAXN];
node *T;
int ans;
int sum;
int n;

node* new_node()
{
    node *p=new(node);
    p->left=NULL;
    p->right=NULL;
    p->value=0;
    return p;
}

node *build(int *in, int *post, int len)
{
    if (len==0) return NULL;
    int i=len-1;
    while (post[len-1]!=in[i]) i--;
    node *T=new_node();
    T->value=post[len-1];
    T->left=build(in, post, i);
    T->right=build(in+i+1, post+i, len-i-1);
    return T;
}

void dfs(node *T, int cur)
{
    if (T->left==NULL&&T->right==NULL)
    {
	if (cur+T->value<sum)
	{
	    sum=cur+T->value;
	    ans=T->value;
	}
	else if (cur+T->value==sum&&ans>T->value)
	{
	    ans=T->value;
	}
	return;
    }
    if (T->left) dfs(T->left,cur+T->value);
    if (T->right) dfs(T->right,cur+T->value);
}

int main()
{
    while (scanf("%d",&inorder[0])==1)
    {
	n=1;
	while (getchar()!='\n') 
	    scanf("%d",&inorder[n++]);
	for (int i=0; i<n; i++)
	    scanf("%d",&postorder[i]);
	T=build(inorder,postorder,n);
	sum=inf;
	dfs(T,0);
	printf("%d\n",ans);
    }
    return 0;
}
