#include <cstdio>
#include <cstring>

const long long one[13] = {0, 1, 11, 111, 1111, 11111, 111111, 1111111, 11111111, 111111111, 1111111111, 11111111111, 111111111111};  

long long a[10], fac[13];
  
int main() {
	int n, num, count;
	long long ans;
	fac[0] = 1;
	for (int i = 1; i <= 12; ++ i) fac[i] = i * fac[i - 1];
    while (scanf("%d", &n) == 1 && n) {  
        memset(a, 0, sizeof(a));
		count = 0;
		for (int i = 0; i < n; ++ i) {
			scanf("%d", &num);
			count += num;
			a[num] ++;
		}
		ans = fac[n - 1] * count;
		for (int i = 0; i < 10; ++i) ans /= fac[a[i]];
		printf("%lld\n", ans * one[n]);
	}
	return 0;
}  
