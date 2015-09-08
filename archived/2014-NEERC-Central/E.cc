#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

char mp[5][5];

bool check() {
  for (int i = 0; i < 2; ++ i) {
    for (int j = 0; j < 2; ++ j) {
      if (mp[i][j] != 'R') return 0;
      if (mp[i][j + 3] != 'G') return 0;
      if (mp[i + 3][j] != 'B') return 0;
      if (mp[i + 3][j + 3] != 'Y') return 0;
    }
  }
  return 1;
}

bool check2() {
  if (mp[0][0] != 'R' || mp[0][1] != 'R' || mp[1][0] != 'R') return 0;
  if (mp[0][3] != 'G' || mp[0][4] != 'G' || mp[1][4] != 'G') return 0;
  if (mp[3][0] != 'B' || mp[4][0] != 'B' || mp[4][1] != 'B') return 0;
  if (mp[3][4] != 'Y' || mp[4][3] != 'Y' || mp[4][4] != 'Y') return 0;
  return 1;
}

void ex(int a, int b) {
  printf("%d %d\n", a, b);
  -- a; -- b;
  swap(mp[a / 5][a % 5], mp[b / 5][b % 5]);
}

void moveR() {
  if (mp[0][0] == 'R' && mp[0][1] == 'R' &&
      mp[1][0] == 'R' && mp[1][1] == 'R') return;
  while (mp[1][1] == 'R') {
    ex(7, 12); ex(6, 7); ex(1, 6); ex(2, 1);
    ex(7, 8); ex(12, 7); ex(7, 2); ex(8, 7);
  }
}

void moveG() {
  if (mp[0][3] == 'G' && mp[0][4] == 'G' &&
      mp[1][3] == 'G' && mp[1][4] == 'G') return;
  while (mp[1][3] == 'G') {
    ex(9, 14); ex(4, 9); ex(5, 4); ex(10, 5);
    ex(9, 8); ex(14, 9); ex(9, 10); ex(8, 9);
  }
}

void moveB() {
  if (mp[3][0] == 'B' && mp[3][1] == 'B' &&
      mp[4][0] == 'B' && mp[4][1] == 'B') return;
  while (mp[3][1] == 'B') {
    ex(17, 12); ex(22, 17); ex(21, 22); ex(16, 21);
    ex(17, 18); ex(12, 17); ex(17, 16); ex(18, 17);
  }
}

void moveY() {
  if (mp[3][3] == 'Y' && mp[3][4] == 'Y' &&
      mp[4][3] == 'Y' && mp[4][4] == 'Y') return;
  while (mp[3][3] == 'Y') {
    ex(19, 14); ex(24, 19); ex(25, 24); ex(20, 25);
    ex(19, 18); ex(14, 19); ex(19, 20); ex(18, 19);
  }
}

void turnR() {
  ex(7, 8); ex(9, 14); ex(19, 18); ex(17, 12);
  ex(8, 9); ex(14, 19); ex(18, 17); ex(12, 7);
}

void turnL() {
  ex(7, 12); ex(9, 8); ex(19, 14); ex(17, 18);
  ex(12, 17); ex(8, 7); ex(14, 9); ex(18, 19);
}

void changeU() {
  ex(9, 14); ex(4, 9); ex(9, 8);
  ex(14, 9); ex(9, 4); ex(8, 9);
}

void changeD() {
  ex(19, 14); ex(24, 19); ex(19, 18);
  ex(14, 19); ex(19, 24); ex(18, 19);
}

int main() {
  for (int i = 0; i < 5; ++ i) scanf("%s", mp[i]);
  while (!check2()) {
    moveR();
    moveG();
    moveB();
    moveY();
    turnR();
  }
  while (mp[1][1] != 'R') turnR();
  if (mp[1][3] == 'Y' && mp[3][3] == 'B' && mp[3][1] == 'G') {
    turnR(); changeU(); turnR(); changeU();
  }
  if (mp[1][3] == 'G' && mp[3][3] == 'B' && mp[3][1] == 'Y') {
    changeD(); turnL(); changeD();
  }
  if (mp[1][3] == 'Y' && mp[3][3] == 'G' && mp[3][1] == 'B') {
    changeU(); turnL(); changeU(); 
  }
  if (mp[1][3] == 'B' && mp[3][3] == 'G' && mp[3][1] == 'Y') {
    changeU(); turnL(); changeU();
    while (mp[1][1] != 'R') turnR();
    changeD(); turnL(); changeD();
  }
  if (mp[1][3] == 'B' && mp[3][3] == 'Y' && mp[3][1] == 'G') {
    turnR(); changeD(); turnL(); changeD();
    turnR(); changeU(); turnR(); changeU();
  }
  while (mp[1][1] != 'R') turnR();
  assert(check());
  return 0;
}