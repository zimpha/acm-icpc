#include <cstdio>

int ftwo,fone,base;

int getlen(int low,int carry,int len)
{
    int tmp=low*ftwo+carry;
    if (tmp==fone) return len;
    return getlen(tmp%base,tmp/base,len+1);
}

int main()
{
    while (scanf("%d%d%d",&base,&fone,&ftwo)==3)
    {
	printf("%d\n",getlen(fone,0,1));
    }
    return 0;
}
