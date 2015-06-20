#include <bits/stdc++.h>
using namespace std;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
const int MAXN = 200;
char G[MAXN][MAXN];
int n;

int lalala(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= n) return 0;
    return (G[x][y] == 'o');
}

bool check() {
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < n; ++ j) {
            int cnt = 0;
            for (int k = 0; k < 4; ++ k) {
                cnt += lalala(i + dx[k], j + dy[k]);
            }
            if (cnt & 1) return false;
        }
    }
    return true;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) scanf("%s", G[i]);
    if (check()) puts("YES");
    else puts("NO");
    return 0;
}
