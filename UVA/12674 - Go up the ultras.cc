#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 100000 + 10;

struct ST {
    int mx[MAXN][20], log2[MAXN], n;
    void init(int n, int a[]) {
        log2[0] = -1; this->n = n;
        for (int i = 1; i <= n; ++ i) log2[i] = log2[i >> 1] + 1;
        for (int i = 0; i < n; ++ i) mx[i][0] = a[i];
        for (int j = 1; (1 << j) < n; ++ j) {
            for (int i = 0; i + (1 << j) <= n; ++ i) {
                mx[i][j] = min(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    int query(int a, int b) {
        if (a > b) swap(a, b);
        int k = log2[b - a + 1];
        return min(mx[a][k], mx[b - (1 << k) + 1][k]);
    }
} RMQ;

int A[MAXN], L[MAXN], R[MAXN];
int N;

int main() {
    while (scanf("%d", &N) == 1) {
        for (int i = 0; i < N; ++ i) scanf("%d", A + i);
        RMQ.init(N, A);
        for (int i = 0; i < N; ++ i) {
            for (L[i] = i - 1; L[i] >= 0 && A[L[i]] <= A[i]; ) {
                L[i] = L[L[i]];
            }
        }
        for (int i = N - 1; i >= 0; -- i) {
            for (R[i] = i + 1; R[i] < N && A[R[i]] <= A[i]; ) {
                R[i] = R[R[i]];
            }
        }
        vector<int> ret;
        for (int i = 0; i < N; ++ i) {
            int mx = 0;
            if (L[i] >= 0) mx = max(mx, RMQ.query(L[i], i));
            if (R[i] < N) mx = max(mx, RMQ.query(i, R[i]));
            if (L[i] < 0 && R[i] >= N) mx = 0;
            if (A[i] - mx >= 150000) {
                ret.push_back(i + 1);
            }
            //printf("%d %d %d\n", L[i], R[i], mx);
        }
        //puts("");
        for (int i = 0; i < (int)ret.size(); ++ i) {
            if (i) putchar(' ');
            printf("%d", ret[i]);
        }
        puts("");
    }
    return 0;
}
