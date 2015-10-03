#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const double w[] = {-200, 2, -200, -100, -0.314312};
const int n = 15, inf = 1e9;
const int all = (1 << n) - 1;
int mp[n], h[n];
int line(0), brick(0);

void eliminate() {
  for (int i = 0; i < n; ++ i) {
    while (mp[i] == all) {
      ++ line;
      for (int j = i; j < n-1; ++ j) mp[j] = mp[j + 1];
    }
  }
}

int AH() {
  int r(0);
  for (int i = 0; i < n; ++ i) h[i] = 0;
  for (int i = 0; i < n; ++ i) {
    for (int j = 0; j < n; ++ j) {
      if (mp[i] >> j & 1) h[j] = i + 1;
    }
  }
  for (int i = 0; i < n; ++ i) r += h[i]==0;
  return r;
}

int CL() {
  int r(0);
  for (int i = 0; i < n; ++ i) r += mp[i] == all;
  return r;
}

int Holes() {
  int r(0);
  for (int j = 0; j < n; ++ j) {
    for (int i = 0; i < h[j]; ++ i) {
      if (!(mp[i] >> j & 1)) ++ r;
    }
  }
  return r;
}

int EL() {
  int r(0);
  for (int i = 0; i < n; ++ i) r += h[i] == 0;
  return 0;
}

double Bump() {
  double avg(0), r(0);
  for (int i = 0; i < n; ++ i) avg += h[i];
  avg /= n;
  for (int i = 0; i < n; ++ i) r += (avg - h[i]) * (avg - h[i]);
  return sqrt(r / n);
}

bool put(int r, int c, int x, int y, const int brick[]) {
  if (r + x >= n || c + y >= n) return 0;
  if (r) {
    int t(0);
    for (int j = c; j < c + y; ++ j) t += mp[r - 1] >> j & 1;
    if (t == 0) return 0;
  }
  for (int i = 0; i < x; ++ i) {
    if ((mp[i + r] >> c) & brick[i]) return 0;
  }
  for (int i = 0; i < x; ++ i) {
    mp[i + r] ^= brick[i] << c;
  }
  return 1;
}

void unput(int r, int c, int x, int y, const int brick[]) {
  for (int i = 0; i < x; ++ i) mp[i + r] ^= brick[i] << c;
}

void output(int rot, int r, int c) {
  printf("%c %d %d\n", char(rot + 'a'), 15 - r, c + 1);
  fflush(stdout);
}

const int tiles[7][4][4] = {
  {{15,0,0,0},{1,1,1,1},{0,0,0,0},{0,0,0,0}},
  {{7,1,0,0},{3,2,2,0},{1,1,3,0},{4,7,0,0}},
  {{7,4,0,0},{3,1,1,0},{1,7,0,0},{2,2,3,0}},
  {{3,3,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}},
  {{3,6,0,0},{2,3,1,0},{0,0,0,0},{0,0,0,0}},
  {{7,2,0,0},{1,3,1,0},{2,7,0,0},{2,3,2,0}},
  {{6,3,0,0},{1,3,2,0},{0,0,0,0},{0,0,0,0}}
};
const int dim[7][4][2] = {
  {{1,4},{4,1},{0,0},{0,0}},
  {{2,3},{3,2},{3,2},{2,3}},
  {{2,3},{3,2},{2,3},{3,2}},
  {{2,2},{0,0},{0,0},{0,0}},
  {{2,3},{3,2},{0,0},{0,0}},
  {{2,3},{3,2},{2,3},{3,2}},
  {{2,3},{3,2},{0,0},{0,0}}
};
const int nums[7] = {2,4,4,1,2,4,2};

bool solve1() {
  int fig; scanf("%d", &fig); -- fig;
  double best(-inf);
  int r(-1), c(-1), rot(-1);
  for (int tt = 0; tt < nums[fig]; ++ tt) {
    int x = dim[fig][tt][0], y = dim[fig][tt][1];
    for (int i = 0; i < n; ++ i) {
      for (int j = 0; j < n; ++ j) {
        if (put(i, j, x, y, tiles[fig][tt])) {
          double A = AH() * w[0];
          double B = CL() * w[1];
          double C = Holes() * w[2];
          double D = Bump() * w[3];
          double E = Bump() * w[4];
          if (A + B + C + D + E >= best) {
            best = A + B + C + D + E;
            r = i, c = j; rot = tt;
          }
          unput(i, j, x, y, tiles[fig][tt]);
        }
      }
    }
  }
  if (r == -1) return 0;
  int x = dim[fig][rot][0], y = dim[fig][rot][1];
  output(rot, r, c);
  put(r, c, x, y, tiles[fig][rot]);
  eliminate();
  return 1;
}

bool solve2() {
  int fig, rot; char buf[10];
  scanf("%d%s", &fig, buf);
  rot = buf[0] - 'a'; -- fig;
  int x = dim[fig][rot][0], y = dim[fig][rot][1];
  double best(-inf);
  int r(-1), c(-1);;
  for (int i = 0; i < n; ++ i) {
    for (int j = 0; j < n; ++ j) {
      if (put(i, j, x, y, tiles[fig][rot])) {
        double A = AH() * w[0];
        double B = CL() * w[1];
        double C = Holes() * w[2];
        double D = Bump() * w[3];
        double E = Bump() * w[4];
        if (A + B + C + D + E > best) {
          best = A + B + C + E;
          r = i, c = j;
        }
        unput(i, j, x, y, tiles[fig][rot]);
      }
    }
  }
  if (r == -1) return 0;
  output(rot, r, c);
  put(r, c, x, y, tiles[fig][rot]);
  eliminate();
  return 1;
}

int main() {
  char type[100];
  for (int i = 0; i < n; ++ i) mp[i] = 0;
  while (scanf("%s", type) == 1 && type[0] != 'G') {
    bool flag = 0;
    if (type[0] == '1') flag = solve1();
    else flag = solve2();
    if (!flag) break;
    brick ++;
  }
  output(0, -1, -1);
  //printf("score = %d, line = %d\n", brick + line * 500, line);
  return 0;
}