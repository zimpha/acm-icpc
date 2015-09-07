#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int SIZE = 100 + 10, MAXN = 10000 + 10;

vector<int> G[MAXN];
int col[SIZE][SIZE], row[SIZE][SIZE];
char A[SIZE][SIZE];
int mth1[MAXN], mth2[MAXN];
bool vis[MAXN];
int R, N, M;

int path(int u) {
    for (int i = 0; i < (int)G[u].size(); ++ i) {
        int v = G[u][i]; if (vis[v]) continue;
        vis[v] = true;
        if (mth2[v] < 0 || path(mth2[v])) {
            mth1[u] = v;
            mth2[v] = u;
            return 1;
        }
    }
    return 0;
}

int main() {
    while (scanf("%d", &R) == 1) {
        for (int i = 0; i < R; ++ i) scanf("%s", A[i]);
        for (int i = 0; i < R; ++ i) {
            for (int j = 0; j < R; ++ j) {
                col[i][j] = row[i][j] = -1;
            }
        }
        // gao row
        N = 0;
        for (int i = 0; i < R; ++ i) {
            for (int j = 0; j < R; ++ j) {
                if (A[i][j] == 'X' || row[i][j] != -1) continue;
                for (int k = j; k < R && A[i][k] == '.'; ++ k) row[i][k] = N;
                ++ N;
            }
        }
        // gao col
        for (int i = 0; i < N; ++ i) G[i].clear();
        M = 0;
        for (int i = 0; i < R; ++ i) {
            for (int j = 0; j < R; ++ j) {
                if (A[i][j] == 'X' || col[i][j] != -1) continue;
                for (int k = i; k < R && A[k][j] == '.'; ++ k) {
                    col[k][j] = M;
                    if (row[k][j] != -1) G[row[k][j]].push_back(M);
                }
                ++ M;
            }
        }
        /*
        for (int i = 0; i < R; ++ i) {
            for (int j = 0; j < R; ++ j) {
                cout << row[i][j] << " ";
            }
            cout << endl;
        }
        for (int i = 0; i < R; ++ i) {
            for (int j = 0; j < R; ++ j) {
                cout << col[i][j] << " ";
            }
            cout << endl;
        }*/
        for (int i = 0; i < N; ++ i) mth1[i] = -1;
        for (int i = 0; i < M; ++ i) mth2[i] = -1;
        int ret = 0;
        for (int i = 0; i < N; ++ i) {
            if (mth1[i] < 0) {
                for (int j = 0; j < M; ++ j) vis[j] = false;
                ret += path(i);
            }
        }
        printf("%d\n", ret);
    }
}
