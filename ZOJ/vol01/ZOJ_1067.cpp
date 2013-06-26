#include <cstdio>
#include <cstring>

int r[16], g[16], b[16];

int dis(int x, int y, int z, int i)
{
	return (x-r[i])*(x-r[i])+(y-g[i])*(y-g[i])+(z-b[i])*(z-b[i]);
}

int main()
{
	for (int i=0; i<16; i++)
		scanf("%d%d%d", r+i, g+i, b+i);
	int x, y, z;
	while (scanf("%d%d%d", &x, &y, &z)==3&&x>=0)
	{
		int index=0;
		for (int i=1; i<16; i++)
			if (dis(x,y,z,i)<dis(x,y,z,index))
				index=i;
		printf("(%d,%d,%d) maps to (%d,%d,%d)\n", x, y, z, r[index], g[index], b[index]);
	}
	return 0;
}
