#include <bits/stdc++.h>
#define MP make_pair
using namespace std;
const int MAXN = 300 + 10, inf = 1e9 + 10;
typedef pair<int, int> PII;
pair<int, PII> edge[MAXN * MAXN];
int dis[MAXN][MAXN], n, m;
int ans[MAXN][MAXN], ret;

void add(int u, int v, int w) {
    for (int i = 0; i < n; ++ i) {
        dis[u][v] = min(dis[u][v], dis[u][i] + dis[i][v]);
    }
    if (dis[u][v] == w) return;
    ans[u][v] = dis[u][v] = w; ++ ret;
    for (int i = 0; i < n; ++ i) {
        dis[u][i] = min(dis[u][i], dis[u][v] + dis[v][i]);
    }
    for (int i = 0; i < n; ++ i) {
        dis[i][v] = min(dis[i][v], dis[i][u] + dis[u][v]);
    }
}

struct FastIO {
    static const int S = 4096;
    inline int xchar() {
        static char buf[S];
        static int len = 0, pos = 0;
        if (pos == len)
            pos = 0, len = fread(buf, 1, S, stdin);
        if (pos == len) return -1;
        return buf[pos ++];
    }
    inline int xuint() {
        int c = xchar(), x = 0;
        while (c <= 32) c = xchar();
        for (;'0' <= c && c <= '9'; c = xchar()) x = x * 10 + c - '0';
        return x;
    }
    inline int xint() {
        int s = 1, c = xchar(), x = 0;
        while (c <= 32) c = xchar();
        if (c == '-') s = -1, c = xchar();
        for (; '0' <= c && c <= '9'; c = xchar()) x = x * 10 + c - '0';
        return x * s;
    }
    inline void xstring(char *s) { 
        int c = xchar();
        while (c <= 32) c = xchar();
        for(; c > 32; c = xchar()) *s++ = c;
        *s = 0;
    }
    static int wpos;
    static char wbuf[S];
    inline void wchar(int x) {
        if (wpos == S) fwrite(wbuf, 1, S, stdout), wpos = 0;
        wbuf[wpos ++] = x;
    }
    inline void flush() {
        if (wpos) fwrite(wbuf, 1, wpos, stdout), wpos = 0;
    }
    inline void wint(int x) {
        if (x < 0) wchar('-'), x = -x;

        char s[24];
        int n = 0;
        while (x || !n) s[n ++] = '0' + x % 10, x /= 10;
        while (n--) wchar(s[n]);
    }
    inline void wstring(const char *s) {
        while (*s) wchar(*s++);
    }
} gay;

int FastIO::wpos = 0;
char FastIO::wbuf[FastIO::S];

int main() {
    //scanf("%d", &n); m = 0;
    n = gay.xint();
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < n; ++ j) {
            int x = gay.xint();// scanf("%d", &x);
            if (x > 0) edge[m ++] = MP(x, PII(i, j));
            dis[i][j] = inf; ans[i][j] = -1;
        }
        dis[i][i] = 0;
    }
    sort(edge, edge + m);
    for (int i = 0; i < m; ++ i) {
        int u = edge[i].second.first;
        int v = edge[i].second.second;
        int w = edge[i].first;
        add(u, v, w);
    }
    gay.wint(ret); gay.wchar('\n');
    //printf("%d\n", ret);
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < n; ++ j) {
            if (ans[i][j] > 0) {
                gay.wint(i + 1); gay.wchar(' ');
                gay.wint(j + 1); gay.wchar(' ');
                gay.wint(ans[i][j]); gay.wchar('\n');
                //printf("%d %d %d\n", i + 1, j + 1, ans[i][j]);
            }
        }
    }
    gay.flush();
    return 0;
}
