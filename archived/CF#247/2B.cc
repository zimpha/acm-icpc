#include <bits/stdc++.h>
using namespace std;

int g[5][5];

int gao(int p[]) {
    int ret = 0;
    for (int i = 0; i < 4; ++ i) {
        for (int j = i; j + 1 < 5; j += 2) {
            ret += g[p[j]][p[j + 1]];
            ret += g[p[j + 1]][p[j]];
        }
    }
    return ret;
}

int main() {
    for (int i = 0; i < 5; ++ i) {
        for (int j = 0; j < 5; ++ j) {
            cin >> g[i][j];
        }
    }
    int p[5] = {0, 1, 2, 3, 4};
    int ret = 0;
    do {
        ret = max(ret, gao(p));
    } while (next_permutation(p, p + 5));
    cout << ret << endl;
}
