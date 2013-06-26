#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
    char name[32];
    int count;
    node *left,*right;
}*head,*tmp;

char s[32];
int n;

void initialize(node *&p)
{
    gets(s);
    p=new node;
    p->left=p->right=NULL;
    strcpy(p->name,s);
    p->count=1;
}

void print(node *p)
{
    if (p->left!=NULL) print(p->left);
    printf("%s %.4lf\n",p->name,p->count*100.0/n);
    if (p->right!=NULL) print(p->right);
}

void insert(char s[32])
{
    tmp=head;
    while (1)
    {
        if (strcmp(tmp->name,s)==0)
        {

            tmp->count++;
            break;
        }
        else
            if (strcmp(tmp->name,s)>0)
            {
                if (tmp->left==NULL)
                {
                    tmp->left=new node;
                    tmp->left->left=tmp->left->right=NULL;
                    strcpy(tmp->left->name,s);
                    tmp->left->count=1;
                    break;
                }
                tmp=tmp->left;
            }
            else
            {
                if (tmp->right==NULL)
                {
                    tmp->right=new node;
                    tmp->right->left=tmp->right->right=NULL;
                    strcpy(tmp->right->name,s);
                    tmp->right->count=1;
                    break;
                }
                tmp=tmp->right;
            }
    }
}

int main()
{
    initialize(head);  n=1;
    while (gets(s))
    {
    	if (s[0]=='\0')
    	{
    		print(head);
    		puts("");
    		initialize(head);  n=1;
    	}
    	else
    	{
        n++;
        insert(s);
        }
    }
    print(head);
    return 0;
}
