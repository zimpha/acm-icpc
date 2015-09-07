#include <cstdio>
#include <cstring>

const int MAXN=60;

typedef char pile[5];

pile stack[MAXN][MAXN];
int top[MAXN];

bool check(pile a,pile b)
{
    if (a[0]==b[0]||a[1]==b[1]) return 1;
    else return 0;
}

void move(int pos,int n)
{
    for (int i=pos; i<n-1; i++)
    {
	memcpy(stack[i],stack[i+1],sizeof(stack[i]));
	top[i]=top[i+1];
    }
}

int game(int n)
{
    while (1)
    {
	bool flag=false;
	for (int p=1; p<n;)
	{
	    for (int i=p; i>=1;)
	    {
		if (i>=3&&check(stack[i][top[i]],stack[i-3][top[i-3]]))
		{
		    top[i-3]++;
		    strcpy(stack[i-3][top[i-3]],stack[i][top[i]]);
		    top[i]--;
		    if (top[i]==0)
		    {
			move(i,n);
			n--;
		    }
		    flag=true;
		    i-=3; p=1;
		}
		else if (check(stack[i][top[i]],stack[i-1][top[i-1]]))
		{
		    top[i-1]++;
		    strcpy(stack[i-1][top[i-1]],stack[i][top[i]]);
		    top[i]--;
		    if (top[i]==0)
		    {
			move(i,n);
			n--;
		    }
		    flag=true;
		    i--; p=1;
		}
		else 
		{
		    p++;
		    flag=false;
		    break;
		}
	    }
	}
	if (!flag) break;
    }
    return n;
}

int main()
{
    int n=0;
    pile s;
    while (scanf("%s",s)&&s[0]!='#')
    {
	top[n]=1;
	strcpy(stack[n][top[n]],s);
	n++;
	if (n==52)
	{
	    n=game(n);
	    if (n>1) printf("%d piles remaining:",n);
	    else printf("1 pile remaining:");
	    for (int i=0; i<n; i++)
		printf(" %d",top[i]);
	    printf("\n");
	    n=0;
	}
    }
    return 0;
}
