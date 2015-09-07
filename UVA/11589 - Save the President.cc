#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

int sum[20][20][20][100];

inline int get_sum(int x, int y, int z, int t) {
	int ret = sum[x][y][z][t];
	for (int mask = 1; mask < 16; ++ mask) {
		int dx = mask & 1, dy = (mask >> 1) & 1, dz = (mask >> 2) & 1, dt = (mask >> 3) & 1, cof = ((dx + dy + dz + dt) & 1) ? 1 : -1;
		ret += sum[x - dx][y - dy][z - dz][t - dt] * cof;
	}
	return ret;
}

inline int get_sum(int x, int y, int z, int t, int qx, int qy, int qz, int qt) {
	int ret = 0;
	for (int mask = 0; mask < 16; ++ mask) {
		int dx = mask & 1, dy = (mask >> 1) & 1, dz = (mask >> 2) & 1, dt = (mask >> 3) & 1, cof = ((dx + dy + dz + dt) & 1) ? 1 : -1;
		ret -= sum[x - 1 + dx * qx][y - 1 + dy * qy][z - 1 + dz * qz][t - 1 + dt * qt] * cof;
	}
	return ret;
}

int main() {
	int N, dimx, dimy, dimz, Q, cas = 0;
	while (scanf("%d%d%d%d%d", &N, &dimx, &dimy, &dimz, &Q) == 5 && N) {
		memset(sum, 0, sizeof(sum));
		for (int i = 0; i < N; ++ i) {
			int x1, y1, z1, x2, y2, z2;
			scanf("%d%d%d%d%d%d", &x1, &y1, &z1, &x2, &y2, &z2);
			int h1, m1, h2, m2, t1, t2;
			scanf("%d:%d %d:%d", &h1, &m1, &h2, &m2);
			t1 = h1 * 4 + m1 / 15, t2 = h2 * 4 + m2 / 15;
			x1 ++, y1 ++, z1 ++, t1 ++;
			for (int x = x1; x <= x2; ++ x) {
				for (int y = y1; y <= y2; ++ y) {
					for (int z = z1; z <= z2; ++ z) {
						for (int t = t1; t <= t2; ++ t) {
							sum[x][y][z][t] = 1;
						}
					}
				}
			}
		}

		for (int x = 1; x <= dimx; ++ x) {
			for (int y = 1; y <= dimy; ++ y) {
				for (int z = 1; z <= dimz; ++ z) {
					for (int t = 1; t <= 96; ++ t) {
						sum[x][y][z][t] = get_sum(x, y, z, t);
					}
				}
			}
		}
		
		printf("3D World %d:\n", ++ cas);
		while (Q --) {
			int qx, qy, qz, qt, h, m;
			scanf("%d%d%d %d:%d", &qx, &qy, &qz, &h, &m);
			qt = h * 4 + m / 15;
			int ret = 0;
			for (int x = 1; x <= dimx - qx + 1; ++ x) {
				for (int y = 1; y <= dimy - qy + 1; ++ y) {
					for (int z = 1; z <= dimz - qz + 1; ++ z) {
						for (int t = 1; t <= 96 - qt + 1; ++ t) {
							if (!get_sum(x, y, z, t, qx, qy, qz, qt)) ret ++;
						}
					}
				}
			}
			if (ret) printf("%d safe place(s) found\n", ret);
			else puts("No safe place(s) found");
		}
	}
	return 0;
}
