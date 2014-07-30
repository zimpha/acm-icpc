#include <set>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1000000 + 10;

char S[MAXN];
int vis[MAXN];
int N, now;

bool solve(int len) {
    ++ now;
    int ret = 0, bits = 3 * len - 3;
    for (int i = 0; i < len; ++ i) {
        ret = (ret << 3) | (S[i] - 'A');
    }
    vis[ret] = now;
    for (int i = len; i < N; ++ i) {
        ret &= (1 << bits) - 1;
        ret = (ret << 3) | (S[i] - 'A');
        vis[ret] = now;
    }
    for (ret = 0; vis[ret] == now; ++ ret);
    if (ret == (1 << (3 * len))) return false;
    string ss = "";
    for (int i = 0; i < len; ++ i) {
        ss = char((ret & 7) + 'A') + ss;
        ret >>= 3;
    }
    puts(ss.c_str());
    return true;
}

int main() {
    int T; scanf("%d", &T);
    while (T --) {
        scanf("%s", S);
        N = strlen(S);
        for (int len = 1; ; ++ len) {
            if (solve(len)) break;
        }
    }
    return 0;
}
