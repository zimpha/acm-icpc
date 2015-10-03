// Pamietaj, ze prawdziwa biblioteka nie zalaczy assert.h ani stdio.h
// za Ciebie!

#ifndef SABOTAZ_H
#define SABOTAZ_H

#include <assert.h>
#include <stdio.h>
typedef long long LL;
static int (*GetN_ptr)();
static int (*GetM_ptr)();
static int (*GetA_ptr)(int);
static int (*GetB_ptr)(int);

#define LIB_MAXN (200 * 1000)
#define LIB_MAXM (100 * 1000 * 1000)


// SmallSample

int SmallSampleGetN() {
  return 4;
}
int SmallSampleGetM() {
  return 4;
}
int SmallSampleGetA(int i) {
  switch (i) {
    case 0: return 0;
    case 1: return 1;
    case 2: return 2;
    case 3: return 2;
    default: assert(0);
  }
}
int SmallSampleGetB(int i) {
  switch (i) {
    case 0: return 1;
    case 1: return 2;
    case 2: return 0;
    case 3: return 3;
    default: assert(0);
  }
}

// LargeSample

static int LIB_N = LIB_MAXN, LIB_K = LIB_MAXM / LIB_MAXN;

int LargeSampleGetN() {
  return LIB_N;
}
int LargeSampleGetM() {
  return LIB_N * LIB_K;
}
int LargeSampleGetA(int i) {
  assert(i >= 0 && i < LIB_N * LIB_K);
  return i % LIB_N;
}
int LargeSampleGetB(int i) {
  assert(i >= 0 && i < LIB_N * LIB_K);
  return (i + 1) % LIB_N;
}

static int lib_initialized = 0;

static void LibInit() {
  int TID;
  scanf("%d", &TID);
  assert(1 <= TID && TID <= 2);
  if (TID == 1) {
    GetN_ptr = SmallSampleGetN;
    GetM_ptr = SmallSampleGetM;
    GetA_ptr = SmallSampleGetA;
    GetB_ptr = SmallSampleGetB;
  } else if (TID == 2) {
    GetN_ptr = LargeSampleGetN;
    GetM_ptr = LargeSampleGetM;
    GetA_ptr = LargeSampleGetA;
    GetB_ptr = LargeSampleGetB;
  }
  lib_initialized = 1;
}

#ifdef __cplusplus
extern "C" {
#endif

long long NumberOfIsles() {
  if (!lib_initialized) {
    LibInit();
  }
  return (*GetN_ptr)();
}

long long NumberOfBridges() {
  if (!lib_initialized) {
    LibInit();
  }
  return (*GetM_ptr)();
}

long long BridgeEndA(long long i) {
  if (!lib_initialized) {
    LibInit();
  }
  return (*GetA_ptr)((int)i);
}

long long BridgeEndB(long long i) {
  if (!lib_initialized) {
    LibInit();
  }
  return (*GetB_ptr)((int)i);
}

#ifdef __cplusplus
}
#endif

#endif // SABOTAZ_H
