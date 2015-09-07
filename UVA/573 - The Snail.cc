#include <cstdio>

int main()
{
    double H,U,D,F;
    while (scanf("%lf%lf%lf%lf",&H,&U,&D,&F)==4&&H!=0)
    {
	double height=0;
	double down=U*F/100.0;
	int day=1;
	while (1)
	{
	    if (U>0) height+=U;
	    if (height>H)
	    {
		printf("success on day %d\n",day);
		break;
	    }
	    height-=D; U-=down;
	    if (height<0)
	    {
		printf("failure on day %d\n",day);
		break;
	    }
	    day++;
	}
    }
    return 0;
}
