#include <map>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 20000 + 10;

map<int, int> cnt;
char s[MAXN];
int N;

int main() {
    int T; scanf("%d", &T);
    while (T --) {
        scanf("%s", s);
        N = strlen(s);
        long long ret = 0;
        // don't contain mark
        cnt.clear(); cnt[0] = 1;
        for (int i = 0, sum = 0; i < N; ++ i) {
            if (s[i] != '?') sum ^= (1 << (s[i] - 'a'));
            if (cnt.find(sum) == cnt.end()) cnt[sum] = 0;
            ret += cnt[sum];
            ++ cnt[sum];
        }
        // contain mark
        cnt.clear(); cnt[0] = 1;
        int pos = N, sum = 0;
        for (int i = 0; i < N; ++ i) {
            if (s[i] == '?') {
                pos = i;
                break;
            }
            sum ^= (1 << (s[i] - 'a'));
            if (cnt.find(sum) == cnt.end()) cnt[sum] = 0;
            ++ cnt[sum];
        }
        for (int i = pos; i < N; ++ i) {
            if (i == pos) {
                for (int j = 0; j < 26; ++ j) {
                    if (cnt.find(sum ^ (1 << j)) != cnt.end()) {
                        ret += cnt[sum ^ (1 << j)];
                    }
                }
                continue;
            }
            sum ^= (1 << (s[i] - 'a'));
            for (int j = 0; j < 26; ++ j) {
                if (cnt.find(sum ^ (1 << j)) != cnt.end()) {
                    ret += cnt[sum ^ (1 << j)];
                }
            }
        }
        cout << ret << endl;
    }
    return 0;
}
