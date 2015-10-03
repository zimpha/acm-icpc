#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 1000 + 10;
int a[MAXN][MAXN];

// 1,2,4,8,12,16,20,24,28,32,36,_,44,48,52,_,60,64,68,72,76,80,84,_,92,_,100
string S[] = {
"",
"++++",
"",
"++-+--+--+++",
"",
"+++--+-++-+----+----",
"",
"++++---+-+--+-+--++--+------",
"",
"++++-+---++-+--+-++---++---+++-++-++",
"",
"++-+--++-+-++++----++++-+++--+++-+---+--+---",
"",
"++-+---+++-+-+---++++++---++-+--++--+-++----+--+----",
"",
"++++++--++-----+-++--++++--++-+----+-++-+----+-+---+--+---+-",
"",
"++--++-+-+-+--++-++--+--------+--++++----+--+----++++---+-+--+-+---+",
"",
"+-+-----++--+++++-+++-+++++----+++++-++-+----++--++----+-+--+-+-++--++-+-+--",
"",
"++--+++++++-------++-+++--++++-++-++++--+++--++-+-+-++-+-+-++--+---+++-+-++-+-+++---",
"",
"+++-+-------+++++++-+--++----+--+----+--+----+++-+--++---++---++--+-++--++-+-+-++++-+-+-++--",
"",
"++-----+-+---+++-+-+++++-++-++++-+-++--++-+-++++-++---+--++++----++++--+---+--+-+++--+----+--+++-+--"
};

char rev(char c) {
  if (c == '+') c = '-';
  else c = '+';
  return c;
}

int trans(char c) {
  if (c == '+') return 1;
  else return -1;
}

char A[MAXN][MAXN], B[MAXN][MAXN], C[MAXN][MAXN], D[MAXN][MAXN];

void getA(int m) {
  for (int i = 0; i < m; ++ i) A[0][i] = S[m][i];
  for (int i = 1; i < m; ++ i) {
    for (int j = 1; j < m; ++ j) A[i][j] = A[i - 1][j - 1];
    A[i][0] = A[i - 1][m - 1];
  }
}

void getB(int m) {
  for (int i = 0; i < m; ++ i) B[0][i] = S[m][i + m];
  for (int i = 1; i < m; ++ i) {
    for (int j = 0; j < m; ++ j) B[i][j] = B[i - 1][(j + 1) % m];
  }
}

void getC(int m) {
  for (int i = 0; i < m; ++ i) C[0][i] = S[m][i + m * 2];
  for (int i = 1; i < m; ++ i) {
    for (int j = 0; j < m; ++ j) C[i][j] = C[i - 1][(j + 1) % m];
  }
}

void getD(int m) {
  for (int i = 0; i < m; ++ i) D[0][i] = S[m][i + m * 3];
  for (int i = 1; i < m; ++ i) {
    for (int j = 0; j < m; ++ j) D[i][j] = D[i - 1][(j + 1) % m];
  }
}

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    int n; scanf("%d", &n);
    if (__builtin_popcount(n) == 1) {
      a[0][0] = 1;
      for (int l = 1; l <= n; l *= 2) {
        for (int i = 0; i < l; ++ i) {
          for (int j = 0; j < l; ++ j) {
            a[i + l][j + l] = -a[i][j];
            a[i + l][j] = a[i][j + l] = a[i][j];
          }
        }
      }
      puts("YES");
      for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < n; ++ j) {
          printf("%d ", a[i][j]);
        }
      }
      puts("");
    }
    else if (n % 4 != 0) puts("NO");
    else {
      puts("YES");
      int m = n;
      while (m % 2 == 0) m /= 2;
      getA(m); getB(m), getC(m), getD(m);
      for (int i = 0; i < m; ++ i) {
        for (int j = 0; j < m; ++ j) {
          a[i][j] = trans(A[i][j]);
          a[i][j + m] = trans(B[i][j]);
          a[i][j + m * 2] = trans(C[i][j]);
          a[i][j + m * 3] = trans(D[i][j]);

          a[i + m][j] = -trans(B[i][j]);
          a[i + m][j + m] = trans(A[i][j]);
          a[i + m][j + m * 2] = trans(D[i][j]);
          a[i + m][j + m * 3] = -trans(C[i][j]);

          a[i + m * 2][j] = -trans(C[i][j]);
          a[i + m * 2][j + m] = -trans(D[i][j]);
          a[i + m * 2][j + m * 2] = trans(A[i][j]);
          a[i + m * 2][j + m * 3] = trans(B[i][j]);

          a[i + m * 3][j] = -trans(D[i][j]);
          a[i + m * 3][j + m] = trans(C[i][j]);
          a[i + m * 3][j + m * 2] = -trans(B[i][j]);
          a[i + m * 3][j + m * 3] = trans(A[i][j]);
        }
      }
      m *= 4;
      for (; m < n; m *= 2) {
        for (int i = 0; i < m; ++ i) {
          for (int j = 0; j < m; ++ j) {
            a[i + m][j + m] = -a[i][j];
            a[i + m][j] = a[i][j + m] = a[i][j];
          }
        }
      }
      for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < n; ++ j) {
          printf("%d ", a[i][j]);
        }
      }
      puts("");
    }
  }
  return 0;
}