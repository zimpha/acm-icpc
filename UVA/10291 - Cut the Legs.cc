#include <bits/stdc++.h>
using namespace std;

int N, A[100];

bool check(int mx) {
    int d = (N & 1) ? N / 2 : (N - 1) / 2;
    vector<int> v;
    for (int i = 0; i < N; ++ i) {
        if (A[i] >= mx) v.push_back(i);
    }
    if (v.size() < 3) return false;
    v.push_back(v[0]);
    for (int i = 1, step; i < (int)v.size(); ++ i) {
        if (v[i] > v[i - 1]) step = v[i] - v[i - 1];
        else step = N + v[i] - v[i - 1];
        if (step > d) return false;
    }
    return true;
}

int main() {
    int cas = 0;
    while (scanf("%d", &N) == 1 && N) {
        for (int i = 0; i < N; ++ i) {
            scanf("%d", A + i);
        }
        if (cas ++) puts("");
        int mx = A[0], sum = A[0];
        for (int i = 1; i < N; ++ i) mx = min(mx, A[i]), sum += A[i];
        if (N <= 4) {
            printf("%d\n", sum - mx * N);
            continue;
        }
        int ret = 1e9;
        for (int i = 0; i < N; ++ i) {
            if (check(A[i])) {
                int tmp = 0;
                for (int j = 0; j < N; ++ j) tmp += max(0, A[j] - A[i]);
                ret = min(ret, tmp);
            }
        }
        printf("%d\n", ret);
    }
}
