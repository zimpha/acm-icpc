#include <cstdio>

int main()
{
	for (double x=0; x<=2.0; x+=0.001)
	{
		double sum=0.0;
		for (double k=1; k<8000; k++)
			sum+=1/(k*(k+1)*(k+2)*(k+x));
		sum=((2-x)*sum+0.25)*(1-x)+1;
		printf("%5.3f %16.12f\n", x, sum);
	}
	return 0;
}
