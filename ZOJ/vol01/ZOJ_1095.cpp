#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN=6000;

int hum[MAXN];
int n;

void get_humble()
{
	int n2, n3, n5, n7;
	n2=n3=n5=n7=0;
	hum[0]=1;
	for (int i=1; i<MAXN; i++)
	{
		int ret=std::min(hum[n2]*2,hum[n3]*3);
		ret=std::min(ret,hum[n5]*5);
		ret=std::min(ret,hum[n7]*7);
		if (ret==hum[n2]*2) n2++;
		if (ret==hum[n3]*3) n3++;
		if (ret==hum[n5]*5) n5++;
		if (ret==hum[n7]*7) n7++;
		hum[i]=ret;
	}
}

int main()
{
	int cas=0;
	get_humble();
	while (scanf("%d", &n)==1&&n)
	{
		printf("The %d", n);
		if (n%10==1)
		{
			if (n%100==11) printf("th");
			else printf("st");
		}
		else if (n%10==2)
		{
			if (n%100==12) printf("th");
			else printf("nd");
		}
		else if (n%10==3)
		{
			if (n%100==13) printf("th");
			else printf("rd");
		}
		else printf("th");
		printf(" humble number is %d.\n", hum[n-1]);
	}
	return 0;
}
