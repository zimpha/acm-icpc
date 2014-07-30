#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

double dis(double x1, double y1, double x2, double y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main()
{
	int T;
	int x1, y1, r1;
	int x2, y2, r2;
	cout.precision(2);
	cin >> T;
	while (T--)
	{
		cin >> x1 >> y1 >> r1;
		cin >> x2 >> y2 >> r2;
		if (r1<r2) swap(x1, x2), swap(y1, y2), swap(r1, r2);
		if (r1==r2||dis(x1, y1, x2, y2)+r2<=r1) cout << "Impossible." << endl;
		else
		{
			double x0=(double)(r1*x2-r2*x1)/(r1-r2);
			double y0=(double)(r1*y2-r2*y1)/(r1-r2);
			cout << fixed << x0 << " " << fixed << y0 << endl;
		}
	}
	return 0;
}
