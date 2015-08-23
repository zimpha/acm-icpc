#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 100000 + 10;
int cnt[MAXN];
char b[MAXN];
int n;
LL sw, sb;

int main() {
    int T; scanf("%d", &T);
    while (T --) {
        scanf("%d", &n); sw = sb = 0;
        for (int i = 0; i < n; ++ i) {
            char buf[10];
            scanf("%d%s", cnt + i, buf);
            b[i] = buf[0];
            if (b[i] == 'W') sw += cnt[i];
            else sb += cnt[i];
        }
        if (sw == 0) printf("%lld\n", sb);
        else if (sb == 0) printf("%lld\n", sw);
        else {
            int ret = 0;
            LL cw = 0, cb = 0;
            for (int i = 0; i < n; ) {
                if (b[i] == 'W') {
                    if (cb == 0) cw += cnt[i], cnt[i] = 0;
                    else {
                        if (cb * sw % sb == 0) {
                            LL ok = cb * sw / sb;
                            if (ok <= cw + cnt[i] && ok >= cw) {
                                cnt[i] -= ok - cw;
                                cw = 0; cb = 0;
                                ++ ret;
                            }
                            else cw += cnt[i], cnt[i] = 0;
                        }
                        else cw += cnt[i], cnt[i] = 0;
                    }
                }
                else {
                    if (cw == 0) cb += cnt[i], cnt[i] = 0;
                    else {
                        if (cw * sb % sw == 0) {
                            LL ok = cw * sb / sw;
                            if (ok <= cb + cnt[i] && ok >= cb) {
                                cnt[i] -= ok - cb;
                                cw = 0; cb = 0;
                                ++ ret;
                            }
                            else cb += cnt[i], cnt[i] = 0;
                        }
                        else cb += cnt[i], cnt[i] = 0;
                    }
                }
                if (cnt[i] == 0) ++ i;
            }
            printf("%d\n", ret);
        }
    }
    return 0;
}
