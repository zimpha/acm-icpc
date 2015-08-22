#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const char *color[] = {
  "White", "Silver", "Gray", "Black", "Red", "Maroon", "Yellow", "Olive",
  "Lime", "Green", "Aqua", "Teal", "Blue", "Navy", "Fuchsia", "Purple"
};

const int rgb[][3] = {
  255, 255, 255,
  192, 192, 192,
  128, 128, 128,
  0, 0, 0,
  155, 0, 0,
  128, 0, 0,
  255, 255, 0,
  128, 128, 0,
  0, 255, 0,
  0, 128, 0,
  0, 255, 255,
  0, 128, 128,
  0, 0, 255,
  0, 0, 128,
  255, 0, 255,
  128, 0, 128
};

int sqr(int x) {return x * x;}

int main() {
  int r, g, b;
  while (cin >> r >> g >> b) {
    if (r == -1 && g == -1 && b == -1) break;
    int idx(-1), mx(1e9);
    for (int i = 0; i < 16; ++ i) {
      int tmp = sqr(rgb[i][0] - r) + sqr(rgb[i][1] - g) + sqr(rgb[i][2] - b);
      if (tmp < mx) mx = tmp, idx = i;
    }
    cout << color[idx] << endl;
  }
  return 0;
}

