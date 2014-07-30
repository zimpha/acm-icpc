#include <cstdio>
#include <cstring>

int main() {
	int T, H, L, W;
	while (scanf("%d", &T) == 1 && T) {
		int Hmax = 0, Vmax = 0;
		for (int i = 0; i < T; ++ i) {
			scanf("%d%d%d", &L, &W, &H);
			if (H > Hmax) {
				Hmax = H;
				Vmax = L * W * H;
			}
			else if (H == Hmax && L * W * H > Vmax) {
				Hmax = H;
				Vmax = L * W * H;
			}
		}
		printf("%d\n", Vmax);
	}
	return 0;
}
