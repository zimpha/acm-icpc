#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1000000 + 10, P = 1e9 + 9;

char A[MAXN], B[MAXN], C[MAXN];
LL ma[MAXN], mb[MAXN], mc[MAXN];
LL AB[MAXN], BC[MAXN];
int la, lb, lc, n;

void calc_mark(char A[], int l, LL ms[]) {
    ms[l] = 1;
    for (int i = l - 1; i >= 0; -- i) {
        ms[i] = ms[i + 1];
        if (A[i] == '?') ms[i] = ms[i + 1] * 26 % P;
    }
}

LL CE(char a, char b, int l = 26) { // a == b < l
    //if (l < 'a') return 0;
    if (a != '?' && b != '?') return a == b && a - 'a' < l;
    if (a == '?') swap(a, b);
    if (a == '?') return l;
    else return a - 'a' < l;
}

LL CL(char a, char b, int l = 26) {// a < b < l
    if (a == '?') {
        if (b == '?') return l * (l - 1) / 2;
        else if (b - 'a' >= l) return 0;
        else return b - 'a';
    }
    else {
        if (b == '?') return max(0, l - (a - 'a') - 1);
        else return a < b && b - 'a' < l;
    }
}

bool same(char a, char b, char c = '?') {
    if (a == '?') swap(a, b);
    if (a == '?') swap(a, c);
    if (a == '?') return true;
    return (a == b || b == '?') && (a == c || c == '?');
}

LL C1(char a, char b, char c) { // a < b < c
    if (c != '?') return CL(a, b, c - 'a');
    int r = 0;
    for (int i = 2; i < 26; ++ i) r += CL(a, b, i);
    return r;
}

LL C2(char a, char b, char c) {// a = b < c
    if (!same(a, b)) return 0;
    if (a == '?') swap(a, b);
    return CL(a, c);
}

LL C3(char a, char b, char c) {// a < b = c
    if (!same(b, c)) return 0;
    if (b == '?') swap(b, c);
    return CL(a, b);
}

int main() {
    int T; scanf("%d", &T);
    while (T --) {
        scanf("%s%s%s", A, B, C);
        la = strlen(A), lb = strlen(B), lc = strlen(C);
        A[la] = B[lb] = C[lc] = 'a' - 1;
        calc_mark(A, la + 1, ma);
        calc_mark(B, lb + 1, mb);
        calc_mark(C, lc + 1, mc);
        n = min(la, lb); AB[n + 1] = 0;
        for (int i = n; i >= 0; -- i) {
            AB[i] = CE(A[i], B[i]) * AB[i + 1] % P;
            AB[i] += CL(A[i], B[i]) * ma[i + 1] % P * mb[i + 1] % P;
            AB[i] %= P;
        }
        n = min(lb, lc); BC[n + 1] = 0;
        for (int i = n; i >= 0; -- i) {
            BC[i] = CE(B[i], C[i]) * BC[i + 1] % P;
            BC[i] += CL(B[i], C[i]) * mb[i + 1] % P * mc[i + 1] % P;
            BC[i] %= P;
        }
        LL ret = 0, mul = 1;
        n = min(la, min(lb, lc));
        for (int i = 0; i <= n; ++ i) {
            // a < b < c
            ret += mul * C1(A[i], B[i], C[i]) % P * ma[i + 1] % P * mb[i + 1] % P * mc[i + 1] % P;
            // a = b < c
            ret += mul * C2(A[i], B[i], C[i]) % P * AB[i + 1] % P * mc[i + 1] % P;
            // a < b = c
            ret += mul * C3(A[i], B[i], C[i]) % P * ma[i + 1] % P * BC[i + 1] % P;
            ret %= P;
            if (same(A[i], B[i], C[i])) {
                if (A[i] == '?' && B[i] == '?' && C[i] == '?') mul = mul * 26 % P;
            }
            else break;
        }
        printf("%lld\n", ret);
    }
    return 0;
}
