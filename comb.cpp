#include <bits/stdc++.h>

#include "mint.cpp"
using namespace std;

struct BiCoef {
  vector<mint> fact, ifact;
  BiCoef(int n) : fact(n + 1), ifact(n + 1) {
    assert(n < mod);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i;
    ifact[n] = fact[n].inv();
    for (int i = n; i >= 1; --i) ifact[i - 1] = ifact[i] * i;
  }

  mint P(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * ifact[n - r];
  }

  mint C(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * ifact[r] * ifact[n - r];
  }

  mint H(int n, int r) {
    if (r < 0 || 0 > n) return 0;
    return C(n + r - 1, r);
  }
};