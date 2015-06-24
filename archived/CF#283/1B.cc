#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int MAXN = 100000 + 10;
int a[MAXN], s1[MAXN], s2[MAXN], n;

int find(int st, int num, int s[]) {
    int left = st, right = n;
    while (left < right) {
        int mid = (left + right - 1) >> 1;
        if (s[mid] - s[st - 1] >= num) right = mid;
        else left = mid + 1;
    }
    if (s[left] - s[st - 1] != num) return -1;
    else return left;
}

bool check(int t, int &s) {
    int c1 = 0, c2 = 0, last = -1;
    for (int i = 1; i <= n; ++ i) {
        int p1 = find(i, t, s1);
        int p2 = find(i, t, s2);
        if (p1 == -1 && p2 == -1) return false;
        if (p1 == -1) c2 ++, i = p2, last = 2;
        else if (p2 == -1) c1 ++, i = p1, last = 1;
        else if (p1 < p2) c1 ++, i = p1, last = 1;
        else c2 ++, i = p2, last = 2;
    }
    if (last == 2 && c2 <= c1) return false;
    if (last == 1 && c1 <= c2) return false;
    s = max(c1, c2);
    return true;
}

int main() {
    scanf("%d", &n); s1[0] = s2[0] = 0;
    for (int i = 1; i <= n; ++ i) {
        s1[i] = s1[i - 1];
        s2[i] = s2[i - 1];
        scanf("%d", a + i);
        s1[i] += a[i] == 1;
        s2[i] += a[i] == 2;
    }
    vector<PII> ret;
    for (int t = 1, s; t <= n; ++ t) {
        if (check(t, s)) {
            ret.push_back(PII(s, t));
        }
    }
    sort(ret.begin(), ret.end());
    printf("%d\n", (int)ret.size());
    for (auto &x : ret) {
        printf("%d %d\n", x.first, x.second);
    }
    return 0;
}