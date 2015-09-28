#ifndef KANAPKA_H
#define KANAPKA_H

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

static long long GetN_SmallSample() {
  return 7LL;
}

static long long GetTaste_SmallSample(long long i) {
  switch ((int)i) {
    case 0: return 10LL;
    case 1: return -2LL;
    case 2: return 5LL;
    case 3: return -4LL;
    case 4: return 3LL;
    case 5: return -5LL;
    case 6: return 1LL;
    default: assert(0);
  }
}

static const long long M = 100000000;

static long long GetN_LargeSample() {
  return 2 * M + 2;
}

static long long GetTaste_LargeSample(long long i) {
  assert(i >= 0 && i < 2 * M + 2);
  if (i <= M) {
    if (i % 2 == 0) {
      return i;
    } else {
      return -i;
    }
  } else {
    i = 2 * M + 1 - i;
    if (i % 2 == 0) {
      return -i;
    } else {
      return i;
    }
  }
}

static int initialized = 0;
static long long (*GetN_ptr)();
static long long (*GetTaste_ptr)(long long);

static void Init() {
  int TID = 0;
  scanf("%d", &TID);
  assert(TID >= 1 && TID <= 2);
  if (TID == 1) {
    GetN_ptr = GetN_SmallSample;
    GetTaste_ptr = GetTaste_SmallSample;
  } else if (TID == 2) {
    GetN_ptr = GetN_LargeSample;
    GetTaste_ptr = GetTaste_LargeSample;
  }
  initialized = 1;
}

#ifdef __cplusplus
extern "C" {
#endif

long long GetN() {
  if (!initialized) {
    Init();
  }
  return (*GetN_ptr)();
}

long long GetTaste(long long i) {
  if (!initialized) {
    Init();
  }
  return (*GetTaste_ptr)(i);
}

#ifdef __cplusplus
}
#endif

#endif // KANAPKA_H
