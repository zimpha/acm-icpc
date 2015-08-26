#include <bitset>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
using namespace std;

const int MAXN = 800 + 10;
bitset<800> A[MAXN][2], B[MAXN][2];
int C[MAXN][MAXN];
int N;

int main() {
    while (scanf("%d", &N) == 1) {
        for (int i = 0; i < N; ++ i) {
            A[i][0].reset(); A[i][1].reset();
            B[i][0].reset(); B[i][1].reset();
        }
        for (int i = 0; i < N; ++ i) {
            for (int j = 0; j < N; ++ j) {
                int x; scanf("%d", &x); x %= 3;
                if (x == 1) A[i][0].set(j);
                else if (x == 2) A[i][1].set(j);
            }
        }
        for (int i = 0; i < N; ++ i) {
            for (int j = 0; j < N; ++ j) {
                int x; scanf("%d", &x); x %= 3;
                if (x == 1) B[j][0].set(i);
                else if (x == 2) B[j][1].set(i);
            }
        }
        bitset<800> t;
        for (int i = 0; i < N; ++ i) {
            for (int j = 0; j < N; ++ j) {
                C[i][j] = 0;
                // 1 * 1
                t = A[i][0] & B[j][0];
                C[i][j] += t.count();
                // 1 * 2
                t = A[i][0] & B[j][1];
                C[i][j] += t.count() * 2;
                // 2 * 1
                t = A[i][1] & B[j][0];
                C[i][j] += t.count() * 2;
                // 2 * 2
                t = A[i][1] & B[j][1];
                C[i][j] += t.count() * 4;
                C[i][j] %= 3;
            }
        }
        for (int i = 0; i < N; ++ i) {
            for (int j = 0; j < N; ++ j) {
                if (j) putchar(' ');
                printf("%d", C[i][j]);
            }
            puts("");
        }
    }
}
