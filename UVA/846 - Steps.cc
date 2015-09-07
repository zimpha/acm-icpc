#include <cstdio>

int main()
{
    int test;
    scanf("%d",&test);
    while (test--)
    {
	int x,y;
	scanf("%d%d",&x,&y);
	int length=1,dis=y-x;
	int step=0;
	bool flag=true;
	while (dis>0)
	{
	    dis-=length;
	    step++;
	    if (!flag) length++;
	    flag=!flag;
	}
	printf("%d\n",step);
    }
    return 0;
}
