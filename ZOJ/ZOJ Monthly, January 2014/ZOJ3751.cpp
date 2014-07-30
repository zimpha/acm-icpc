#include <cstdio>
#include <cstring>

int main() {
	int N;
	while (scanf("%d", &N) == 1){
		int ret = 0, y = N * N;
		for (int i = 1; i < N; ++ i) {
			ret += y;
			y -= 2;
		}
		ret += (y + 2) >> 1;
		printf("%d\n", ret);
	}
	return 0;
}
