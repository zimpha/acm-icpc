#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

typedef long long LL;
const int MAXN = 50000;

int a[MAXN], n, m;

int main(){
	int T; scanf("%d", &T);
	while (T --) {
		scanf("%d%d", &n, &m);		
		for (int i = 0; i < n; ++ i) scanf("%d", &a[i]);
		int sum = 0, big = 0;
		for (int i = 0; i < n; ++ i) sum += a[i], big = max(big, a[i]);
		sum = sum / m + (sum % m != 0);
		sum = max(sum, big);
		printf("%d\n", sum);
	}
	return 0;	
}
