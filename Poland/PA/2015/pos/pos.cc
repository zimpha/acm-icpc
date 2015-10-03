#include <bits/stdc++.h>
#include "poszukiwania.h"
#include "message.h"
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int P = 2e7, MAXN = 200;
const int S1 = 1000070587, M1 = 2000321069, inv1 = 1292605818;
const int S2 = 1000263083, M2 = 2100313087, inv2 = 1227883253;

LL pw1, pw2, hs1, hs2;
LL SignalHs1, SignalHs2;
LL SeqHs1[MAXN], SeqHs2[MAXN];
int nx[P + 10];
int Node, NodeID;
int S, M, tot;

int main() {
  S = SignalLength();
  M = SeqLength();
  tot = M / P + (M % P != 0);
  Node = NumberOfNodes();
  NodeID = MyNodeId();
  if (S < P) {
    int l = min(NodeID * P, M), r = min(l + P * 2, M);
    int lim = min(l + P, M);
    if (l >= r) {PutInt(0, 0); Send(0); return 0;}
    nx[0] = -1;
    for (int i = 1, j(-1); i < S; ++ i) {
      while (j >= 0 && SignalAt(j + 2) != SignalAt(i + 1)) j = nx[j];
      nx[i] = (SignalAt(j + 2) == SignalAt(i + 1)) ? ++ j : j;
    }
    int cnt(0);
    for (int i = l, j(-1); i < r; ++ i) {
      while (j >= 0 && SignalAt(j + 2) != SeqAt(i + 1)) j = nx[j];
      if (SignalAt(j + 2) == SeqAt(i + 1)) j ++;
      if (j + 1 == S) {
        if (i - S + 1 < lim) ++ cnt;
        else break;
        j = nx[j];
      }
    }
    PutInt(0, cnt); Send(0);

    if (NodeID == 0) {
      int ret(0);
      for (int i = 0; i < Node; ++ i) {
        Receive(i);
        ret += GetInt(i);
      }
      printf("%d\n", ret);
    }
  }
  else {
    {// Get Hash of Signal
      int need = S / P + (S % P != 0);
      if (NodeID < need) {
        int l = NodeID * P, r = min(l + P, S);
        pw1 = pw2 = 1; hs1 = hs2 = 0;
        for (int i = l; i < r; ++ i) {
          int v = SignalAt(i + 1);
          pw1 = pw1 * S1 % M1;
          pw2 = pw2 * S2 % M2;
          hs1 = (hs1 * S1 + v + 1) % M1;
          hs2 = (hs2 * S2 + v + 1) % M2;
        }
        PutLL(0, hs1); PutLL(0, pw1);
        PutLL(0, hs2); PutLL(0, pw2);
        Send(0);
      }
    }
    { // merge Hash result of Signal, send to nodes
      if (NodeID == 0) {
        int need = S / P + (S % P != 0);
        SignalHs1 = SignalHs2 = 0;
        for (int i = 0; i < need; ++ i) {
          LL h, p;
          Receive(i);
          h = GetLL(i), p = GetLL(i);
          SignalHs1 = (SignalHs1 * p + h) % M1;
          h = GetLL(i), p = GetLL(i);
          SignalHs2 = (SignalHs2 * p + h) % M2;
        }
        for (int i = 0; i < Node; ++ i) {
          PutLL(i, SignalHs1); PutLL(i, pw1);
          PutLL(i, SignalHs2); PutLL(i, pw2);
          Send(i);
        }
      }
      Receive(0);
      SignalHs1 = GetLL(0); pw1 = GetLL(0);
      SignalHs2 = GetLL(0); pw2 = GetLL(0);
    }
    {// get Hash of Seq
      if (NodeID < tot) {
        int l = NodeID * P, r = min(l + P, M);
        LL h1(0), h2(0);
        for (int i = l; i < r; ++ i) {
          int v = SeqAt(i + 1);
          h1 = (h1 * S1 + v + 1) % M1;
          h2 = (h2 * S2 + v + 1) % M2;
        }
        for (int i = 0; i < Node; ++ i) {
          PutLL(i, h1);
          PutLL(i, h2);
          Send(i);
        }
      }
      for (int i = 0; i < tot; ++ i) {
        Receive(i);
        SeqHs1[i] = GetLL(i);
        SeqHs2[i] = GetLL(i);
      }
    }
    {// find occurence
      LL Bs1(0), Bs2(0);
      int t = S / P, l = NodeID * P, r = l + P;
      if (l + S > M) {
        PutInt(0, 0);
        Send(0);
        return 0;
      }
      LL p1(1), p2(1);
      for (int i = 0; i < t; ++ i) {
        Bs1 = (Bs1 * pw1 + SeqHs1[NodeID + i]) % M1;
        Bs2 = (Bs2 * pw2 + SeqHs2[NodeID + i]) % M2;
        p1 = p1 * pw1 % M1;
        p2 = p2 * pw2 % M2;
      }
      pw1 = p1, pw2 = p2;
      int ed(l + t * P);
      for (int i = 0; i < S % P; ++ i) {
        int v = SeqAt(ed + 1); ed ++;
        pw1 = pw1 * S1 % M1;
        pw2 = pw2 * S2 % M2;
        Bs1 = (Bs1 * S1 + v + 1) % M1;
        Bs2 = (Bs2 * S2 + v + 1) % M2;
      }
      pw1 = pw1 * inv1 % M1;
      pw2 = pw2 * inv2 % M2;
      int cnt(0);
      for (int i = l; i < r; ++ i) {
        if (Bs1 == SignalHs1 && Bs2 == SignalHs2) ++ cnt;
        if (ed == M) break;
        int v = SeqAt(i + 1), u = SeqAt(ed + 1); ed ++;
        Bs1 = (Bs1 - pw1 * (v + 1) % M1) % M1; if (Bs1 < 0) Bs1 += M1;
        Bs2 = (Bs2 - pw2 * (v + 1) % M2) % M2; if (Bs2 < 0) Bs2 += M2;
        Bs1 = (Bs1 * S1 + u + 1) % M1;
        Bs2 = (Bs2 * S2 + u + 1) % M2;
      }
      PutInt(0, cnt);
      Send(0);
    }
    {// merge answer
      if (NodeID == 0) {
        int ret(0);
        for (int i = 0; i < Node; ++ i) {
          Receive(i);
          ret += GetInt(i);
        }
        printf("%d\n", ret);
      }
    }
  }
  return 0;
}