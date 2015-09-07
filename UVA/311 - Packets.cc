#include <cstdio>

const int one[5]={0,7,6,5};
const int two[5]={0,5,3,1};

int main() {
	int a[10] , n = 6;
	while (true) {
		for (int i = 1; i <= n; ++ i) scanf("%d", &a[i]);
		if (a[1] + a[2] + a[3] + a[4] + a[5] + a[6] == 0) break;
		int tot = a[6] + a[5] + a[4] + (a[3] + 3) / 4;
		int onenum = a[5] * 11 + one[a[3] % 4];
		int twonum = a[4] * 5 + two[a[3] % 4];
		if (twonum < a[2]) {
			int left = a[2] - twonum;
			int tmp = (left + 8) / 9;
			tot += tmp;
			onenum += 4 * (9 * tmp - left);
		} else onenum += 4 * (twonum - a[2]);
		if (onenum < a[1]) tot += (a[1] - onenum + 35) / 36;
		printf("%d\n", tot);
	}
	return 0;
}
