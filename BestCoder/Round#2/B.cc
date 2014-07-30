#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;;
typedef pair<int, int> PII;

void out(int n) {
    n %= 1440;
    printf("%02d:%02d\n", n / 60, n % 60);
}

const int MAXM = 1000 + 10;

int arr[MAXM], id[MAXM], num[MAXM], ret[MAXM];

int main() {
    int cas; scanf("%d", &cas);
    while (cas --) {
        int N, T, K, M;
        scanf("%d%d%d%d", &N, &T, &K, &M);
        for (int i = 0; i < M; ++ i) {
            int hh, mm;
            scanf("%d:%d %d %d", &hh, &mm, &id[i], &num[i]);
            arr[i] = hh * 60 + mm; ret[i] = -1;
        }
        int now = 0;
        for (int i = 0; i < M; ++ i) {
            if (ret[i] == -1) {
                int need = (num[i] + K - 1) / K;
                int end = max(now, arr[i]) + (need - 1) * T;
                int rest = need * K;
                for (int j = i; j < M; ++ j) {
                    if (arr[j] > end || rest == 0) break;
                    if (id[j] == id[i]) {
                        int del = min(rest, num[j]);
                        rest -= del; num[j] -= del;
                        if (num[j] == 0 && ret[j] == -1) ret[j] = end + T;
                    }
                }
                now = end + T;
            }
            out(ret[i]);
        }
        if (cas) puts("");
    }
    return 0;
}
