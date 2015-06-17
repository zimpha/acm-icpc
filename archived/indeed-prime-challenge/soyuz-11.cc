#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; scanf("%d", &n);
  puts("  /\\");
  for (int i = 0; i < n; ++ i) puts("  ||");
  puts(" /||\\");
  puts("/:||:\\");
  for (int i = 1; i < n; ++ i) puts("|:||:|");
  puts("|/||\\|");
  puts("  **\n  **");
  return 0;
}
