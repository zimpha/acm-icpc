#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 100000 + 10;

char st[MAXN];
int S[MAXN], Q[MAXN];
int N, L;

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		scanf("%d%d", &N, &L);
		scanf("%s", st);
		S[0] = 0;
		for (int i = 0; i < N; ++ i) {
			S[i + 1] = S[i] + st[i] - '0';
		}
		int head = 0, tail = 0;
		int pl = 0, pr = N;
		double ave = 0;
		Q[0] = 0;
		for (int i = L; i <= N; ++ i) {
			while (head < tail && 
				(LL)(S[i] - S[Q[head+ 1]]) * (i- Q[head]) >= (LL)(S[i] - S[Q[head]]) * (i - Q[head + 1])) head ++; 
			
			double ta = (double)(S[i] - S[Q[head]]) / (i - Q[head]);
			if (ta > ave || (ta == ave && i - Q[head] < pr - pl)) {
				ave = ta; pr = i; pl = Q[head];
			}
			
			int tmp = i - L + 1;
			while (head < tail && 
				(LL)(S[tmp] - S[Q[tail]]) * (Q[tail] - Q[tail - 1]) <= (LL)(S[Q[tail]] -S[Q[tail - 1]]) * (tmp - Q[tail])) tail --;
			Q[++ tail] = tmp;
		}
		printf("%d %d\n", pl + 1, pr);
	}
	return 0;
}
