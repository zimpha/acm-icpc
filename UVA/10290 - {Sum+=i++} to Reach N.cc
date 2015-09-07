#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e7 + 10;
typedef long long ll;  

bool isPrime[maxn];
vector<int> prime, cnt;
ll n;

void getPrime() {
    memset(isPrime, 1, sizeof isPrime);
    for (int i = 2; i < maxn; ++ i) {
        if (isPrime[i]) {
            prime.push_back(i);
            for (int j = i + i; j < maxn; j += i) {
                isPrime[j] = 0;
            }
        }
    }
}

void getDigit() {
    while (n % 2 == 0) n /= 2;
    for (int i = 1; i < (int)prime.size() && n >= prime[i]; ++ i) {
        if (n % prime[i] == 0) {
            int t = 0;
            while (n % prime[i] == 0) {
                n /= prime[i];
                ++ t;
            }
            cnt.push_back(t);
        }
    }
    if (n != 1) cnt.push_back(1);
}

int main(){  
    getPrime();  
    while(~scanf("%lld", &n)) {
        cnt.clear();
        getDigit();
        ll ans = 1;
        for (int i = 0; i < (int)cnt.size(); ++ i) ans *= (cnt[i]+1);
        cout << ans << endl;
    }
    return 0;
}
