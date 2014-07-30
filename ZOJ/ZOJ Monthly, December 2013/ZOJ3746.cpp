#include <cmath>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int YS = 90, XS = 180, MAXY = 200;
const double eps = 1e-9, R = 6378, PI = acos(-1), rad = PI / 180;

class BIT {
private:
	static const int SIZE = 400, BIAS = 5;
	int C[SIZE];

public:
	void clear() {memset(C, 0, sizeof(C));}
	void Modify(int x, int v) {
		for (x += BIAS; x < SIZE; x += x & -x) C[x] += v;
	}
	int Get(int x) {
		int ret = 0;
		for (x += BIAS; x; x -= x & -x) ret += C[x];
		return ret;
	}
	int Get(int l, int r) {
		return Get(r) - Get(l - 1);
	}
};

int dis[MAXY][MAXY];
BIT T[MAXY];
int N, M;

inline double fix(double x) {
	x = (x > 1 - eps) ? 1 - eps : x;
	x = (x < eps - 1) ? eps - 1 : x;
	return x;
}

inline double sqr(double x) {return x * x;}
inline double cosd(double x) {return cos(x * rad);}
inline double sind(double x) {return sin(x * rad);}

int main() {
	while (scanf("%d%d", &N, &M) == 2) {
		for (int y1 = -90; y1 <= 90; ++ y1) {
			T[y1 + YS].clear();
			for (int y2 = y1; y2 <= 90; ++ y2) {
				int left = -1, right = 180;
				double a = sind(y1) * sind(y2), b = cosd(y1) * cosd(y2);
				while (left < right) {
					int mid = left + (right - left + 1) / 2;
					double len = acos(fix(a + b * cosd(mid)));
					if (len * R <= eps + M) left = mid;
					else right = mid - 1;
				}
				dis[y1 + YS][y2 + YS] = dis[y2 + YS][y1 + YS] = left;
			}
		}
		while (N --) {
			char st[10];
			int x, y;
			scanf("%s%d%d", st, &x, &y);
			x = (x % 360 + 360) % 360;
			if (st[0] == 'i') {
				T[y + YS].Modify(x, 1);
			}
			else{
				int ret = 0;
				for (int i = -90; i <= 90; ++ i) {
					int delta = dis[y + YS][i + YS];
					if (delta < 0) continue;
					if (delta == 180) ret += T[i + YS].Get(360);
					else {
						int l = x - delta, r = x + delta;
						l = (l % 360 + 360) % 360;
						r = (r % 360 + 360) % 360;
						if (l <= r) ret += T[i + YS].Get(l, r);
						else ret += T[i + YS].Get(l, r) + T[i + YS].Get(360);
					}
				}
				printf("%d\n", ret);
			}
		}
	}
	return 0;
}
