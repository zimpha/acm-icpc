#include <bits/stdc++.h>
#include "kanapka.h"
#include "message.h"
using namespace std;
typedef long long ll;

pair<ll, ll> divide(ll n) {
  auto f = [](ll n, int i, int k) { return n * i / k; };
  return make_pair(f(n, MyNodeId(), NumberOfNodes()),
                   f(n, MyNodeId() + 1, NumberOfNodes()));
}

int main() {
  // Local computation
  ll nl, nr;
  tie(nl, nr) = divide(GetN());

  // Total and left max
  {
    ll s = 0, sl = 0, sr = 0, sans = 0;
    for (ll i = nl; i < nr; ++i) {
      ll x = -GetTaste(i);;
      s += x;
      sl = max(sl, s);
      sr = max(sr + x, 0LL);
      sans = max(sans, sr);
    }

    // Send it, and compute!
    PutLL(0, s);
    PutLL(0, sl);
    PutLL(0, sr);
    PutLL(0, sans);
    // printf("[%lld, %lld): %lld %lld %lld %lld\n", nl, nr, s, sl, sr, sans);
    Send(0);
  }

  // DP
  if (MyNodeId() == 0) {
    ll ans = 0, dp = 0, total = 0;
    for (int i = 0; i < NumberOfNodes(); ++i) {
      Receive(i);
      ll ts = GetLL(i);
      ll tsl = GetLL(i);
      ll tsr = GetLL(i);
      ll tsans = GetLL(i);
      ans = max(ans, max(tsans, dp + tsl));
      dp = max(dp + ts, tsr);
      total += ts;
    }
    printf("%lld\n", -(total - ans));
  }
  return 0;
}