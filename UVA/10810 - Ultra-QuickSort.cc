#include <cstdio>
#include <cstring>

const int MAXN = 500005;
const int inf = 1000000000;

int A[MAXN], B[MAXN];
int N;
long long ret;

void merge_sort(int L, int R) {
	if (L == R) return;
	int mid = ( L + R ) >> 1;
	merge_sort(L, mid);
	merge_sort(mid + 1, R);
	for (int i = L; i <= mid; ++ i) B[i] = A[i];
	for (int i = mid + 2; i <= R + 1; ++ i) B[i] = A[i - 1];
	B[mid + 1] = B[R + 2] = inf;
	for (int k = L, i = L, j = mid + 2; k <= R; ++ k)
	{
		if (B[i] <= B[j]) A[k] = B[i ++];
		else A[k] = B[j ++], ret += (long long)mid - i + 1;
	}
}

int main() {
	while (scanf("%d", &N) == 1 && N) {
		for (int i = 1; i <= N; ++ i)
			scanf("%d", &A[i]);
		ret = 0;
		merge_sort(1, N);
		printf("%lld\n", ret);
	}
	return 0;
}
