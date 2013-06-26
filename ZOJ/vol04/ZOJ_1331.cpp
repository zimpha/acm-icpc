#include <cstdio>
#include <cstring>

int main()
{	
	for (int a=6; a<=200; a++)
		for (int b=2; b<=a; b++)
			for (int c=b; c<=a; c++)
				for (int d=c; d<=a; d++)
					if (a*a*a==b*b*b+c*c*c+d*d*d)
						printf("Cube = %d, Triple = (%d,%d,%d)\n", a, b, c, d);
	return 0;
}
