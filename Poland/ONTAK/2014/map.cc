#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int MAXN = 1000 + 10;
char bx[MAXN][MAXN], by[MAXN][MAXN];
int n, m;
vector<PII> opt;

bool foldX(int x1, int y1, int x2, int y2, int x) {
    if (x == x2) return false;
    for (int j = y1; j <= y2; ++ j) {
        if (bx[x][j] != bx[x][y1]) return false;
    }
    for (int j = y1; j <= y2; ++ j) {// X is ok
        int a = x - 1, b = x + 1;
        while (a >= x1 && b < x2) {
            if (bx[a][j] == bx[b][j]) return false;
            -- a; ++ b;
        }
    }
    for (int j = y1; j < y2; ++ j) {// Y is ok
        int a = x, b = x + 1;
        while (a >= x1 && b <= x2) {
            if (by[a][j] == by[b][j]) return false;
            -- a; ++ b;
        }
    }
    return true;
}

bool foldY(int x1, int y1, int x2, int y2, int y) {
    if (y2 == y) return false;
    for (int i = x1; i <= x2; ++ i) {
        if (by[i][y] != by[x1][y]) return false;
    }
    for (int i = x1; i <= x2; ++ i) {// Y is ok
        int a = y - 1, b = y + 1;
        while (a >= y1 && b < y2) {
            if (by[i][a] == by[i][b]) return false;
            -- a; ++ b;
        }
    }
    for (int i = x1; i < x2; ++ i) {// X is ok
        int a = y, b = y + 1;
        while (a >= y1 && b <= y2) {
            if (bx[i][a] == bx[i][b]) return false;
            -- a; ++ b;
        }
    }
    return true;
}

bool fold(int x1, int y1, int x2, int y2) {
    if (x1 == x2 && y1 == y2) return true;
    int xa = x1, xb = x2 - 1, ya = y1, yb = y2 - 1;
    for (int x, y; xa <= xb || ya <= yb; ) {
        if (xb - xa > yb - ya) {// fold X
            if (rand() % 2) x = xa ++;
            else x = xb --;
            if (foldX(x1, y1, x2, y2, x)) {
                opt.push_back(PII(0, x));
                if (x2 - x - 1 < x - x1) return fold(x1, y1, x, y2);
                else return fold(x + 1, y1, x2, y2);
            }
        } 
        else {// fold Y
            if (rand() % 2) y = ya ++;
            else y = yb --;
            if (foldY(x1, y1, x2, y2, y)) {
                opt.push_back(PII(1, y));
                if (y2 - y - 1 < y - y1) return fold(x1, y1, x2, y);
                else return fold(x1, y + 1, x2, y2);
            }
        }
    }
    return false;
}

int main() {
    scanf("%d%d", &n, &m); opt.clear();
    for (int i = 1; i <= n; ++ i) scanf("%s", by[i] + 1);
    for (int i = 1; i < n; ++ i) scanf("%s", bx[i] + 1);
    if (fold(1, 1, n, m)) {
        puts("TAK");
        printf("%d\n", (int)opt.size());
        for (int i = 0; i < (int)opt.size(); ++ i) {
            printf("%c %d\n", "-|"[opt[i].first], opt[i].second);
        }
    }
    else puts("NIE");
    return 0;
}
