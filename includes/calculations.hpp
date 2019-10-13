#pragma once
#include <gmp.h>
#include <gmpxx.h>
#include <iostream>
using namespace std;

using ll = mpz_t;

class Calculate {
  void Eulers_P_Q(ll phi, ll p, ll q);
  void N_P_Q(ll n, ll p, ll q);
  void Q_P_N(ll q, ll p, ll n);
  void C_M_E_N(ll c, ll m, ll e, ll n);
};