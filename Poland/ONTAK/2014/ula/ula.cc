#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
vector<PII> ret;

int main() {
    int n; scanf("%d", &n);
    if (n == 0) {
        ret.push_back(PII(5, 2));
        ret.push_back(PII(5, 3));
    }
    if (n == 1) {
        ret.push_back(PII(1, 6));
        ret.push_back(PII(7, 10));
        ret.push_back(PII(7, 15));
        ret.push_back(PII(1, 2));
        ret.push_back(PII(1, 3));
    }
    if (n == 2) {
        ret.push_back(PII(5, 3));
        ret.push_back(PII(21, 10));
        ret.push_back(PII(1, 6));
        ret.push_back(PII(1, 3));
        ret.push_back(PII(1, 5));
        ret.push_back(PII(2, 49));
        ret.push_back(PII(1, 35));
        ret.push_back(PII(1, 7));
    }
    if (n == 3) {
        ret.push_back(PII(19, 7));
        ret.push_back(PII(11 * 7, 19 * 2));
        ret.push_back(PII(13 * 7, 3 * 19));
        ret.push_back(PII(1, 19));
        ret.push_back(PII(10, 11));
        ret.push_back(PII(15, 13));
    }
    if (n == 4) {
        for (int i = 6; i >= 1; -- i) ret.push_back(PII(pow(7, i), pow(30, i)));
        for (int i = 6; i >= 1; -- i) ret.push_back(PII(pow(7, i), pow( 6, i)));
        for (int i = 6; i >= 1; -- i) ret.push_back(PII(pow(7, i), pow(10, i)));
        for (int i = 6; i >= 1; -- i) ret.push_back(PII(pow(7, i), pow(15, i)));
        for (int i = 6; i >= 1; -- i) ret.push_back(PII(1, pow(2, i)));
        for (int i = 6; i >= 1; -- i) ret.push_back(PII(1, pow(3, i)));
        for (int i = 6; i >= 1; -- i) ret.push_back(PII(1, pow(5, i)));
        ret.push_back(PII(1, 11));
    }
    if (n == 5) {
        ret.push_back(PII(2 * 23 * 31, 17));
        ret.push_back(PII(29, 31));
        ret.push_back(PII(11 * 31, 2 * 5 * 29));
        ret.push_back(PII(5, 11 * 29));
        ret.push_back(PII(5, 11));
        ret.push_back(PII(3 * 5 * 5 * 17, 2 * 23));
        ret.push_back(PII(3 * 5 * 17, 2));
        ret.push_back(PII(1, 5));
        ret.push_back(PII(1, 23));
        ret.push_back(PII(1, 29));
    }
    printf("%d\n", (int)ret.size());
    for (int i = 0; i < (int)ret.size(); ++ i) {
        printf("%d %d\n", ret[i].first, ret[i].second);
    }
    return 0;
}
