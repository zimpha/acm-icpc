#include <bits/stdc++.h>
using namespace std;
//p:->  G:^  L:<-  D: v
const int MAXN = 1000 + 10;
char go[MAXN][MAXN];
int n, m, f;

int main() {
    scanf("%d%d%d", &n, &m, &f);
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < m; ++ j) {
            go[i][j] = "DG"[i & 1];
        }
    }
    for (int i = 0; i < n; ++ i) {
        if (i < n - 1) go[i][0] = 'P';
        if (i && i % 2 == 0) go[i][1] = 'L';
        if (i & 1) go[i][m - 1] = 'L';
    }
    for (int i = 0; i < f; ++ i) {
        int x, y; scanf("%d%d", &x, &y);
        if (x & 1) {
            go[x][y - 2] = 'L';
            go[x - 1][y + 1] = 'P';
            go[x][y + 1] = 'P';
            go[x + 1][y + 2] = 'L';
        }
        else {
            if (y == 3) {
                go[x - 1][0] = 'G';
                go[x - 1][1] = 'P';
                go[x][1] = 'D';
                go[x][y + 1] = 'L';
            }
            else {
                go[x][y + 1] = 'L';
                go[x - 1][y - 2] = 'P';
                go[x][y - 2] = 'P';
                go[x + 1][y - 3] = 'L';
            }
        }
    }
    puts("TAK");
    for (int i = 0, x = 0, y = 0; i < n * m - 4 * f; ++ i) {
        putchar(go[x][y]);
        if (go[x][y] == 'P') ++ x;
        else if (go[x][y] == 'L') -- x;
        else if (go[x][y] == 'G') ++ y;
        else -- y;
    }
    puts("");
    return 0;
}