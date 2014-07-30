#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 1000000 + 10;

LL S[MAXN];
int A[MAXN], C[MAXN];
int N, K;

void add(int x) {
	for (int i = x; i < MAXN; i += (i & -i)) C[i] ++;
}

int get_sum(int x) {
	int ret = 0;
	for (int i = x; i; i -= (i & -i)) ret += C[i];
	return ret;
}

int main() {
	scanf("%d%d", &N, &K); S[0] = 0;
	vector<LL> V; V.clear();
	for (int i = 1; i <= N; ++ i) {
		scanf("%d", &A[i]);
		S[i] = S[i - 1] + A[i];
	}
	for (int i = 0; i <= N; ++ i) {
		S[i] -= (LL)i * K;
		V.push_back(S[i]);
	}
	sort(V.begin(), V.end());
	V.erase(unique(V.begin(), V.end()), V.end());
	for (int i = 0; i <= N; ++ i) {
		A[i] = lower_bound(V.begin(), V.end(), S[i]) - V.begin() + 1;
	}
	long long ret = 0;
	memset(C, 0, sizeof(C));
	for (int i = 0; i <= N; ++ i) {
		ret += get_sum(A[i]);
		add(A[i]);
	}
	printf("%lld\n", ret);
	return 0;
}
