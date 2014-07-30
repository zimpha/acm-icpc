#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int MAXN = 100000 + 10;

char P[MAXN];
int N, M, K;

inline void add_mod(LL &a, LL b) {
    if ((a += b) >= M) a -= M;
}

void mul(LL a[4][4], LL b[4][4]) {
    LL c[4][4];
    for (int i = 0; i < 4; ++ i) {
        for (int j = 0; j < 4; ++ j) {
            c[i][j] = 0;
            for (int k = 0; k < 4; ++ k) {
                c[i][j] += a[i][k] * b[k][j] % M;
            }
            c[i][j] %= M;
        }
    }
    memcpy(a, c, sizeof(c));
}

#define debug(x) {cerr << #x << ": " << (x) << endl;}
int main() {
    scanf("%s%d%d", P, &K, &M);
    N = strlen(P);
    LL SP = 0, SL = 0, SB = 0, PP = 1, PL = 0, PB = 0;
    for (int i = 0; i < N; ++ i) {
        P[i] -= '0';
        PP = PP * 10 % M;
        PL = (PL * 10 + P[i]) % M;
        PB = (PB * 10 + P[i] * (i + 1)) % M;
        add_mod(SP, PP);
        add_mod(SL, PL);
        add_mod(SB, PB);
    }
    LL x[4][4], ret[4], tmp[4];
    memset(x, 0, sizeof(x)); memset(ret, 0, sizeof(ret)); 
    ret[3] = 1;
    x[0][0] = 1; x[0][1] = SP; x[0][2] = SL; x[0][3] = SB;
    x[1][1] = PP; x[1][2] = PL; x[1][3] = PB;
    x[2][2] = 1; x[2][3] = N;
    x[3][3] = 1;
    for (; K; K >>= 1) {
        if (K & 1) {
            for (int i = 0; i < 4; ++ i) {
                tmp[i] = 0;
                for (int j = 0; j < 4; ++ j) {
                    tmp[i] += x[i][j] * ret[j] % M;
                }
            }
            for (int i = 0; i < 4; ++ i) ret[i] = tmp[i] % M;
        }
        mul(x, x);
    }
    printf("%d\n", (int)ret[0]);
    return 0;
}
