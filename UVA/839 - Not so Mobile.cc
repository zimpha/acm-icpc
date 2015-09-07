#include <cstdio>
#include <cstring>

struct node
{
    int Wl, Wr;
    int Dl, Dr;
    node *l, *r;
};

node *T;

node *new_node()
{
    node *p=new(node);
    p->l=p->r=NULL;
    return p;
}

node *build()
{
    node *p=new_node();
    scanf("%d%d%d%d",&p->Wl,&p->Dl,&p->Wr,&p->Dr);
    if (!p->Wl)	p->l=build();
    if (!p->Wr)	p->r=build();
    return p;
}

bool check(node *T)
{
    if (!T->Wl)
    {
	bool flag=check(T->l);
	if (!flag) return false;
	T->Wl=T->l->Wl+T->l->Wr;
    }
    if (!T->Wr)
    {
	bool flag=check(T->r);
	if (!flag) return false;
	T->Wr=T->r->Wl+T->r->Wr;
    }
    return (T->Wl*T->Dl==T->Wr*T->Dr);
}

int main()
{
    int test;
    scanf("%d",&test);
    while (test--)
    {
	T=build();
	if (check(T)) printf("YES\n");
	else printf("NO\n");
	if (test) printf("\n");
    }
    return 0;
}
