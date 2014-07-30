#include <bits/stdc++.h>
using namespace std;

const int MAXN = 55;

typedef long long LL;
typedef int matrix[MAXN][MAXN];

int point[MAXN][MAXN];
int N, M, D, P, Q;

void mul(matrix A, matrix B) {
    matrix C;;
    for (int i = 0; i <= N; ++ i) {
        for (int j = 0; j <= N; ++ j) {
            C[i][j] = 0;
            for (int k = 0; k <= N; ++ k) {
                C[i][j] += (LL)A[i][k] * B[k][j] % P;
                C[i][j] %= P;
            }
        }
    }
    memcpy(A, C, sizeof(C));
}

int main() {
    cin >> N >> M >> D >> P >> Q;
    for (int i = 0; i < Q; ++ i) {
        for (int j = 0; j < N; ++ j) {
            cin >> point[i][j];
        }
    }
    matrix x; memset(x, 0, sizeof(x));
    for (int r = 0; r <= N; ++ r) {
        if (r > 0) x[r - 1][r] = (N - r + 1) * (M - 1) % P;
        x[r][r] = r * (M - 2) % P;
        if (r < N) x[r + 1][r] = (r + 1) % P;
    }
    int ret[MAXN], tmp[MAXN];
    memset(ret, 0, sizeof(ret)); ret[0] = 1;
    while (D) {
        if (D & 1) {
            for (int i = 0; i <= N; ++ i) {
                tmp[i] = 0;
                for (int j = 0; j <= N; ++ j) {
                    tmp[i] += (LL)ret[j] * x[i][j] % P;
                    tmp[i] %= P;
                }
            }
            for (int i = 0; i <= N; ++ i) ret[i] = tmp[i];
        }
        D >>= 1;
        mul(x, x);
    }
    for (int i = 0; i < Q; ++ i) {
        for (int j = 0; j < Q; ++ j) {
            if (j) cout << " ";
            int cnt = 0;
            for (int k = 0; k < N; ++ k) cnt += (point[i][k] != point[j][k]);
            cout << ret[cnt] % P;
        }
        cout << endl;
    }
    return 0;
}
