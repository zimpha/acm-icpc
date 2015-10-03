#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef double flt;
const int MAXN = 777777 + 10;
int x[MAXN], y[MAXN], z[MAXN];

flt sqr(flt x) {return x * x;}
flt qua(flt x) {return sqr(sqr(x));}

namespace FFT {
  static const int W = 1 << 22;
  static const flt PI = acos(-1.0);
  struct Complex {
    flt x,y;
    Complex(flt _x=0,flt _y=0):x(_x),y(_y) {}
    Complex operator +(const Complex &t) const {return Complex(x+t.x,y+t.y);}
    Complex& operator +=(const Complex &t) {x+=t.x,y+=t.y;return *this;}
    Complex operator -(const Complex &t) const {return Complex(x-t.x,y-t.y);}
    Complex& operator -=(const Complex &t) {x-=t.x,y-=t.y;return *this;}
    Complex operator *(const Complex &t) const {return Complex(x*t.x-y*t.y,x*t.y+y*t.x);}
    Complex operator /(const flt &t) const {return Complex(x/t,y/t);}
    Complex& operator /=(const flt &t) {x/=t,y/=t;return *this;}
    flt real() {return x;}
    flt imag() {return y;}
  };
  void fft(Complex a[], int n, int rev=1) {// rev=-1, reverse
      for (int i=1,j=0,k;i<n;++i) {
          for (k=n>>1;k>(j^=k);k>>=1);
          if (i<j) swap(a[i],a[j]);
      }
      for (int s=1,ss=2;s<n;s<<=1,ss<<=1) {
          Complex wn(cos(2*PI*rev/ss), sin(2*PI*rev/ss)), w;
          for (int i=0,j;i<n;i+=ss) {
              for (j=i,w=1;j<i+s;++j,w=w*wn) {
                  Complex t = w*a[j+s];
                  a[j+s]=a[j]-t; a[j]=a[j]+t;
              }
          }
      }
      if (rev==-1) for (int i=0;i<n;++i) a[i]/=n;
  }
}

FFT::Complex A[FFT::W], B[FFT::W];
flt cost[80][80][80];

int main() {
  for (int i = 0; i < 80; ++ i) {
    for (int j = 0; j < 80; ++ j) {
      for (int k = 0; k < 80; ++ k) {
        cost[i][j][k] = sqrt(qua(i) + qua(j) + qua(k));
      }
    }
  }
  int n, q; scanf("%d%d", &n, &q);
  for (int i = 0; i < n; ++ i) {
    scanf("%d%d%d", x + i, y + i, z + i);
    x[i] --; y[i] --; z[i] --;
    int a = x[i] * 153 * 153 + y[i] * 153 + z[i];
    int b = (76 - x[i]) * 153 * 153 + (76 - y[i]) * 153 + (76 - z[i]);
    A[a].x += 1; B[b].x += 1;
  }
  FFT::fft(A, FFT::W);
  FFT::fft(B, FFT::W);
  for (int i = 0; i < FFT::W; ++ i) {
    A[i] = A[i] * B[i];
  }
  FFT::fft(A, FFT::W, -1);
  for (int _ = 0; _ < q; ++ _ ) {
    int a, b, c, d; scanf("%d%d%d%d", &a, &b, &c, &d);
    flt ret(0);
    for (int i = 0; i < FFT::W; ++ i) {
      int cnt = int(A[i].real() + 0.5);
      if (cnt == 0) continue;
      int x = i / (153 * 153) - 76, y = i / 153 % 153 - 76, z = i % 153 - 76;
      if (x == 0 && y == 0 && z == 0) continue;
      ret += fabs(a * x + b * y + c * z + d) * cnt / cost[abs(x)][abs(y)][abs(z)];
    }
    ret /= n; ret /= (n - 1);
    printf("%.10f\n", ret);
  }
  return 0;
}