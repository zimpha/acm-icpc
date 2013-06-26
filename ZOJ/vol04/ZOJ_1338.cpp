#include <cstdio>  
#include <cstdlib>
#include <cstring>  
#include <iostream>  
    
using namespace std;  
int num[35]; 
 
int main()
{  
	int len,i,n,x,flag,up,upnum,down,downnum,tmp,ff;  
	while (scanf("%d", &n)==1&&n)  
	{  
		len = 1;  
		num[0] = n;  
		while (scanf("%d", &x)==1&&x)  
			num[len++] = x;  
		up = upnum = down = downnum = tmp = 0;  
		ff = flag = 0;  
		for (i=1; i<len; i++)  
		{  
			if (num[i] == num[i-1] )  
			{  
				if (!flag&&!ff) tmp++;   
				if (flag) down++;  
				if (ff) up++;
			}
			if (num[i] < num[i-1])  
			{
				ff = 0;
				if (!flag) flag = 1, downnum++;
				down++;
				down += tmp;
				tmp = 0;  
			}  
			if (num[i] > num[i-1])  
			{
				flag = 0;
				if (!ff) upnum++, ff = 1;
				up++;
				up += tmp;  
				tmp = 0;  
			}
		}  
		double ansup,ansdown;  
		if (upnum == 0) ansup = 0;
		else ansup = (double)up/upnum;
		if (downnum == 0) ansdown = 0;
		else ansdown = (double)down/downnum;
		printf("Nr values = %d:  %.6lf %.6lf\n", len, ansup, ansdown);  
	}  
	return 0;
}  
