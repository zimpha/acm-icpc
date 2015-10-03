// Pamietaj, ze prawdziwa biblioteka nie zalaczy assert.h ani stdio.h
// za Ciebie!

#include <assert.h>
#include <stdio.h>

static int initialized = 0;

static long long (*SignalLength_ptr)();
static long long (*SignalAt_ptr)(long long);
static long long (*SeqLength_ptr)();
static long long (*SeqAt_ptr)(long long);

long long SignalLengthA() {
  return 5LL;
}

long long SignalAtA(long long pos) {
  switch ((int)pos) {
    case 1: return 1LL;
    case 2: return 2LL;
    case 3: return 3LL;
    case 4: return 2LL;
    case 5: return 1LL;
    default: assert(0);
  }
}

long long SeqLengthA() {
  return 11LL;
}

long long SeqAtA(long long pos) {
  switch ((int)pos) {
    case 1: return 2LL;
    case 2: return 1LL;
    case 3: return 2LL;
    case 4: return 3LL;
    case 5: return 2LL;
    case 6: return 1LL;
    case 7: return 2LL;
    case 8: return 3LL;
    case 9: return 2LL;
    case 10: return 1LL;
    case 11: return 2LL;
    default: assert(0);
  }
}

long long SignalLengthB() {
  return 10000000LL;
}

long long SignalAtB(long long pos) {
  return (pos-1) % 7;
}

long long SeqLengthB() {
  return 20000000LL;
}

long long SeqAtB(long long pos) {
  return (pos-1) % 7;
}

long long SignalLengthC() {
  return 20000000LL;
}

long long SignalAtC(long long pos) {
  return (pos-1) + 10000000;
}

long long SeqLengthC() {
  return 200000000LL;
}

long long SeqAtC(long long pos) {
  return (pos-1) % 40000000;
}

static void Init() {
  int TID = 0;
  scanf("%d", &TID);
  assert(TID >= 1 && TID <= 3);
  if (TID == 1) {
    SeqAt_ptr = SeqAtA;
    SeqLength_ptr = SeqLengthA;
    SignalAt_ptr = SignalAtA;
    SignalLength_ptr = SignalLengthA;
  } else if (TID == 2) {
    SeqAt_ptr = SeqAtB;
    SeqLength_ptr = SeqLengthB;
    SignalAt_ptr = SignalAtB;
    SignalLength_ptr = SignalLengthB;
  } else if(TID == 3) {
    SeqAt_ptr = SeqAtC;
    SeqLength_ptr = SeqLengthC;
    SignalAt_ptr = SignalAtC;
    SignalLength_ptr = SignalLengthC;
    }
  initialized = 1;
}

long long SeqLength() {
  if (!initialized) {
    Init();
  }
  return (*SeqLength_ptr)();
}

long long SignalLength() {
  if (!initialized) {
    Init();
  }
  return (*SignalLength_ptr)();
}

long long SeqAt(long long pos) {
  if (!initialized) {
    Init();
  }
  return (*SeqAt_ptr)(pos);
}

long long SignalAt(long long pos) {
  if (!initialized) {
    Init();
  }
  return (*SignalAt_ptr)(pos);
}
